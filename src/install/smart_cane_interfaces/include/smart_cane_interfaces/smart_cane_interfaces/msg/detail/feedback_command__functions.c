// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from smart_cane_interfaces:msg/FeedbackCommand.idl
// generated code does not contain a copyright notice
#include "smart_cane_interfaces/msg/detail/feedback_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `message_text`
#include "rosidl_runtime_c/string_functions.h"

bool
smart_cane_interfaces__msg__FeedbackCommand__init(smart_cane_interfaces__msg__FeedbackCommand * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    smart_cane_interfaces__msg__FeedbackCommand__fini(msg);
    return false;
  }
  // message_text
  if (!rosidl_runtime_c__String__init(&msg->message_text)) {
    smart_cane_interfaces__msg__FeedbackCommand__fini(msg);
    return false;
  }
  // vibration_enabled
  // vibration_intensity
  // audio_enabled
  return true;
}

void
smart_cane_interfaces__msg__FeedbackCommand__fini(smart_cane_interfaces__msg__FeedbackCommand * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // message_text
  rosidl_runtime_c__String__fini(&msg->message_text);
  // vibration_enabled
  // vibration_intensity
  // audio_enabled
}

bool
smart_cane_interfaces__msg__FeedbackCommand__are_equal(const smart_cane_interfaces__msg__FeedbackCommand * lhs, const smart_cane_interfaces__msg__FeedbackCommand * rhs)
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
  // message_text
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message_text), &(rhs->message_text)))
  {
    return false;
  }
  // vibration_enabled
  if (lhs->vibration_enabled != rhs->vibration_enabled) {
    return false;
  }
  // vibration_intensity
  if (lhs->vibration_intensity != rhs->vibration_intensity) {
    return false;
  }
  // audio_enabled
  if (lhs->audio_enabled != rhs->audio_enabled) {
    return false;
  }
  return true;
}

bool
smart_cane_interfaces__msg__FeedbackCommand__copy(
  const smart_cane_interfaces__msg__FeedbackCommand * input,
  smart_cane_interfaces__msg__FeedbackCommand * output)
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
  // message_text
  if (!rosidl_runtime_c__String__copy(
      &(input->message_text), &(output->message_text)))
  {
    return false;
  }
  // vibration_enabled
  output->vibration_enabled = input->vibration_enabled;
  // vibration_intensity
  output->vibration_intensity = input->vibration_intensity;
  // audio_enabled
  output->audio_enabled = input->audio_enabled;
  return true;
}

smart_cane_interfaces__msg__FeedbackCommand *
smart_cane_interfaces__msg__FeedbackCommand__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  smart_cane_interfaces__msg__FeedbackCommand * msg = (smart_cane_interfaces__msg__FeedbackCommand *)allocator.allocate(sizeof(smart_cane_interfaces__msg__FeedbackCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(smart_cane_interfaces__msg__FeedbackCommand));
  bool success = smart_cane_interfaces__msg__FeedbackCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
smart_cane_interfaces__msg__FeedbackCommand__destroy(smart_cane_interfaces__msg__FeedbackCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    smart_cane_interfaces__msg__FeedbackCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
smart_cane_interfaces__msg__FeedbackCommand__Sequence__init(smart_cane_interfaces__msg__FeedbackCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  smart_cane_interfaces__msg__FeedbackCommand * data = NULL;

  if (size) {
    data = (smart_cane_interfaces__msg__FeedbackCommand *)allocator.zero_allocate(size, sizeof(smart_cane_interfaces__msg__FeedbackCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = smart_cane_interfaces__msg__FeedbackCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        smart_cane_interfaces__msg__FeedbackCommand__fini(&data[i - 1]);
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
smart_cane_interfaces__msg__FeedbackCommand__Sequence__fini(smart_cane_interfaces__msg__FeedbackCommand__Sequence * array)
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
      smart_cane_interfaces__msg__FeedbackCommand__fini(&array->data[i]);
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

smart_cane_interfaces__msg__FeedbackCommand__Sequence *
smart_cane_interfaces__msg__FeedbackCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  smart_cane_interfaces__msg__FeedbackCommand__Sequence * array = (smart_cane_interfaces__msg__FeedbackCommand__Sequence *)allocator.allocate(sizeof(smart_cane_interfaces__msg__FeedbackCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = smart_cane_interfaces__msg__FeedbackCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
smart_cane_interfaces__msg__FeedbackCommand__Sequence__destroy(smart_cane_interfaces__msg__FeedbackCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    smart_cane_interfaces__msg__FeedbackCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
smart_cane_interfaces__msg__FeedbackCommand__Sequence__are_equal(const smart_cane_interfaces__msg__FeedbackCommand__Sequence * lhs, const smart_cane_interfaces__msg__FeedbackCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!smart_cane_interfaces__msg__FeedbackCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
smart_cane_interfaces__msg__FeedbackCommand__Sequence__copy(
  const smart_cane_interfaces__msg__FeedbackCommand__Sequence * input,
  smart_cane_interfaces__msg__FeedbackCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(smart_cane_interfaces__msg__FeedbackCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    smart_cane_interfaces__msg__FeedbackCommand * data =
      (smart_cane_interfaces__msg__FeedbackCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!smart_cane_interfaces__msg__FeedbackCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          smart_cane_interfaces__msg__FeedbackCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!smart_cane_interfaces__msg__FeedbackCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
