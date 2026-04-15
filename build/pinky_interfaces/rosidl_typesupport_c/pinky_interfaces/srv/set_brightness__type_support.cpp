// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from pinky_interfaces:srv/SetBrightness.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "pinky_interfaces/srv/detail/set_brightness__struct.h"
#include "pinky_interfaces/srv/detail/set_brightness__type_support.h"
#include "pinky_interfaces/srv/detail/set_brightness__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace pinky_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _SetBrightness_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetBrightness_Request_type_support_ids_t;

static const _SetBrightness_Request_type_support_ids_t _SetBrightness_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetBrightness_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetBrightness_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetBrightness_Request_type_support_symbol_names_t _SetBrightness_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pinky_interfaces, srv, SetBrightness_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pinky_interfaces, srv, SetBrightness_Request)),
  }
};

typedef struct _SetBrightness_Request_type_support_data_t
{
  void * data[2];
} _SetBrightness_Request_type_support_data_t;

static _SetBrightness_Request_type_support_data_t _SetBrightness_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetBrightness_Request_message_typesupport_map = {
  2,
  "pinky_interfaces",
  &_SetBrightness_Request_message_typesupport_ids.typesupport_identifier[0],
  &_SetBrightness_Request_message_typesupport_symbol_names.symbol_name[0],
  &_SetBrightness_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetBrightness_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetBrightness_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &pinky_interfaces__srv__SetBrightness_Request__get_type_hash,
  &pinky_interfaces__srv__SetBrightness_Request__get_type_description,
  &pinky_interfaces__srv__SetBrightness_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace pinky_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, pinky_interfaces, srv, SetBrightness_Request)() {
  return &::pinky_interfaces::srv::rosidl_typesupport_c::SetBrightness_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "pinky_interfaces/srv/detail/set_brightness__struct.h"
// already included above
// #include "pinky_interfaces/srv/detail/set_brightness__type_support.h"
// already included above
// #include "pinky_interfaces/srv/detail/set_brightness__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace pinky_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _SetBrightness_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetBrightness_Response_type_support_ids_t;

static const _SetBrightness_Response_type_support_ids_t _SetBrightness_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetBrightness_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetBrightness_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetBrightness_Response_type_support_symbol_names_t _SetBrightness_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pinky_interfaces, srv, SetBrightness_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pinky_interfaces, srv, SetBrightness_Response)),
  }
};

typedef struct _SetBrightness_Response_type_support_data_t
{
  void * data[2];
} _SetBrightness_Response_type_support_data_t;

static _SetBrightness_Response_type_support_data_t _SetBrightness_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetBrightness_Response_message_typesupport_map = {
  2,
  "pinky_interfaces",
  &_SetBrightness_Response_message_typesupport_ids.typesupport_identifier[0],
  &_SetBrightness_Response_message_typesupport_symbol_names.symbol_name[0],
  &_SetBrightness_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetBrightness_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetBrightness_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &pinky_interfaces__srv__SetBrightness_Response__get_type_hash,
  &pinky_interfaces__srv__SetBrightness_Response__get_type_description,
  &pinky_interfaces__srv__SetBrightness_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace pinky_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, pinky_interfaces, srv, SetBrightness_Response)() {
  return &::pinky_interfaces::srv::rosidl_typesupport_c::SetBrightness_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "pinky_interfaces/srv/detail/set_brightness__struct.h"
// already included above
// #include "pinky_interfaces/srv/detail/set_brightness__type_support.h"
// already included above
// #include "pinky_interfaces/srv/detail/set_brightness__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace pinky_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _SetBrightness_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetBrightness_Event_type_support_ids_t;

static const _SetBrightness_Event_type_support_ids_t _SetBrightness_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetBrightness_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetBrightness_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetBrightness_Event_type_support_symbol_names_t _SetBrightness_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pinky_interfaces, srv, SetBrightness_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pinky_interfaces, srv, SetBrightness_Event)),
  }
};

typedef struct _SetBrightness_Event_type_support_data_t
{
  void * data[2];
} _SetBrightness_Event_type_support_data_t;

static _SetBrightness_Event_type_support_data_t _SetBrightness_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetBrightness_Event_message_typesupport_map = {
  2,
  "pinky_interfaces",
  &_SetBrightness_Event_message_typesupport_ids.typesupport_identifier[0],
  &_SetBrightness_Event_message_typesupport_symbol_names.symbol_name[0],
  &_SetBrightness_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetBrightness_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetBrightness_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &pinky_interfaces__srv__SetBrightness_Event__get_type_hash,
  &pinky_interfaces__srv__SetBrightness_Event__get_type_description,
  &pinky_interfaces__srv__SetBrightness_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace pinky_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, pinky_interfaces, srv, SetBrightness_Event)() {
  return &::pinky_interfaces::srv::rosidl_typesupport_c::SetBrightness_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "pinky_interfaces/srv/detail/set_brightness__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
#include "service_msgs/msg/service_event_info.h"
#include "builtin_interfaces/msg/time.h"

namespace pinky_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{
typedef struct _SetBrightness_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetBrightness_type_support_ids_t;

static const _SetBrightness_type_support_ids_t _SetBrightness_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetBrightness_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetBrightness_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetBrightness_type_support_symbol_names_t _SetBrightness_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pinky_interfaces, srv, SetBrightness)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pinky_interfaces, srv, SetBrightness)),
  }
};

typedef struct _SetBrightness_type_support_data_t
{
  void * data[2];
} _SetBrightness_type_support_data_t;

static _SetBrightness_type_support_data_t _SetBrightness_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetBrightness_service_typesupport_map = {
  2,
  "pinky_interfaces",
  &_SetBrightness_service_typesupport_ids.typesupport_identifier[0],
  &_SetBrightness_service_typesupport_symbol_names.symbol_name[0],
  &_SetBrightness_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t SetBrightness_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetBrightness_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &SetBrightness_Request_message_type_support_handle,
  &SetBrightness_Response_message_type_support_handle,
  &SetBrightness_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    pinky_interfaces,
    srv,
    SetBrightness
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    pinky_interfaces,
    srv,
    SetBrightness
  ),
  &pinky_interfaces__srv__SetBrightness__get_type_hash,
  &pinky_interfaces__srv__SetBrightness__get_type_description,
  &pinky_interfaces__srv__SetBrightness__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace pinky_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, pinky_interfaces, srv, SetBrightness)() {
  return &::pinky_interfaces::srv::rosidl_typesupport_c::SetBrightness_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
