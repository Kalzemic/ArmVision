from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from launch.actions import DeclareLaunchArgument
from launch.substitutions import Command, LaunchConfiguration
from launch_ros.parameter_descriptions import ParameterValue  
import os


def generate_launch_description():

    model_arg = DeclareLaunchArgument(
        name='model',
        default_value=os.path.join(get_package_share_directory('armvision_description'),'urdf','armvision.urdf.xacro'),
        description='absolute path to the robot urdf file'
    )

    robot_description = ParameterValue(Command(['xacro ',LaunchConfiguration('model')]), value_type=str)

    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[{'robot_description': robot_description}]
    )

    kinematics = Node(
        package='kinematics',
        executable='kinematics_node',
        parameters=[{
            'robot_description': robot_description,
            'end_effector': 'end_effector',
            'ik.max_iterations': 100,
            'ik.epsilon': 1e-4,
            'ik.step_size': 0.5,
            'ik.damping': 1e-3,
        }]
    )

    trajectory = Node(
        package='trajectory',
        executable='trajectory_node',
        parameters=[{
            'trajectory.duration': 2.0,
            'frequency': 1000.0,
        }]
    )

    controller_config = os.path.join(get_package_share_directory('robo_controller'),'config','robo_controller.yaml')
    controller_manager = Node(
        package='controller_manager',
        executable='ros2_control_node',
        parameters=[
            {'robot_description':robot_description},
            controller_config
        ]
    )

    joint_state_broadcaster_spawner = Node(
        package='controller_manager',
        executable='spawner',
        arguments=['joint_state_broadcaster','--controller-manager','/controller_manager']
    )

    robo_controller_spawner = Node(
        package='controller_manager',
        executable='spawner',
        arguments=['robo_controller', '--controller-manager','/controller_manager']
    )

    return LaunchDescription([
        model_arg,
        robot_state_publisher,
        kinematics,
        trajectory,
        controller_manager,
        joint_state_broadcaster_spawner,
        robo_controller_spawner
    ])