// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from smart_cane_interfaces:msg/FeedbackCommand.idl
// generated code does not contain a copyright notice

#ifndef SMART_CANE_INTERFACES__MSG__DETAIL__FEEDBACK_COMMAND__TRAITS_HPP_
#define SMART_CANE_INTERFACES__MSG__DETAIL__FEEDBACK_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "smart_cane_interfaces/msg/detail/feedback_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace smart_cane_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const FeedbackCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: message_text
  {
    out << "message_text: ";
    rosidl_generator_traits::value_to_yaml(msg.message_text, out);
    out << ", ";
  }

  // member: vibration_enabled
  {
    out << "vibration_enabled: ";
    rosidl_generator_traits::value_to_yaml(msg.vibration_enabled, out);
    out << ", ";
  }

  // member: vibration_intensity
  {
    out << "vibration_intensity: ";
    rosidl_generator_traits::value_to_yaml(msg.vibration_intensity, out);
    out << ", ";
  }

  // member: audio_enabled
  {
    out << "audio_enabled: ";
    rosidl_generator_traits::value_to_yaml(msg.audio_enabled, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FeedbackCommand & msg,
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

  // member: message_text
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message_text: ";
    rosidl_generator_traits::value_to_yaml(msg.message_text, out);
    out << "\n";
  }

  // member: vibration_enabled
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vibration_enabled: ";
    rosidl_generator_traits::value_to_yaml(msg.vibration_enabled, out);
    out << "\n";
  }

  // member: vibration_intensity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vibration_intensity: ";
    rosidl_generator_traits::value_to_yaml(msg.vibration_intensity, out);
    out << "\n";
  }

  // member: audio_enabled
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "audio_enabled: ";
    rosidl_generator_traits::value_to_yaml(msg.audio_enabled, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FeedbackCommand & msg, bool use_flow_style = false)
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
  const smart_cane_interfaces::msg::FeedbackCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  smart_cane_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use smart_cane_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const smart_cane_interfaces::msg::FeedbackCommand & msg)
{
  return smart_cane_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<smart_cane_interfaces::msg::FeedbackCommand>()
{
  return "smart_cane_interfaces::msg::FeedbackCommand";
}

template<>
inline const char * name<smart_cane_interfaces::msg::FeedbackCommand>()
{
  return "smart_cane_interfaces/msg/FeedbackCommand";
}

template<>
struct has_fixed_size<smart_cane_interfaces::msg::FeedbackCommand>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<smart_cane_interfaces::msg::FeedbackCommand>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<smart_cane_interfaces::msg::FeedbackCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SMART_CANE_INTERFACES__MSG__DETAIL__FEEDBACK_COMMAND__TRAITS_HPP_
