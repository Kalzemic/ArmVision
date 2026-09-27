// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from trajectory:srv/Trajectory.idl
// generated code does not contain a copyright notice
#include "trajectory/srv/detail/trajectory__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `goal`
#include "sensor_msgs/msg/detail/joint_state__functions.h"
// Member `duration`
#include "builtin_interfaces/msg/detail/duration__functions.h"

bool
trajectory__srv__Trajectory_Request__init(trajectory__srv__Trajectory_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal
  if (!sensor_msgs__msg__JointState__init(&msg->goal)) {
    trajectory__srv__Trajectory_Request__fini(msg);
    return false;
  }
  // duration
  if (!builtin_interfaces__msg__Duration__init(&msg->duration)) {
    trajectory__srv__Trajectory_Request__fini(msg);
    return false;
  }
  return true;
}

void
trajectory__srv__Trajectory_Request__fini(trajectory__srv__Trajectory_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal
  sensor_msgs__msg__JointState__fini(&msg->goal);
  // duration
  builtin_interfaces__msg__Duration__fini(&msg->duration);
}

bool
trajectory__srv__Trajectory_Request__are_equal(const trajectory__srv__Trajectory_Request * lhs, const trajectory__srv__Trajectory_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal
  if (!sensor_msgs__msg__JointState__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  // duration
  if (!builtin_interfaces__msg__Duration__are_equal(
      &(lhs->duration), &(rhs->duration)))
  {
    return false;
  }
  return true;
}

bool
trajectory__srv__Trajectory_Request__copy(
  const trajectory__srv__Trajectory_Request * input,
  trajectory__srv__Trajectory_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal
  if (!sensor_msgs__msg__JointState__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  // duration
  if (!builtin_interfaces__msg__Duration__copy(
      &(input->duration), &(output->duration)))
  {
    return false;
  }
  return true;
}

trajectory__srv__Trajectory_Request *
trajectory__srv__Trajectory_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trajectory__srv__Trajectory_Request * msg = (trajectory__srv__Trajectory_Request *)allocator.allocate(sizeof(trajectory__srv__Trajectory_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trajectory__srv__Trajectory_Request));
  bool success = trajectory__srv__Trajectory_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
trajectory__srv__Trajectory_Request__destroy(trajectory__srv__Trajectory_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    trajectory__srv__Trajectory_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
trajectory__srv__Trajectory_Request__Sequence__init(trajectory__srv__Trajectory_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trajectory__srv__Trajectory_Request * data = NULL;

  if (size) {
    data = (trajectory__srv__Trajectory_Request *)allocator.zero_allocate(size, sizeof(trajectory__srv__Trajectory_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trajectory__srv__Trajectory_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trajectory__srv__Trajectory_Request__fini(&data[i - 1]);
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
trajectory__srv__Trajectory_Request__Sequence__fini(trajectory__srv__Trajectory_Request__Sequence * array)
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
      trajectory__srv__Trajectory_Request__fini(&array->data[i]);
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

trajectory__srv__Trajectory_Request__Sequence *
trajectory__srv__Trajectory_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trajectory__srv__Trajectory_Request__Sequence * array = (trajectory__srv__Trajectory_Request__Sequence *)allocator.allocate(sizeof(trajectory__srv__Trajectory_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = trajectory__srv__Trajectory_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
trajectory__srv__Trajectory_Request__Sequence__destroy(trajectory__srv__Trajectory_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    trajectory__srv__Trajectory_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
trajectory__srv__Trajectory_Request__Sequence__are_equal(const trajectory__srv__Trajectory_Request__Sequence * lhs, const trajectory__srv__Trajectory_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!trajectory__srv__Trajectory_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
trajectory__srv__Trajectory_Request__Sequence__copy(
  const trajectory__srv__Trajectory_Request__Sequence * input,
  trajectory__srv__Trajectory_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(trajectory__srv__Trajectory_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    trajectory__srv__Trajectory_Request * data =
      (trajectory__srv__Trajectory_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!trajectory__srv__Trajectory_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          trajectory__srv__Trajectory_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!trajectory__srv__Trajectory_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `trajectory`
#include "trajectory_msgs/msg/detail/joint_trajectory__functions.h"

bool
trajectory__srv__Trajectory_Response__init(trajectory__srv__Trajectory_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // trajectory
  if (!trajectory_msgs__msg__JointTrajectory__init(&msg->trajectory)) {
    trajectory__srv__Trajectory_Response__fini(msg);
    return false;
  }
  return true;
}

void
trajectory__srv__Trajectory_Response__fini(trajectory__srv__Trajectory_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // trajectory
  trajectory_msgs__msg__JointTrajectory__fini(&msg->trajectory);
}

bool
trajectory__srv__Trajectory_Response__are_equal(const trajectory__srv__Trajectory_Response * lhs, const trajectory__srv__Trajectory_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // trajectory
  if (!trajectory_msgs__msg__JointTrajectory__are_equal(
      &(lhs->trajectory), &(rhs->trajectory)))
  {
    return false;
  }
  return true;
}

bool
trajectory__srv__Trajectory_Response__copy(
  const trajectory__srv__Trajectory_Response * input,
  trajectory__srv__Trajectory_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // trajectory
  if (!trajectory_msgs__msg__JointTrajectory__copy(
      &(input->trajectory), &(output->trajectory)))
  {
    return false;
  }
  return true;
}

trajectory__srv__Trajectory_Response *
trajectory__srv__Trajectory_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trajectory__srv__Trajectory_Response * msg = (trajectory__srv__Trajectory_Response *)allocator.allocate(sizeof(trajectory__srv__Trajectory_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trajectory__srv__Trajectory_Response));
  bool success = trajectory__srv__Trajectory_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
trajectory__srv__Trajectory_Response__destroy(trajectory__srv__Trajectory_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    trajectory__srv__Trajectory_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
trajectory__srv__Trajectory_Response__Sequence__init(trajectory__srv__Trajectory_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trajectory__srv__Trajectory_Response * data = NULL;

  if (size) {
    data = (trajectory__srv__Trajectory_Response *)allocator.zero_allocate(size, sizeof(trajectory__srv__Trajectory_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trajectory__srv__Trajectory_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trajectory__srv__Trajectory_Response__fini(&data[i - 1]);
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
trajectory__srv__Trajectory_Response__Sequence__fini(trajectory__srv__Trajectory_Response__Sequence * array)
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
      trajectory__srv__Trajectory_Response__fini(&array->data[i]);
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

trajectory__srv__Trajectory_Response__Sequence *
trajectory__srv__Trajectory_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trajectory__srv__Trajectory_Response__Sequence * array = (trajectory__srv__Trajectory_Response__Sequence *)allocator.allocate(sizeof(trajectory__srv__Trajectory_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = trajectory__srv__Trajectory_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
trajectory__srv__Trajectory_Response__Sequence__destroy(trajectory__srv__Trajectory_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    trajectory__srv__Trajectory_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
trajectory__srv__Trajectory_Response__Sequence__are_equal(const trajectory__srv__Trajectory_Response__Sequence * lhs, const trajectory__srv__Trajectory_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!trajectory__srv__Trajectory_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
trajectory__srv__Trajectory_Response__Sequence__copy(
  const trajectory__srv__Trajectory_Response__Sequence * input,
  trajectory__srv__Trajectory_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(trajectory__srv__Trajectory_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    trajectory__srv__Trajectory_Response * data =
      (trajectory__srv__Trajectory_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!trajectory__srv__Trajectory_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          trajectory__srv__Trajectory_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!trajectory__srv__Trajectory_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
