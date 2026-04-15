#!/usr/bin/env python3
"""
Component: SShopy (sp) / FrontJet (fj) / WareJet (wj) ROS2 노드
Role: 메인서버의 ROS2 Action 요청을 수신하고, 로봇 동작 수행 후 result 응답.
"""
import threading
import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer, GoalResponse, CancelResponse
from rclpy.action.server import ServerGoalHandle
from nav2_msgs.action import NavigateToPose
from rclpy.action import ActionClient
from geometry_msgs.msg import PoseStamped
from std_msgs.msg import Bool 
import logging
logger = logging.getLogger("robot_nodes")

from dataclasses import dataclass
from typing import Optional

@dataclass
class MoveGoal:
    target_location: str

@dataclass
class MoveResult:
    success: bool
    message: str

class SShopyNode(Node):
    def __init__(self):
        super().__init__("sshopy_node")

        # Nav2 Action Client
        self._nav2_client = ActionClient(
            self,
            NavigateToPose,
            'navigate_to_pose'
        )

        # 적재 완료 신호 수신 토픽 (메인서버 → 핑키)
        self._load_complete_sub = self.create_subscription(
            Bool,
            '/load_complete',
            self._load_complete_callback,
            10
        )

        # 도착 신호 발행 토픽 (핑키 → 메인서버)
        self._arrived_pub = self.create_publisher(
            Bool,
            '/pinky/arrived',
            10
        )

        # 좌표 딕셔너리
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
            },
        }

        self._load_complete = False
        self._load_event = threading.Event()

        # Action Server 등록
        self._move_action_server = ActionServer(
            self,
            NavigateToPose,
            "/sshopy/move",
            execute_callback=self.execute_move_callback,
            goal_callback=self.goal_callback,
            cancel_callback=self.cancel_callback,
        )

        self.get_logger().info("SShopy 노드 시작!")

    def goal_callback(self, goal_request) -> GoalResponse:
        self.get_logger().info("이동 요청 수신")
        return GoalResponse.ACCEPT

    def cancel_callback(self, goal_handle: ServerGoalHandle) -> CancelResponse:
        self.get_logger().info("취소 요청 수신")
        return CancelResponse.ACCEPT

    def _load_complete_callback(self, msg: Bool):
        if msg.data:
            self.get_logger().info("적재 완료 신호 수신!")
            self._load_complete = True
            self._load_event.set()

    async def execute_move_callback(self, goal_handle: ServerGoalHandle):
        self.get_logger().info("이동 시작!")

        # 1단계 — 창고로 이동
        self.get_logger().info("창고로 이동 중...")
        success = await self._navigate_to("warejet")

        if not success:
            goal_handle.abort()
            return MoveResult(success=False, message="창고 이동 실패")

        # 2단계 — 도착 신호 발행
        self.get_logger().info("창고 도착! 메인서버에 신호 발송")
        arrived_msg = Bool()
        arrived_msg.data = True
        self._arrived_pub.publish(arrived_msg)

        # 3단계 — 적재 완료 신호 대기
        self.get_logger().info("적재 완료 신호 대기 중...")
        self._load_complete = False
        while not self._load_complete:
            rclpy.spin_once(self, timeout_sec=0.5)

        # 4단계 — 입구로 이동
        self.get_logger().info("입구로 이동 중...")
        success = await self._navigate_to("frontjet")

        if not success:
            goal_handle.abort()
            return MoveResult(success=False, message="입구 이동 실패")

        # 5단계 — 완료
        self.get_logger().info("입구 도착 완료!")
        goal_handle.succeed()
        return MoveResult(success=True, message="전체 동작 완료")

    async def _navigate_to(self, target_location: str) -> bool:
        if target_location not in self._locations:
            self.get_logger().error(f"알 수 없는 위치: {target_location}")
            return False

        loc = self._locations[target_location]

        # Nav2 goal 생성
        goal_msg = NavigateToPose.Goal()
        goal_msg.pose = PoseStamped()
        goal_msg.pose.header.frame_id = 'map'
        goal_msg.pose.header.stamp = self.get_clock().now().to_msg()
        goal_msg.pose.pose.position.x = loc["x"]
        goal_msg.pose.pose.position.y = loc["y"]
        goal_msg.pose.pose.orientation.z = loc["z"]
        goal_msg.pose.pose.orientation.w = loc["w"]

        # Nav2 대기
        self._nav2_client.wait_for_server()

        # goal 전송
        send_goal_future = await self._nav2_client.send_goal_async(goal_msg)

        if not send_goal_future.accepted:
            self.get_logger().error("Nav2 goal 거절됨")
            return False

        # 완료 대기
        result_future = await send_goal_future.get_result_async()

        if result_future.status == 4:  # SUCCEEDED
            self.get_logger().info(f"{target_location} 도착 완료!")
            return True
        else:
            self.get_logger().error(f"{target_location} 이동 실패")
            return False


def run_sshopy():
    rclpy.init()
    node = SShopyNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    run_sshopy()