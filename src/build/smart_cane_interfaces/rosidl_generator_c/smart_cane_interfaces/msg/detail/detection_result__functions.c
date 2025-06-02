// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from smart_cane_interfaces:msg/DetectionResult.idl
// generated code does not contain a copyright notice
#include "smart_cane_interfaces/msg/detail/detection_result__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `detected_objects`
#include "rosidl_runtime_c/string_functions.h"
// Member `object_positions`
#include "geometry_msgs/msg/detail/point__functions.h"
// Member `confidence_scores`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
smart_cane_interfaces__msg__DetectionResult__init(smart_cane_interfaces__msg__DetectionResult * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    smart_cane_interfaces__msg__DetectionResult__fini(msg);
    return false;
  }
  // detected_objects
  if (!rosidl_runtime_c__String__Sequence__init(&msg->detected_objects, 0)) {
    smart_cane_interfaces__msg__DetectionResult__fini(msg);
    return false;
  }
  // object_positions
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->object_positions, 0)) {
    smart_cane_interfaces__msg__DetectionResult__fini(msg);
    return false;
  }
  // confidence_scores
  if (!rosidl_runtime_c__float__Sequence__init(&msg->confidence_scores, 0)) {
    smart_cane_interfaces__msg__DetectionResult__fini(msg);
    return false;
  }
  return true;
}

void
smart_cane_interfaces__msg__DetectionResult__fini(smart_cane_interfaces__msg__DetectionResult * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // detected_objects
  rosidl_runtime_c__String__Sequence__fini(&msg->detected_objects);
  // object_positions
  geometry_msgs__msg__Point__Sequence__fini(&msg->object_positions);
  // confidence_scores
  rosidl_runtime_c__float__Sequence__fini(&msg->confidence_scores);
}

bool
smart_cane_interfaces__msg__DetectionResult__are_equal(const smart_cane_interfaces__msg__DetectionResult * lhs, const smart_cane_interfaces__msg__DetectionResult * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // detected_objects
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->detected_objects), &(rhs->detected_objects)))
  {
    return false;
  }
  // object_positions
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->object_positions), &(rhs->object_positions)))
  {
    return false;
  }
  // confidence_scores
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->confidence_scores), &(rhs->confidence_scores)))
  {
    return false;
  }
  return true;
}

bool
smart_cane_interfaces__msg__DetectionResult__copy(
  const smart_cane_interfaces__msg__DetectionResult * input,
  smart_cane_interfaces__msg__DetectionResult * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // detected_objects
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->detected_objects), &(output->detected_objects)))
  {
    return false;
  }
  // object_positions
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->object_positions), &(output->object_positions)))
  {
    return false;
  }
  // confidence_scores
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->confidence_scores), &(output->confidence_scores)))
  {
    return false;
  }
  return true;
}

smart_cane_interfaces__msg__DetectionResult *
smart_cane_interfaces__msg__DetectionResult__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  smart_cane_interfaces__msg__DetectionResult * msg = (smart_cane_interfaces__msg__DetectionResult *)allocator.allocate(sizeof(smart_cane_interfaces__msg__DetectionResult), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(smart_cane_interfaces__msg__DetectionResult));
  bool success = smart_cane_interfaces__msg__DetectionResult__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
smart_cane_interfaces__msg__DetectionResult__destroy(smart_cane_interfaces__msg__DetectionResult * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    smart_cane_interfaces__msg__DetectionResult__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
smart_cane_interfaces__msg__DetectionResult__Sequence__init(smart_cane_interfaces__msg__DetectionResult__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  smart_cane_interfaces__msg__DetectionResult * data = NULL;

  if (size) {
    data = (smart_cane_interfaces__msg__DetectionResult *)allocator.zero_allocate(size, sizeof(smart_cane_interfaces__msg__DetectionResult), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = smart_cane_interfaces__msg__DetectionResult__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        smart_cane_interfaces__msg__DetectionResult__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
smart_cane_interfaces__msg__DetectionResult__Sequence__fini(smart_cane_interfaces__msg__DetectionResult__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      smart_cane_interfaces__msg__DetectionResult__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

smart_cane_interfaces__msg__DetectionResult__Sequence *
smart_cane_interfaces__msg__DetectionResult__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  smart_cane_interfaces__msg__DetectionResult__Sequence * array = (smart_cane_interfaces__msg__DetectionResult__Sequence *)allocator.allocate(sizeof(smart_cane_interfaces__msg__DetectionResult__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = smart_cane_interfaces__msg__DetectionResult__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
smart_cane_interfaces__msg__DetectionResult__Sequence__destroy(smart_cane_interfaces__msg__DetectionResult__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    smart_cane_interfaces__msg__DetectionResult__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
smart_cane_interfaces__msg__DetectionResult__Sequence__are_equal(const smart_cane_interfaces__msg__DetectionResult__Sequence * lhs, const smart_cane_interfaces__msg__DetectionResult__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!smart_cane_interfaces__msg__DetectionResult__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
smart_cane_interfaces__msg__DetectionResult__Sequence__copy(
  const smart_cane_interfaces__msg__DetectionResult__Sequence * input,
  smart_cane_interfaces__msg__DetectionResult__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(smart_cane_interfaces__msg__DetectionResult);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    smart_cane_interfaces__msg__DetectionResult * data =
      (smart_cane_interfaces__msg__DetectionResult *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!smart_cane_interfaces__msg__DetectionResult__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          smart_cane_interfaces__msg__DetectionResult__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!smart_cane_interfaces__msg__DetectionResult__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
