// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from smart_cane_interfaces:msg/DetectionResult.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "smart_cane_interfaces/msg/detail/detection_result__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace smart_cane_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void DetectionResult_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) smart_cane_interfaces::msg::DetectionResult(_init);
}

void DetectionResult_fini_function(void * message_memory)
{
  auto typed_message = static_cast<smart_cane_interfaces::msg::DetectionResult *>(message_memory);
  typed_message->~DetectionResult();
}

size_t size_function__DetectionResult__detected_objects(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DetectionResult__detected_objects(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__DetectionResult__detected_objects(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__DetectionResult__detected_objects(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__DetectionResult__detected_objects(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__DetectionResult__detected_objects(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__DetectionResult__detected_objects(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__DetectionResult__detected_objects(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

size_t size_function__DetectionResult__object_positions(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DetectionResult__object_positions(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void * get_function__DetectionResult__object_positions(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void fetch_function__DetectionResult__object_positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const geometry_msgs::msg::Point *>(
    get_const_function__DetectionResult__object_positions(untyped_member, index));
  auto & value = *reinterpret_cast<geometry_msgs::msg::Point *>(untyped_value);
  value = item;
}

void assign_function__DetectionResult__object_positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<geometry_msgs::msg::Point *>(
    get_function__DetectionResult__object_positions(untyped_member, index));
  const auto & value = *reinterpret_cast<const geometry_msgs::msg::Point *>(untyped_value);
  item = value;
}

void resize_function__DetectionResult__object_positions(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  member->resize(size);
}

size_t size_function__DetectionResult__confidence_scores(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DetectionResult__confidence_scores(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__DetectionResult__confidence_scores(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__DetectionResult__confidence_scores(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__DetectionResult__confidence_scores(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__DetectionResult__confidence_scores(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__DetectionResult__confidence_scores(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__DetectionResult__confidence_scores(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DetectionResult_message_member_array[4] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(smart_cane_interfaces::msg::DetectionResult, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "detected_objects",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(smart_cane_interfaces::msg::DetectionResult, detected_objects),  // bytes offset in struct
    nullptr,  // default value
    size_function__DetectionResult__detected_objects,  // size() function pointer
    get_const_function__DetectionResult__detected_objects,  // get_const(index) function pointer
    get_function__DetectionResult__detected_objects,  // get(index) function pointer
    fetch_function__DetectionResult__detected_objects,  // fetch(index, &value) function pointer
    assign_function__DetectionResult__detected_objects,  // assign(index, value) function pointer
    resize_function__DetectionResult__detected_objects  // resize(index) function pointer
  },
  {
    "object_positions",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(smart_cane_interfaces::msg::DetectionResult, object_positions),  // bytes offset in struct
    nullptr,  // default value
    size_function__DetectionResult__object_positions,  // size() function pointer
    get_const_function__DetectionResult__object_positions,  // get_const(index) function pointer
    get_function__DetectionResult__object_positions,  // get(index) function pointer
    fetch_function__DetectionResult__object_positions,  // fetch(index, &value) function pointer
    assign_function__DetectionResult__object_positions,  // assign(index, value) function pointer
    resize_function__DetectionResult__object_positions  // resize(index) function pointer
  },
  {
    "confidence_scores",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(smart_cane_interfaces::msg::DetectionResult, confidence_scores),  // bytes offset in struct
    nullptr,  // default value
    size_function__DetectionResult__confidence_scores,  // size() function pointer
    get_const_function__DetectionResult__confidence_scores,  // get_const(index) function pointer
    get_function__DetectionResult__confidence_scores,  // get(index) function pointer
    fetch_function__DetectionResult__confidence_scores,  // fetch(index, &value) function pointer
    assign_function__DetectionResult__confidence_scores,  // assign(index, value) function pointer
    resize_function__DetectionResult__confidence_scores  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DetectionResult_message_members = {
  "smart_cane_interfaces::msg",  // message namespace
  "DetectionResult",  // message name
  4,  // number of fields
  sizeof(smart_cane_interfaces::msg::DetectionResult),
  DetectionResult_message_member_array,  // message members
  DetectionResult_init_function,  // function to initialize message memory (memory has to be allocated)
  DetectionResult_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DetectionResult_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DetectionResult_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace smart_cane_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<smart_cane_interfaces::msg::DetectionResult>()
{
  return &::smart_cane_interfaces::msg::rosidl_typesupport_introspection_cpp::DetectionResult_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, smart_cane_interfaces, msg, DetectionResult)() {
  return &::smart_cane_interfaces::msg::rosidl_typesupport_introspection_cpp::DetectionResult_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
