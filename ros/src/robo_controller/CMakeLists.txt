cmake_minimum_required(VERSION 3.8)
project(robo_controller)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)

find_package(controller_interface REQUIRED)
find_package(hardware_interface REQUIRED)
find_package(pluginlib REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_lifecycle REQUIRED)
find_package(trajectory_msgs REQUIRED)
find_package(realtime_tools REQUIRED)

find_package(Eigen3 REQUIRED)
find_package(pinocchio REQUIRED)

add_library(robo_controller SHARED
    src/robo_controller.cpp
)

ament_target_dependencies(robo_controller
    controller_interface
    hardware_interface
    pluginlib
    rclcpp
    rclcpp_lifecycle
    trajectory_msgs
    realtime_tools
)

target_link_libraries(robo_controller
    Eigen3::Eigen
    pinocchio::pinocchio
)

pluginlib_export_plugin_description_file(
    controller_interface
    robo_controller.xml
)

install(
    TARGETS robo_controller
    LIBRARY DESTINATION lib
)

install(
    FILES robo_controller.xml
    DESTINATION share/${PROJECT_NAME}
)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
