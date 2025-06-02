// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from smart_cane_interfaces:msg/DetectionResult.idl
// generated code does not contain a copyright notice

#ifndef SMART_CANE_INTERFACES__MSG__DETAIL__DETECTION_RESULT__STRUCT_H_
#define SMART_CANE_INTERFACES__MSG__DETAIL__DETECTION_RESULT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'detected_objects'
#include "rosidl_runtime_c/string.h"
// Member 'object_positions'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'confidence_scores'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/DetectionResult in the package smart_cane_interfaces.
/**
  * Object detection results
 */
typedef struct smart_cane_interfaces__msg__DetectionResult
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String__Sequence detected_objects;
  geometry_msgs__msg__Point__Sequence object_positions;
  rosidl_runtime_c__float__Sequence confidence_scores;
} smart_cane_interfaces__msg__DetectionResult;

// Struct for a sequence of smart_cane_interfaces__msg__DetectionResult.
typedef struct smart_cane_interfaces__msg__DetectionResult__Sequence
{
  smart_cane_interfaces__msg__DetectionResult * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} smart_cane_interfaces__msg__DetectionResult__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SMART_CANE_INTERFACES__MSG__DETAIL__DETECTION_RESULT__STRUCT_H_
