#!/bin/bash

# Exit on error
set -e

# Install required dependencies
sudo apt install -y software-properties-common

# Enable universe repository
sudo add-apt-repository universe

# Update package list and install curl
sudo apt update && sudo apt install -y curl

# Add ROS 2 key
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg

# Add ROS 2 repository
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null

# Update package list and upgrade the system
sudo apt update && sudo apt upgrade -y

# Install ROS 2 Humble Desktop
sudo apt install -y ros-humble-desktop

# Print success message
echo "ROS 2 Humble installation completed successfully!"

