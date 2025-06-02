// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from smart_cane_interfaces:msg/DetectionResult.idl
// generated code does not contain a copyright notice

#ifndef SMART_CANE_INTERFACES__MSG__DETAIL__DETECTION_RESULT__TRAITS_HPP_
#define SMART_CANE_INTERFACES__MSG__DETAIL__DETECTION_RESULT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "smart_cane_interfaces/msg/detail/detection_result__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'object_positions'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace smart_cane_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const DetectionResult & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: detected_objects
  {
    if (msg.detected_objects.size() == 0) {
      out << "detected_objects: []";
    } else {
      out << "detected_objects: [";
      size_t pending_items = msg.detected_objects.size();
      for (auto item : msg.detected_objects) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: object_positions
  {
    if (msg.object_positions.size() == 0) {
      out << "object_positions: []";
    } else {
      out << "object_positions: [";
      size_t pending_items = msg.object_positions.size();
      for (auto item : msg.object_positions) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: confidence_scores
  {
    if (msg.confidence_scores.size() == 0) {
      out << "confidence_scores: []";
    } else {
      out << "confidence_scores: [";
      size_t pending_items = msg.confidence_scores.size();
      for (auto item : msg.confidence_scores) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DetectionResult & msg,
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

  // member: detected_objects
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.detected_objects.size() == 0) {
      out << "detected_objects: []\n";
    } else {
      out << "detected_objects:\n";
      for (auto item : msg.detected_objects) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: object_positions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.object_positions.size() == 0) {
      out << "object_positions: []\n";
    } else {
      out << "object_positions:\n";
      for (auto item : msg.object_positions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: confidence_scores
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.confidence_scores.size() == 0) {
      out << "confidence_scores: []\n";
    } else {
      out << "confidence_scores:\n";
      for (auto item : msg.confidence_scores) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DetectionResult & msg, bool use_flow_style = false)
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
  const smart_cane_interfaces::msg::DetectionResult & msg,
  std::ostream & out, size_t indentation = 0)
{
  smart_cane_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use smart_cane_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const smart_cane_interfaces::msg::DetectionResult & msg)
{
  return smart_cane_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<smart_cane_interfaces::msg::DetectionResult>()
{
  return "smart_cane_interfaces::msg::DetectionResult";
}

template<>
inline const char * name<smart_cane_interfaces::msg::DetectionResult>()
{
  return "smart_cane_interfaces/msg/DetectionResult";
}

template<>
struct has_fixed_size<smart_cane_interfaces::msg::DetectionResult>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<smart_cane_interfaces::msg::DetectionResult>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<smart_cane_interfaces::msg::DetectionResult>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SMART_CANE_INTERFACES__MSG__DETAIL__DETECTION_RESULT__TRAITS_HPP_
