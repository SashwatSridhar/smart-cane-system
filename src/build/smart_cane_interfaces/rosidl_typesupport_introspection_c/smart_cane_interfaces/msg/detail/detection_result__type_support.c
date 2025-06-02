// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from smart_cane_interfaces:msg/DetectionResult.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "smart_cane_interfaces/msg/detail/detection_result__rosidl_typesupport_introspection_c.h"
#include "smart_cane_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "smart_cane_interfaces/msg/detail/detection_result__functions.h"
#include "smart_cane_interfaces/msg/detail/detection_result__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `detected_objects`
#include "rosidl_runtime_c/string_functions.h"
// Member `object_positions`
#include "geometry_msgs/msg/point.h"
// Member `object_positions`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"
// Member `confidence_scores`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__DetectionResult_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  smart_cane_interfaces__msg__DetectionResult__init(message_memory);
}

void smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__DetectionResult_fini_function(void * message_memory)
{
  smart_cane_interfaces__msg__DetectionResult__fini(message_memory);
}

size_t smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__size_function__DetectionResult__detected_objects(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__get_const_function__DetectionResult__detected_objects(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__get_function__DetectionResult__detected_objects(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__fetch_function__DetectionResult__detected_objects(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__get_const_function__DetectionResult__detected_objects(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__assign_function__DetectionResult__detected_objects(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__get_function__DetectionResult__detected_objects(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__resize_function__DetectionResult__detected_objects(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__size_function__DetectionResult__object_positions(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__get_const_function__DetectionResult__object_positions(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__get_function__DetectionResult__object_positions(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__fetch_function__DetectionResult__object_positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__get_const_function__DetectionResult__object_positions(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__assign_function__DetectionResult__object_positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__get_function__DetectionResult__object_positions(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__resize_function__DetectionResult__object_positions(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

size_t smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__size_function__DetectionResult__confidence_scores(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__get_const_function__DetectionResult__confidence_scores(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__get_function__DetectionResult__confidence_scores(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__fetch_function__DetectionResult__confidence_scores(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__get_const_function__DetectionResult__confidence_scores(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__assign_function__DetectionResult__confidence_scores(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__get_function__DetectionResult__confidence_scores(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__resize_function__DetectionResult__confidence_scores(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__DetectionResult_message_member_array[4] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(smart_cane_interfaces__msg__DetectionResult, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "detected_objects",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(smart_cane_interfaces__msg__DetectionResult, detected_objects),  // bytes offset in struct
    NULL,  // default value
    smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__size_function__DetectionResult__detected_objects,  // size() function pointer
    smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__get_const_function__DetectionResult__detected_objects,  // get_const(index) function pointer
    smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__get_function__DetectionResult__detected_objects,  // get(index) function pointer
    smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__fetch_function__DetectionResult__detected_objects,  // fetch(index, &value) function pointer
    smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__assign_function__DetectionResult__detected_objects,  // assign(index, value) function pointer
    smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__resize_function__DetectionResult__detected_objects  // resize(index) function pointer
  },
  {
    "object_positions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(smart_cane_interfaces__msg__DetectionResult, object_positions),  // bytes offset in struct
    NULL,  // default value
    smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__size_function__DetectionResult__object_positions,  // size() function pointer
    smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__get_const_function__DetectionResult__object_positions,  // get_const(index) function pointer
    smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__get_function__DetectionResult__object_positions,  // get(index) function pointer
    smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__fetch_function__DetectionResult__object_positions,  // fetch(index, &value) function pointer
    smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__assign_function__DetectionResult__object_positions,  // assign(index, value) function pointer
    smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__resize_function__DetectionResult__object_positions  // resize(index) function pointer
  },
  {
    "confidence_scores",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(smart_cane_interfaces__msg__DetectionResult, confidence_scores),  // bytes offset in struct
    NULL,  // default value
    smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__size_function__DetectionResult__confidence_scores,  // size() function pointer
    smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__get_const_function__DetectionResult__confidence_scores,  // get_const(index) function pointer
    smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__get_function__DetectionResult__confidence_scores,  // get(index) function pointer
    smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__fetch_function__DetectionResult__confidence_scores,  // fetch(index, &value) function pointer
    smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__assign_function__DetectionResult__confidence_scores,  // assign(index, value) function pointer
    smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__resize_function__DetectionResult__confidence_scores  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__DetectionResult_message_members = {
  "smart_cane_interfaces__msg",  // message namespace
  "DetectionResult",  // message name
  4,  // number of fields
  sizeof(smart_cane_interfaces__msg__DetectionResult),
  smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__DetectionResult_message_member_array,  // message members
  smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__DetectionResult_init_function,  // function to initialize message memory (memory has to be allocated)
  smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__DetectionResult_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__DetectionResult_message_type_support_handle = {
  0,
  &smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__DetectionResult_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_smart_cane_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, smart_cane_interfaces, msg, DetectionResult)() {
  smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__DetectionResult_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__DetectionResult_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__DetectionResult_message_type_support_handle.typesupport_identifier) {
    smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__DetectionResult_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &smart_cane_interfaces__msg__DetectionResult__rosidl_typesupport_introspection_c__DetectionResult_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
