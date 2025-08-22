
## Activity - ROS2 Topics

You’ll create 2 nodes from scratch. In the first one you’ll have 1 publisher, and in the second one, 1 publisher & 1 subscriber.

   1. The number_publisher node publishes a number (always the same) on the “/number” topic, with the existing type example_interfaces/msg/Int64.

   2.  The number_counter node subscribes to the “/number” topic. It keeps a counter variable. Every time a new number is received, it’s added to the counter. The node also has a publisher on the “/number_count” topic. When the counter is updated, the publisher directly publishes the new value on the topic.

    ros2 topic echo /number_count 
    
   output:


    data: 38

    ---

    data: 40

    ---

    data: 42

    ---

## Activity - ROS2 Service

Add a functionality to reset the counter to zero:

   1. Create a service server inside the “number_counter” node.

   2. Service name: “/the_conter_reset ”

   3. Service type: std_srvs/srv/SetBool. Use “ros2 interface show” to discover what’s inside!

   4. When the server is called, you check the boolean data from the request. If true, you set the counter variable to 0.