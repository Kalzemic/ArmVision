# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target kinematics::kinematics
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${kinematics_TARGETS}.
if(kinematics_TARGETS AND NOT TARGET kinematics::kinematics)
  add_library(kinematics::kinematics INTERFACE IMPORTED)
  set_target_properties(kinematics::kinematics PROPERTIES
    INTERFACE_LINK_LIBRARIES "${kinematics_TARGETS}")
endif()
