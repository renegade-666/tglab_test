current_dir=$(pwd)
cd /opt/ros
dirs=(*/)

cd $current_dir
echo "Entering workspace"
cd dev_ws
echo "Sourcing ROS 2 environment"
setup_path="/opt/ros/"
setup_path+="${dirs[0]}"
setup_path+="setup.bash"
source $setup_path
echo "Sourcing overlay environment"
. install/setup.bash
echo "Launching gps node..."
ros2 run py_pubsub gps_node __params:=./gps_node.yaml
