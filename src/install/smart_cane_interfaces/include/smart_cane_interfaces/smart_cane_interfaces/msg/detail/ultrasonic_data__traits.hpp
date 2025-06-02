// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from smart_cane_interfaces:msg/UltrasonicData.idl
// generated code does not contain a copyright notice

#ifndef SMART_CANE_INTERFACES__MSG__DETAIL__ULTRASONIC_DATA__TRAITS_HPP_
#define SMART_CANE_INTERFACES__MSG__DETAIL__ULTRASONIC_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "smart_cane_interfaces/msg/detail/ultrasonic_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace smart_cane_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const UltrasonicData & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: distance_cm
  {
    out << "distance_cm: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_cm, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << ", ";
  }

  // member: obstacle_detected
  {
    out << "obstacle_detected: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_detected, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UltrasonicData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: distance_cm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance_cm: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_cm, out);
    out << "\n";
  }

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }

  // member: obstacle_detected
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "obstacle_detected: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_detected, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UltrasonicData & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace smart_cane_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use smart_cane_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const smart_cane_interfaces::msg::UltrasonicData & msg,
  std::ostream & out, size_t indentation = 0)
{
  smart_cane_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use smart_cane_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const smart_cane_interfaces::msg::UltrasonicData & msg)
{
  return smart_cane_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<smart_cane_interfaces::msg::UltrasonicData>()
{
  return "smart_cane_interfaces::msg::UltrasonicData";
}

template<>
inline const char * name<smart_cane_interfaces::msg::UltrasonicData>()
{
  return "smart_cane_interfaces/msg/UltrasonicData";
}

template<>
struct has_fixed_size<smart_cane_interfaces::msg::UltrasonicData>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<smart_cane_interfaces::msg::UltrasonicData>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<smart_cane_interfaces::msg::UltrasonicData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SMART_CANE_INTERFACES__MSG__DETAIL__ULTRASONIC_DATA__TRAITS_HPP_
