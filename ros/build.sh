#!/usr/bin/env bash 

if [ -n "$1" ]; then
    colcon build --packages-select $1 --cmake-args -DPYTHON_EXECUTABLE=/usr/bin/python3
else
    colcon build --cmake-args -DPYTHON_EXECUTABLE=/usr/bin/python3
fi

