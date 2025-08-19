#!/usr/bin python3

import rclpy
from rclpy.node import Node

from example_interfaces.srv import AddTwoInts

# python import not ros based so no need to add in package.xml
from functools import partial

class AddTwoIntsClient(Node):
    def __init__(self):
        super().__init__("Add_Two_Ints_client")
        self.call_add_two_ints_server()
        self.get_logger().info("AddTwoInts client service started...")
        
    def call_add_two_ints_server(self):
        client = self.create_client(AddTwoInts,"the_addition_of_twoInts")
        while not client.wait_for_service(1.0):
            self.get_logger().warn("waiting for Server ...")
            
        request = AddTwoInts.Request()
        request.a = int(input("enter a: "))
        request.b = int(input("enter b: "))
        a = request.a
        b = request.b
        
        future = client.call_async(request)
        future.add_done_callback(partial(self.callback_call_add_two_ints,
                                         a=a, b=b))
        
    def callback_call_add_two_ints(self, future, a, b):
        try:
            response = future.result()
            self.get_logger().info(f"sum of {a}, {b}= {response.sum}")
            
        except Exception as e:
            self.get_logger().error("service call failed...\n",e)
        
        
def main(args= None):
    
    rclpy.init(args=args)
    # node = Node("Add_Two_Ints_client")
    # client = node.create_client(AddTwoInts,"the_addition_of_twoInts")
    # while not client.wait_for_service(1.0):
    #     node.get_logger().warn("waiting for Server ...")
        
    # request = AddTwoInts.Request()
    # request.a = int(input("enter a: "))
    # request.b = int(input("enter b: "))
    
    # future = client.call_async(request)
    # rclpy.spin_until_future_complete(node, future)
    
    # try:
    #     response = future.result()
    #     node.get_logger().info(f"sum of {request.a}, { request.b }= {response.sum}")
        
    # except Exception as e:
    #     node.get_logger().error("service call failed...")
    node = AddTwoIntsClient()
    rclpy.spin(node)
    rclpy.shutdown()
    
    
if __name__ == "__main__":
    main()