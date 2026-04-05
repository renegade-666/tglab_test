echo "Entering workspace"
cd dev_ws
echo "Sourcing ROS 2 environment"
source /opt/ros/dashing/setup.bash
echo "Sourcing the overlay"
. install/setup.bash
echo "Launching gps node..."
ros2 run py_pubsub gps_node __params:=./gps_node.yaml
