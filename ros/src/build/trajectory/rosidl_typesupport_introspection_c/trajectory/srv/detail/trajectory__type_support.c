// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from trajectory:srv/Trajectory.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "trajectory/srv/detail/trajectory__rosidl_typesupport_introspection_c.h"
#include "trajectory/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "trajectory/srv/detail/trajectory__functions.h"
#include "trajectory/srv/detail/trajectory__struct.h"


// Include directives for member types
// Member `goal`
#include "sensor_msgs/msg/joint_state.h"
// Member `goal`
#include "sensor_msgs/msg/detail/joint_state__rosidl_typesupport_introspection_c.h"
// Member `duration`
#include "builtin_interfaces/msg/duration.h"
// Member `duration`
#include "builtin_interfaces/msg/detail/duration__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void trajectory__srv__Trajectory_Request__rosidl_typesupport_introspection_c__Trajectory_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trajectory__srv__Trajectory_Request__init(message_memory);
}

void trajectory__srv__Trajectory_Request__rosidl_typesupport_introspection_c__Trajectory_Request_fini_function(void * message_memory)
{
  trajectory__srv__Trajectory_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember trajectory__srv__Trajectory_Request__rosidl_typesupport_introspection_c__Trajectory_Request_message_member_array[2] = {
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trajectory__srv__Trajectory_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "duration",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trajectory__srv__Trajectory_Request, duration),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers trajectory__srv__Trajectory_Request__rosidl_typesupport_introspection_c__Trajectory_Request_message_members = {
  "trajectory__srv",  // message namespace
  "Trajectory_Request",  // message name
  2,  // number of fields
  sizeof(trajectory__srv__Trajectory_Request),
  trajectory__srv__Trajectory_Request__rosidl_typesupport_introspection_c__Trajectory_Request_message_member_array,  // message members
  trajectory__srv__Trajectory_Request__rosidl_typesupport_introspection_c__Trajectory_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  trajectory__srv__Trajectory_Request__rosidl_typesupport_introspection_c__Trajectory_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t trajectory__srv__Trajectory_Request__rosidl_typesupport_introspection_c__Trajectory_Request_message_type_support_handle = {
  0,
  &trajectory__srv__Trajectory_Request__rosidl_typesupport_introspection_c__Trajectory_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trajectory
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory, srv, Trajectory_Request)() {
  trajectory__srv__Trajectory_Request__rosidl_typesupport_introspection_c__Trajectory_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, JointState)();
  trajectory__srv__Trajectory_Request__rosidl_typesupport_introspection_c__Trajectory_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Duration)();
  if (!trajectory__srv__Trajectory_Request__rosidl_typesupport_introspection_c__Trajectory_Request_message_type_support_handle.typesupport_identifier) {
    trajectory__srv__Trajectory_Request__rosidl_typesupport_introspection_c__Trajectory_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &trajectory__srv__Trajectory_Request__rosidl_typesupport_introspection_c__Trajectory_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trajectory/srv/detail/trajectory__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trajectory/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trajectory/srv/detail/trajectory__functions.h"
// already included above
// #include "trajectory/srv/detail/trajectory__struct.h"


// Include directives for member types
// Member `trajectory`
#include "trajectory_msgs/msg/joint_trajectory.h"
// Member `trajectory`
#include "trajectory_msgs/msg/detail/joint_trajectory__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void trajectory__srv__Trajectory_Response__rosidl_typesupport_introspection_c__Trajectory_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trajectory__srv__Trajectory_Response__init(message_memory);
}

void trajectory__srv__Trajectory_Response__rosidl_typesupport_introspection_c__Trajectory_Response_fini_function(void * message_memory)
{
  trajectory__srv__Trajectory_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember trajectory__srv__Trajectory_Response__rosidl_typesupport_introspection_c__Trajectory_Response_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trajectory__srv__Trajectory_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "trajectory",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trajectory__srv__Trajectory_Response, trajectory),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers trajectory__srv__Trajectory_Response__rosidl_typesupport_introspection_c__Trajectory_Response_message_members = {
  "trajectory__srv",  // message namespace
  "Trajectory_Response",  // message name
  2,  // number of fields
  sizeof(trajectory__srv__Trajectory_Response),
  trajectory__srv__Trajectory_Response__rosidl_typesupport_introspection_c__Trajectory_Response_message_member_array,  // message members
  trajectory__srv__Trajectory_Response__rosidl_typesupport_introspection_c__Trajectory_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  trajectory__srv__Trajectory_Response__rosidl_typesupport_introspection_c__Trajectory_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t trajectory__srv__Trajectory_Response__rosidl_typesupport_introspection_c__Trajectory_Response_message_type_support_handle = {
  0,
  &trajectory__srv__Trajectory_Response__rosidl_typesupport_introspection_c__Trajectory_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trajectory
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory, srv, Trajectory_Response)() {
  trajectory__srv__Trajectory_Response__rosidl_typesupport_introspection_c__Trajectory_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory_msgs, msg, JointTrajectory)();
  if (!trajectory__srv__Trajectory_Response__rosidl_typesupport_introspection_c__Trajectory_Response_message_type_support_handle.typesupport_identifier) {
    trajectory__srv__Trajectory_Response__rosidl_typesupport_introspection_c__Trajectory_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &trajectory__srv__Trajectory_Response__rosidl_typesupport_introspection_c__Trajectory_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "trajectory/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "trajectory/srv/detail/trajectory__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers trajectory__srv__detail__trajectory__rosidl_typesupport_introspection_c__Trajectory_service_members = {
  "trajectory__srv",  // service namespace
  "Trajectory",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // trajectory__srv__detail__trajectory__rosidl_typesupport_introspection_c__Trajectory_Request_message_type_support_handle,
  NULL  // response message
  // trajectory__srv__detail__trajectory__rosidl_typesupport_introspection_c__Trajectory_Response_message_type_support_handle
};

static rosidl_service_type_support_t trajectory__srv__detail__trajectory__rosidl_typesupport_introspection_c__Trajectory_service_type_support_handle = {
  0,
  &trajectory__srv__detail__trajectory__rosidl_typesupport_introspection_c__Trajectory_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory, srv, Trajectory_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory, srv, Trajectory_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trajectory
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory, srv, Trajectory)() {
  if (!trajectory__srv__detail__trajectory__rosidl_typesupport_introspection_c__Trajectory_service_type_support_handle.typesupport_identifier) {
    trajectory__srv__detail__trajectory__rosidl_typesupport_introspection_c__Trajectory_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)trajectory__srv__detail__trajectory__rosidl_typesupport_introspection_c__Trajectory_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory, srv, Trajectory_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory, srv, Trajectory_Response)()->data;
  }

  return &trajectory__srv__detail__trajectory__rosidl_typesupport_introspection_c__Trajectory_service_type_support_handle;
}
