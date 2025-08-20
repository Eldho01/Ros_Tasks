
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    ld = LaunchDescription()
    
    new_station = Node(
        package="ros_learning_cpp",
        executable="news_station"
    )
    
    receiver_station = Node(
        package="ros_learning_pkg",
        executable="smart_phone",
        name="receiver_station"
    )
    
    ld.add_action(new_station)
    ld.add_action(receiver_station)
    return ld