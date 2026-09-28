import os
from pathlib import Path
from launch import LaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument, SetEnvironmentVariable, IncludeLaunchDescription
from ament_index_python.packages import get_package_share_directory
from launch.substitutions import Command, LaunchConfiguration
from launch_ros.parameter_descriptions import ParameterValue  
from launch.actions import TimerAction

def generate_launch_description():

    armvision_description_dir = get_package_share_directory('armvision_description')
    model_arg = DeclareLaunchArgument(
        name='model',
        default_value=os.path.join(armvision_description_dir,'urdf','armvision.urdf.xacro'),
        description='absolute path to the robot urdf file'
        )

    gazebo_resource_path = SetEnvironmentVariable(
        name='GZ_SIM_RESOURCE_PATH',
        value=[
            str(Path(armvision_description_dir).parent.resolve())
        ]
    )

    ros_distro = os.environ['ROS_DISTRO']
    is_ignition = 'True' if ros_distro == 'humble' else 'False'
    physics_engine = '' if ros_distro == 'humble' else '--physics-engine gz-physics-bullet-featherstone-plugin'
    
    robot_description = ParameterValue(Command([
        'xacro ',
        LaunchConfiguration('model'),
        " is_ignition:=",
        is_ignition
        ]))

    
    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[{'robot_description': robot_description, 'use_sim_time': True}]
    )

    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(
            get_package_share_directory('ros_gz_sim'),'launch'
        ),'/gz_sim.launch.py']),
        launch_arguments=[
            ('gz_args',[' -v 4 -r empty.sdf', physics_engine])
        ]
    )

    gz_spawn_entity = Node(
        package='ros_gz_sim',
        executable='create',
        output='screen',
        arguments=['-topic', 'robot_description', '-name', 'armvision']
    )

    delayed_spawn = TimerAction(period=3.0, actions=[gz_spawn_entity])

    gz_ros2_bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=['/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock',
                   '/image_raw@sensor_msgs/msg/Image[gz.msgs.Image',
                    '/camera_info@sensor_msgs/msg/CameraInfo[gz.msgs.CameraInfo'
                ]
    )




    return LaunchDescription([
        model_arg,
        gazebo_resource_path, 
        robot_state_publisher, 
        gazebo,
        delayed_spawn, 
        gz_ros2_bridge
    ])
