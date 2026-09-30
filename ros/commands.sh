#!/usr/bin/env bash 

cmd=$1

source ./install/setup.bash

case "$cmd" in

reset)
    ros2 action send_goal /move_to_pose motion_executor/action/MoveToPose \
    "{target: {header: {frame_id: ''}, pose: {position: {x: -0.11, y: 0.786, z: 1.320}, orientation: {w: 1.0}}}, position_only: true}"
    ;;
drop)
    ros2 action send_goal /move_to_pose motion_executor/action/MoveToPose \
    "{target: {header: {frame_id: ''}, pose: {position: {x: -0.11, y: 0.786, z: 0.520}, orientation: {w: 1.0}}}, position_only: true}"
    ;;
spin)
    ros2 action send_goal /move_to_pose motion_executor/action/MoveToPose \
    "{target: {header: {frame_id: ''}, pose: {position: {x: 1.4, y: 0.786, z: 1.320}, orientation: {w: 1.0}}}, position_only: true}"
    ;;
*)
    ;;

esac