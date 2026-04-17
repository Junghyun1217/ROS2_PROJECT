#!/usr/bin/env python3
import threading
import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer, GoalResponse, CancelResponse, ActionClient
from rclpy.action.server import ServerGoalHandle
from nav2_msgs.action import NavigateToPose
from geometry_msgs.msg import PoseStamped
from std_msgs.msg import Bool
from rclpy.executors import MultiThreadedExecutor
from rclpy.callback_groups import ReentrantCallbackGroup

class SShopyNode(Node):
    def __init__(self):
        super().__init__("sshopy_node")

        # ★ 핵심: 여러 콜백이 동시에 실행될 수 있도록 그룹 설정
        self.callback_group = ReentrantCallbackGroup()

        # Nav2 클라이언트 (목적지로 보낼 때 사용)
        self._nav2_client = ActionClient(
            self, NavigateToPose, 'navigate_to_pose', 
            callback_group=self.callback_group)

        # 적재 완료 구독
        self._load_complete_sub = self.create_subscription(
            Bool, '/load_complete', self._load_complete_callback, 10,
            callback_group=self.callback_group)

        # 도착 신호 발행
        self._arrived_pub = self.create_publisher(Bool, '/pinky/arrived', 10)

        # 위치 정보
        self._locations = {
            "warejet": {
                "x": 0.10835881471111715,
                "y": 0.21389932731805447,
                "z": 0.9998012815964794,
                "w": 0.019934826762158426
            },
            "frontjet": {
                "x": 1.047697012206532,
                "y": 0.4737226911736648,
                "z": -0.715750014555285,
                "w": 0.6983565827455981
            }
        }

        self._load_event = threading.Event()

        # 메인 서버로부터 명령을 받을 액션 서버
        self._move_action_server = ActionServer(
            self, NavigateToPose, "/sshopy/move",
            execute_callback=self.execute_move_callback,
            goal_callback=self.goal_callback,
            cancel_callback=self.cancel_callback,
            callback_group=self.callback_group # 그룹 지정 필수
        )

        self.get_logger().info("SShopy 노드 시작! (Multi-Threaded)")

    def goal_callback(self, goal_request) -> GoalResponse:
        self.get_logger().info("메인 서버로부터 이동 요청 수신")
        return GoalResponse.ACCEPT

    def cancel_callback(self, goal_handle) -> CancelResponse:
        self.get_logger().info("이동 취소 요청 수신")
        return CancelResponse.ACCEPT

    def _load_complete_callback(self, msg: Bool):
        if msg.data and not self._load_event.is_set():  # 중복 방지
            self.get_logger().info("적재 완료 신호 수신 (Event Set)")
            self._load_event.set()

    async def execute_move_callback(self, goal_handle: ServerGoalHandle):
        """액션 실행 메인 루프"""
        self.get_logger().info("시나리오 시작!")

        # 1단계 — 입고존(frontjet)으로 이동
        self.get_logger().info("1단계: 입고존으로 이동 중...")
        success = await self._navigate_to("frontjet")

        if not success:
            self.get_logger().error("입고존 이동 실패")
            goal_handle.abort()
            return NavigateToPose.Result()

        # 2단계 — 도착 신호 발행
        self.get_logger().info("입고존 도착! /pinky/arrived 신호 발송")
        arrived_msg = Bool()
        arrived_msg.data = True
        self._arrived_pub.publish(arrived_msg)

        # 3단계 — 적재 완료 신호 대기 (Event Wait)
        self.get_logger().info("3단계: /load_complete 신호 대기 중...")
        self._load_event.clear()
        # 주의: Event.wait()는 블로킹 함수이므로 별도 스레드에서 돌려야 안전함
        self._load_event.wait() 

        # 4단계 — 창고(warejet)로 이동
        self.get_logger().info("4단계: 창고로 귀환 중...")
        success = await self._navigate_to("warejet")

        if not success:
            self.get_logger().error("창고 이동 실패")
            goal_handle.abort()
            return NavigateToPose.Result()

        self.get_logger().info("모든 시나리오 완료!")
        goal_handle.succeed()
        return NavigateToPose.Result()

    async def _navigate_to(self, target_location: str) -> bool:
        """Nav2에 목표 Pose를 전달하고 결과를 기다림"""
        if target_location not in self._locations:
            return False

        loc = self._locations[target_location]
        goal_msg = NavigateToPose.Goal()
        goal_msg.pose = PoseStamped()
        goal_msg.pose.header.frame_id = 'map'
        goal_msg.pose.header.stamp = self.get_clock().now().to_msg()
        goal_msg.pose.pose.position.x = loc["x"]
        goal_msg.pose.pose.position.y = loc["y"]
        goal_msg.pose.pose.orientation.z = loc["z"]
        goal_msg.pose.pose.orientation.w = loc["w"]

        # 서버 대기
        self._nav2_client.wait_for_server()
        
        # 비동기 전송
        send_goal_future = self._nav2_client.send_goal_async(goal_msg)
        goal_handle = await send_goal_future

        if not goal_handle.accepted:
            self.get_logger().info(f"{target_location} 목표 거절됨")
            return False

        self.get_logger().info(f"{target_location} 목표 수락됨")
        result_future = goal_handle.get_result_async()
        result = await result_future

        # status 4는 SUCCEEDED를 의미
        return result.status == 4

def main(args=None):
    rclpy.init(args=args)
    node = SShopyNode()
    
    # ★ 핵심: 단일 스레드가 아닌 멀티 스레드 실행기 사용
    executor = MultiThreadedExecutor()
    executor.add_node(node)

    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()