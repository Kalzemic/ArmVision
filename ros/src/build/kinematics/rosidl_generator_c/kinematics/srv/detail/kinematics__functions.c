// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from kinematics:srv/Kinematics.idl
// generated code does not contain a copyright notice
#include "kinematics/srv/detail/kinematics__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `target`
#include "geometry_msgs/msg/detail/pose_stamped__functions.h"

bool
kinematics__srv__Kinematics_Request__init(kinematics__srv__Kinematics_Request * msg)
{
  if (!msg) {
    return false;
  }
  // target
  if (!geometry_msgs__msg__PoseStamped__init(&msg->target)) {
    kinematics__srv__Kinematics_Request__fini(msg);
    return false;
  }
  return true;
}

void
kinematics__srv__Kinematics_Request__fini(kinematics__srv__Kinematics_Request * msg)
{
  if (!msg) {
    return;
  }
  // target
  geometry_msgs__msg__PoseStamped__fini(&msg->target);
}

bool
kinematics__srv__Kinematics_Request__are_equal(const kinematics__srv__Kinematics_Request * lhs, const kinematics__srv__Kinematics_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // target
  if (!geometry_msgs__msg__PoseStamped__are_equal(
      &(lhs->target), &(rhs->target)))
  {
    return false;
  }
  return true;
}

bool
kinematics__srv__Kinematics_Request__copy(
  const kinematics__srv__Kinematics_Request * input,
  kinematics__srv__Kinematics_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // target
  if (!geometry_msgs__msg__PoseStamped__copy(
      &(input->target), &(output->target)))
  {
    return false;
  }
  return true;
}

kinematics__srv__Kinematics_Request *
kinematics__srv__Kinematics_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinematics__srv__Kinematics_Request * msg = (kinematics__srv__Kinematics_Request *)allocator.allocate(sizeof(kinematics__srv__Kinematics_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kinematics__srv__Kinematics_Request));
  bool success = kinematics__srv__Kinematics_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kinematics__srv__Kinematics_Request__destroy(kinematics__srv__Kinematics_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kinematics__srv__Kinematics_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kinematics__srv__Kinematics_Request__Sequence__init(kinematics__srv__Kinematics_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinematics__srv__Kinematics_Request * data = NULL;

  if (size) {
    data = (kinematics__srv__Kinematics_Request *)allocator.zero_allocate(size, sizeof(kinematics__srv__Kinematics_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kinematics__srv__Kinematics_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kinematics__srv__Kinematics_Request__fini(&data[i - 1]);
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
kinematics__srv__Kinematics_Request__Sequence__fini(kinematics__srv__Kinematics_Request__Sequence * array)
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
      kinematics__srv__Kinematics_Request__fini(&array->data[i]);
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

kinematics__srv__Kinematics_Request__Sequence *
kinematics__srv__Kinematics_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinematics__srv__Kinematics_Request__Sequence * array = (kinematics__srv__Kinematics_Request__Sequence *)allocator.allocate(sizeof(kinematics__srv__Kinematics_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kinematics__srv__Kinematics_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kinematics__srv__Kinematics_Request__Sequence__destroy(kinematics__srv__Kinematics_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kinematics__srv__Kinematics_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kinematics__srv__Kinematics_Request__Sequence__are_equal(const kinematics__srv__Kinematics_Request__Sequence * lhs, const kinematics__srv__Kinematics_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kinematics__srv__Kinematics_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kinematics__srv__Kinematics_Request__Sequence__copy(
  const kinematics__srv__Kinematics_Request__Sequence * input,
  kinematics__srv__Kinematics_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kinematics__srv__Kinematics_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    kinematics__srv__Kinematics_Request * data =
      (kinematics__srv__Kinematics_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kinematics__srv__Kinematics_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          kinematics__srv__Kinematics_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!kinematics__srv__Kinematics_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `solution`
#include "sensor_msgs/msg/detail/joint_state__functions.h"

bool
kinematics__srv__Kinematics_Response__init(kinematics__srv__Kinematics_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // solution
  if (!sensor_msgs__msg__JointState__init(&msg->solution)) {
    kinematics__srv__Kinematics_Response__fini(msg);
    return false;
  }
  return true;
}

void
kinematics__srv__Kinematics_Response__fini(kinematics__srv__Kinematics_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // solution
  sensor_msgs__msg__JointState__fini(&msg->solution);
}

bool
kinematics__srv__Kinematics_Response__are_equal(const kinematics__srv__Kinematics_Response * lhs, const kinematics__srv__Kinematics_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // solution
  if (!sensor_msgs__msg__JointState__are_equal(
      &(lhs->solution), &(rhs->solution)))
  {
    return false;
  }
  return true;
}

bool
kinematics__srv__Kinematics_Response__copy(
  const kinematics__srv__Kinematics_Response * input,
  kinematics__srv__Kinematics_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // solution
  if (!sensor_msgs__msg__JointState__copy(
      &(input->solution), &(output->solution)))
  {
    return false;
  }
  return true;
}

kinematics__srv__Kinematics_Response *
kinematics__srv__Kinematics_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinematics__srv__Kinematics_Response * msg = (kinematics__srv__Kinematics_Response *)allocator.allocate(sizeof(kinematics__srv__Kinematics_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kinematics__srv__Kinematics_Response));
  bool success = kinematics__srv__Kinematics_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kinematics__srv__Kinematics_Response__destroy(kinematics__srv__Kinematics_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kinematics__srv__Kinematics_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kinematics__srv__Kinematics_Response__Sequence__init(kinematics__srv__Kinematics_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinematics__srv__Kinematics_Response * data = NULL;

  if (size) {
    data = (kinematics__srv__Kinematics_Response *)allocator.zero_allocate(size, sizeof(kinematics__srv__Kinematics_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kinematics__srv__Kinematics_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kinematics__srv__Kinematics_Response__fini(&data[i - 1]);
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
kinematics__srv__Kinematics_Response__Sequence__fini(kinematics__srv__Kinematics_Response__Sequence * array)
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
      kinematics__srv__Kinematics_Response__fini(&array->data[i]);
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

kinematics__srv__Kinematics_Response__Sequence *
kinematics__srv__Kinematics_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinematics__srv__Kinematics_Response__Sequence * array = (kinematics__srv__Kinematics_Response__Sequence *)allocator.allocate(sizeof(kinematics__srv__Kinematics_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kinematics__srv__Kinematics_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kinematics__srv__Kinematics_Response__Sequence__destroy(kinematics__srv__Kinematics_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kinematics__srv__Kinematics_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kinematics__srv__Kinematics_Response__Sequence__are_equal(const kinematics__srv__Kinematics_Response__Sequence * lhs, const kinematics__srv__Kinematics_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kinematics__srv__Kinematics_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kinematics__srv__Kinematics_Response__Sequence__copy(
  const kinematics__srv__Kinematics_Response__Sequence * input,
  kinematics__srv__Kinematics_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kinematics__srv__Kinematics_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    kinematics__srv__Kinematics_Response * data =
      (kinematics__srv__Kinematics_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kinematics__srv__Kinematics_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          kinematics__srv__Kinematics_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!kinematics__srv__Kinematics_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
