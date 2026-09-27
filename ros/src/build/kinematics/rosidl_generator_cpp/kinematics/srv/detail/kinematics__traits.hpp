// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from kinematics:srv/Kinematics.idl
// generated code does not contain a copyright notice

#ifndef KINEMATICS__SRV__DETAIL__KINEMATICS__TRAITS_HPP_
#define KINEMATICS__SRV__DETAIL__KINEMATICS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "kinematics/srv/detail/kinematics__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'target'
#include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"

namespace kinematics
{

namespace srv
{

inline void to_flow_style_yaml(
  const Kinematics_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: target
  {
    out << "target: ";
    to_flow_style_yaml(msg.target, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Kinematics_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: target
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target:\n";
    to_block_style_yaml(msg.target, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Kinematics_Request & msg, bool use_flow_style = false)
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

}  // namespace kinematics

namespace rosidl_generator_traits
{

[[deprecated("use kinematics::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const kinematics::srv::Kinematics_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  kinematics::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use kinematics::srv::to_yaml() instead")]]
inline std::string to_yaml(const kinematics::srv::Kinematics_Request & msg)
{
  return kinematics::srv::to_yaml(msg);
}

template<>
inline const char * data_type<kinematics::srv::Kinematics_Request>()
{
  return "kinematics::srv::Kinematics_Request";
}

template<>
inline const char * name<kinematics::srv::Kinematics_Request>()
{
  return "kinematics/srv/Kinematics_Request";
}

template<>
struct has_fixed_size<kinematics::srv::Kinematics_Request>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::PoseStamped>::value> {};

template<>
struct has_bounded_size<kinematics::srv::Kinematics_Request>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::PoseStamped>::value> {};

template<>
struct is_message<kinematics::srv::Kinematics_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'solution'
#include "sensor_msgs/msg/detail/joint_state__traits.hpp"

namespace kinematics
{

namespace srv
{

inline void to_flow_style_yaml(
  const Kinematics_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: solution
  {
    out << "solution: ";
    to_flow_style_yaml(msg.solution, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Kinematics_Response & msg,
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

  // member: solution
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "solution:\n";
    to_block_style_yaml(msg.solution, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Kinematics_Response & msg, bool use_flow_style = false)
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

}  // namespace kinematics

namespace rosidl_generator_traits
{

[[deprecated("use kinematics::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const kinematics::srv::Kinematics_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  kinematics::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use kinematics::srv::to_yaml() instead")]]
inline std::string to_yaml(const kinematics::srv::Kinematics_Response & msg)
{
  return kinematics::srv::to_yaml(msg);
}

template<>
inline const char * data_type<kinematics::srv::Kinematics_Response>()
{
  return "kinematics::srv::Kinematics_Response";
}

template<>
inline const char * name<kinematics::srv::Kinematics_Response>()
{
  return "kinematics/srv/Kinematics_Response";
}

template<>
struct has_fixed_size<kinematics::srv::Kinematics_Response>
  : std::integral_constant<bool, has_fixed_size<sensor_msgs::msg::JointState>::value> {};

template<>
struct has_bounded_size<kinematics::srv::Kinematics_Response>
  : std::integral_constant<bool, has_bounded_size<sensor_msgs::msg::JointState>::value> {};

template<>
struct is_message<kinematics::srv::Kinematics_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<kinematics::srv::Kinematics>()
{
  return "kinematics::srv::Kinematics";
}

template<>
inline const char * name<kinematics::srv::Kinematics>()
{
  return "kinematics/srv/Kinematics";
}

template<>
struct has_fixed_size<kinematics::srv::Kinematics>
  : std::integral_constant<
    bool,
    has_fixed_size<kinematics::srv::Kinematics_Request>::value &&
    has_fixed_size<kinematics::srv::Kinematics_Response>::value
  >
{
};

template<>
struct has_bounded_size<kinematics::srv::Kinematics>
  : std::integral_constant<
    bool,
    has_bounded_size<kinematics::srv::Kinematics_Request>::value &&
    has_bounded_size<kinematics::srv::Kinematics_Response>::value
  >
{
};

template<>
struct is_service<kinematics::srv::Kinematics>
  : std::true_type
{
};

template<>
struct is_service_request<kinematics::srv::Kinematics_Request>
  : std::true_type
{
};

template<>
struct is_service_response<kinematics::srv::Kinematics_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // KINEMATICS__SRV__DETAIL__KINEMATICS__TRAITS_HPP_
