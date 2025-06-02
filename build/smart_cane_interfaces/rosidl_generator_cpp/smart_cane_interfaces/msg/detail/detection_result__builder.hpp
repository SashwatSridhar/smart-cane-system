// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from smart_cane_interfaces:msg/DetectionResult.idl
// generated code does not contain a copyright notice

#ifndef SMART_CANE_INTERFACES__MSG__DETAIL__DETECTION_RESULT__BUILDER_HPP_
#define SMART_CANE_INTERFACES__MSG__DETAIL__DETECTION_RESULT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "smart_cane_interfaces/msg/detail/detection_result__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace smart_cane_interfaces
{

namespace msg
{

namespace builder
{

class Init_DetectionResult_confidence_scores
{
public:
  explicit Init_DetectionResult_confidence_scores(::smart_cane_interfaces::msg::DetectionResult & msg)
  : msg_(msg)
  {}
  ::smart_cane_interfaces::msg::DetectionResult confidence_scores(::smart_cane_interfaces::msg::DetectionResult::_confidence_scores_type arg)
  {
    msg_.confidence_scores = std::move(arg);
    return std::move(msg_);
  }

private:
  ::smart_cane_interfaces::msg::DetectionResult msg_;
};

class Init_DetectionResult_object_positions
{
public:
  explicit Init_DetectionResult_object_positions(::smart_cane_interfaces::msg::DetectionResult & msg)
  : msg_(msg)
  {}
  Init_DetectionResult_confidence_scores object_positions(::smart_cane_interfaces::msg::DetectionResult::_object_positions_type arg)
  {
    msg_.object_positions = std::move(arg);
    return Init_DetectionResult_confidence_scores(msg_);
  }

private:
  ::smart_cane_interfaces::msg::DetectionResult msg_;
};

class Init_DetectionResult_detected_objects
{
public:
  explicit Init_DetectionResult_detected_objects(::smart_cane_interfaces::msg::DetectionResult & msg)
  : msg_(msg)
  {}
  Init_DetectionResult_object_positions detected_objects(::smart_cane_interfaces::msg::DetectionResult::_detected_objects_type arg)
  {
    msg_.detected_objects = std::move(arg);
    return Init_DetectionResult_object_positions(msg_);
  }

private:
  ::smart_cane_interfaces::msg::DetectionResult msg_;
};

class Init_DetectionResult_header
{
public:
  Init_DetectionResult_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectionResult_detected_objects header(::smart_cane_interfaces::msg::DetectionResult::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_DetectionResult_detected_objects(msg_);
  }

private:
  ::smart_cane_interfaces::msg::DetectionResult msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::smart_cane_interfaces::msg::DetectionResult>()
{
  return smart_cane_interfaces::msg::builder::Init_DetectionResult_header();
}

}  // namespace smart_cane_interfaces

#endif  // SMART_CANE_INTERFACES__MSG__DETAIL__DETECTION_RESULT__BUILDER_HPP_
