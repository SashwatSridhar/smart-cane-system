// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from smart_cane_interfaces:msg/UltrasonicData.idl
// generated code does not contain a copyright notice

#ifndef SMART_CANE_INTERFACES__MSG__DETAIL__ULTRASONIC_DATA__BUILDER_HPP_
#define SMART_CANE_INTERFACES__MSG__DETAIL__ULTRASONIC_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "smart_cane_interfaces/msg/detail/ultrasonic_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace smart_cane_interfaces
{

namespace msg
{

namespace builder
{

class Init_UltrasonicData_obstacle_detected
{
public:
  explicit Init_UltrasonicData_obstacle_detected(::smart_cane_interfaces::msg::UltrasonicData & msg)
  : msg_(msg)
  {}
  ::smart_cane_interfaces::msg::UltrasonicData obstacle_detected(::smart_cane_interfaces::msg::UltrasonicData::_obstacle_detected_type arg)
  {
    msg_.obstacle_detected = std::move(arg);
    return std::move(msg_);
  }

private:
  ::smart_cane_interfaces::msg::UltrasonicData msg_;
};

class Init_UltrasonicData_confidence
{
public:
  explicit Init_UltrasonicData_confidence(::smart_cane_interfaces::msg::UltrasonicData & msg)
  : msg_(msg)
  {}
  Init_UltrasonicData_obstacle_detected confidence(::smart_cane_interfaces::msg::UltrasonicData::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_UltrasonicData_obstacle_detected(msg_);
  }

private:
  ::smart_cane_interfaces::msg::UltrasonicData msg_;
};

class Init_UltrasonicData_distance_cm
{
public:
  explicit Init_UltrasonicData_distance_cm(::smart_cane_interfaces::msg::UltrasonicData & msg)
  : msg_(msg)
  {}
  Init_UltrasonicData_confidence distance_cm(::smart_cane_interfaces::msg::UltrasonicData::_distance_cm_type arg)
  {
    msg_.distance_cm = std::move(arg);
    return Init_UltrasonicData_confidence(msg_);
  }

private:
  ::smart_cane_interfaces::msg::UltrasonicData msg_;
};

class Init_UltrasonicData_header
{
public:
  Init_UltrasonicData_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UltrasonicData_distance_cm header(::smart_cane_interfaces::msg::UltrasonicData::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_UltrasonicData_distance_cm(msg_);
  }

private:
  ::smart_cane_interfaces::msg::UltrasonicData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::smart_cane_interfaces::msg::UltrasonicData>()
{
  return smart_cane_interfaces::msg::builder::Init_UltrasonicData_header();
}

}  // namespace smart_cane_interfaces

#endif  // SMART_CANE_INTERFACES__MSG__DETAIL__ULTRASONIC_DATA__BUILDER_HPP_
