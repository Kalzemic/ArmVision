// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from trajectory:srv/Trajectory.idl
// generated code does not contain a copyright notice

#ifndef TRAJECTORY__SRV__DETAIL__TRAJECTORY__TRAITS_HPP_
#define TRAJECTORY__SRV__DETAIL__TRAJECTORY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "trajectory/srv/detail/trajectory__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'goal'
#include "sensor_msgs/msg/detail/joint_state__traits.hpp"
// Member 'duration'
#include "builtin_interfaces/msg/detail/duration__traits.hpp"

namespace trajectory
{

namespace srv
{

inline void to_flow_style_yaml(
  const Trajectory_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
    out << ", ";
  }

  // member: duration
  {
    out << "duration: ";
    to_flow_style_yaml(msg.duration, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Trajectory_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }

  // member: duration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "duration:\n";
    to_block_style_yaml(msg.duration, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Trajectory_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace trajectory

namespace rosidl_generator_traits
{

[[deprecated("use trajectory::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const trajectory::srv::Trajectory_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  trajectory::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use trajectory::srv::to_yaml() instead")]]
inline std::string to_yaml(const trajectory::srv::Trajectory_Request & msg)
{
  return trajectory::srv::to_yaml(msg);
}

template<>
inline const char * data_type<trajectory::srv::Trajectory_Request>()
{
  return "trajectory::srv::Trajectory_Request";
}

template<>
inline const char * name<trajectory::srv::Trajectory_Request>()
{
  return "trajectory/srv/Trajectory_Request";
}

template<>
struct has_fixed_size<trajectory::srv::Trajectory_Request>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Duration>::value && has_fixed_size<sensor_msgs::msg::JointState>::value> {};

template<>
struct has_bounded_size<trajectory::srv::Trajectory_Request>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Duration>::value && has_bounded_size<sensor_msgs::msg::JointState>::value> {};

template<>
struct is_message<trajectory::srv::Trajectory_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'trajectory'
#include "trajectory_msgs/msg/detail/joint_trajectory__traits.hpp"

namespace trajectory
{

namespace srv
{

inline void to_flow_style_yaml(
  const Trajectory_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: trajectory
  {
    out << "trajectory: ";
    to_flow_style_yaml(msg.trajectory, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Trajectory_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: trajectory
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "trajectory:\n";
    to_block_style_yaml(msg.trajectory, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Trajectory_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace trajectory

namespace rosidl_generator_traits
{

[[deprecated("use trajectory::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const trajectory::srv::Trajectory_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  trajectory::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use trajectory::srv::to_yaml() instead")]]
inline std::string to_yaml(const trajectory::srv::Trajectory_Response & msg)
{
  return trajectory::srv::to_yaml(msg);
}

template<>
inline const char * data_type<trajectory::srv::Trajectory_Response>()
{
  return "trajectory::srv::Trajectory_Response";
}

template<>
inline const char * name<trajectory::srv::Trajectory_Response>()
{
  return "trajectory/srv/Trajectory_Response";
}

template<>
struct has_fixed_size<trajectory::srv::Trajectory_Response>
  : std::integral_constant<bool, has_fixed_size<trajectory_msgs::msg::JointTrajectory>::value> {};

template<>
struct has_bounded_size<trajectory::srv::Trajectory_Response>
  : std::integral_constant<bool, has_bounded_size<trajectory_msgs::msg::JointTrajectory>::value> {};

template<>
struct is_message<trajectory::srv::Trajectory_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trajectory::srv::Trajectory>()
{
  return "trajectory::srv::Trajectory";
}

template<>
inline const char * name<trajectory::srv::Trajectory>()
{
  return "trajectory/srv/Trajectory";
}

template<>
struct has_fixed_size<trajectory::srv::Trajectory>
  : std::integral_constant<
    bool,
    has_fixed_size<trajectory::srv::Trajectory_Request>::value &&
    has_fixed_size<trajectory::srv::Trajectory_Response>::value
  >
{
};

template<>
struct has_bounded_size<trajectory::srv::Trajectory>
  : std::integral_constant<
    bool,
    has_bounded_size<trajectory::srv::Trajectory_Request>::value &&
    has_bounded_size<trajectory::srv::Trajectory_Response>::value
  >
{
};

template<>
struct is_service<trajectory::srv::Trajectory>
  : std::true_type
{
};

template<>
struct is_service_request<trajectory::srv::Trajectory_Request>
  : std::true_type
{
};

template<>
struct is_service_response<trajectory::srv::Trajectory_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TRAJECTORY__SRV__DETAIL__TRAJECTORY__TRAITS_HPP_
