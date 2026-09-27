# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target trajectory::trajectory
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${trajectory_TARGETS}.
if(trajectory_TARGETS AND NOT TARGET trajectory::trajectory)
  add_library(trajectory::trajectory INTERFACE IMPORTED)
  set_target_properties(trajectory::trajectory PROPERTIES
    INTERFACE_LINK_LIBRARIES "${trajectory_TARGETS}")
endif()
