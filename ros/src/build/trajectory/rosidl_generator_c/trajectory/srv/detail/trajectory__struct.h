// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from trajectory:srv/Trajectory.idl
// generated code does not contain a copyright notice

#ifndef TRAJECTORY__SRV__DETAIL__TRAJECTORY__STRUCT_H_
#define TRAJECTORY__SRV__DETAIL__TRAJECTORY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'goal'
#include "sensor_msgs/msg/detail/joint_state__struct.h"
// Member 'duration'
#include "builtin_interfaces/msg/detail/duration__struct.h"

/// Struct defined in srv/Trajectory in the package trajectory.
typedef struct trajectory__srv__Trajectory_Request
{
  sensor_msgs__msg__JointState goal;
  builtin_interfaces__msg__Duration duration;
} trajectory__srv__Trajectory_Request;

// Struct for a sequence of trajectory__srv__Trajectory_Request.
typedef struct trajectory__srv__Trajectory_Request__Sequence
{
  trajectory__srv__Trajectory_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trajectory__srv__Trajectory_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'trajectory'
#include "trajectory_msgs/msg/detail/joint_trajectory__struct.h"

/// Struct defined in srv/Trajectory in the package trajectory.
typedef struct trajectory__srv__Trajectory_Response
{
  bool success;
  trajectory_msgs__msg__JointTrajectory trajectory;
} trajectory__srv__Trajectory_Response;

// Struct for a sequence of trajectory__srv__Trajectory_Response.
typedef struct trajectory__srv__Trajectory_Response__Sequence
{
  trajectory__srv__Trajectory_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trajectory__srv__Trajectory_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRAJECTORY__SRV__DETAIL__TRAJECTORY__STRUCT_H_
