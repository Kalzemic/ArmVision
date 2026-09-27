// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kinematics:srv/Kinematics.idl
// generated code does not contain a copyright notice

#ifndef KINEMATICS__SRV__DETAIL__KINEMATICS__STRUCT_H_
#define KINEMATICS__SRV__DETAIL__KINEMATICS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'target'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"

/// Struct defined in srv/Kinematics in the package kinematics.
typedef struct kinematics__srv__Kinematics_Request
{
  geometry_msgs__msg__PoseStamped target;
} kinematics__srv__Kinematics_Request;

// Struct for a sequence of kinematics__srv__Kinematics_Request.
typedef struct kinematics__srv__Kinematics_Request__Sequence
{
  kinematics__srv__Kinematics_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kinematics__srv__Kinematics_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'solution'
#include "sensor_msgs/msg/detail/joint_state__struct.h"

/// Struct defined in srv/Kinematics in the package kinematics.
typedef struct kinematics__srv__Kinematics_Response
{
  bool success;
  sensor_msgs__msg__JointState solution;
} kinematics__srv__Kinematics_Response;

// Struct for a sequence of kinematics__srv__Kinematics_Response.
typedef struct kinematics__srv__Kinematics_Response__Sequence
{
  kinematics__srv__Kinematics_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kinematics__srv__Kinematics_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KINEMATICS__SRV__DETAIL__KINEMATICS__STRUCT_H_
