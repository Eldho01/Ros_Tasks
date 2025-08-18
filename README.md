## Activity - ROS2 Topics

You’ll create 2 nodes from scratch. In the first one you’ll have 1 publisher, and in the second one, 1 publisher & 1 subscriber.

   1. The number_publisher node publishes a number (always the same) on the “/number” topic, with the existing type example_interfaces/msg/Int64.

   2.  The number_counter node subscribes to the “/number” topic. It keeps a counter variable. Every time a new number is received, it’s added to the counter. The node also has a publisher on the “/number_count” topic. When the counter is updated, the publisher directly publishes the new value on the topic.

    <pre>
    ```bash
    ros2 topic echo /number_count 
    ```
    output:

    ```bash

    data: 38

    ---

    data: 40

    ---

    data: 42

    ---
    ```</pre>