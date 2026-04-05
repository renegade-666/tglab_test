# Copyright 2016 Open Source Robotics Foundation, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import rclpy
from rclpy.node import Node
from rclpy.exceptions import ParameterNotDeclaredException
from rcl_interfaces.msg import ParameterType

from interface.msg import GpsPosition

import serial
from py_pubsub.uart_gps import init, shutdown, loop, dumb_parse

class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('gps_node')
        self.declare_parameter('port', '/dev/ttyUSB0')
        self.publisher_ = self.create_publisher(GpsPosition, '/gps_position', 10)
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        init(self.get_parameter('port').get_parameter_value().string_value)

    def timer_callback(self):
        gps_data, error = loop()
        if not gps_data:
            self.get_logger().info('Error: "%s"' % error)
        else:
            latitude, latitude_type, longitude, longitude_type, num_satellites = gps_data
            msg = GpsPosition()
            msg.latitude = -latitude if latitude_type == "S" else latitude;
            msg.longitude = -longitude if longitude_type == "W" else longitude;
            msg.satellites = num_satellites
            self.publisher_.publish(msg)
            self.get_logger().info('Publishing...')

    def __del__(self):
        shutdown()

def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
