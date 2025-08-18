#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"

class NumberCounter: public rclcpp::Node{

    public:
    NumberCounter():Node("number_counter"), num_counter_(0){
        publisher_ = this->create_publisher<std_msgs::msg::Int64>("number_count",10);

        subscriber_ = this->create_subscription<std_msgs::msg::Int64>("number", 10,
                            std::bind(&NumberCounter::callback_new_num, this,
                                std::placeholders::_1));

        timer_ = this->create_wall_timer(std::chrono::seconds(1),
                        std::bind(&NumberCounter::sub_pub_count, this));

        RCLCPP_INFO(this->get_logger(),"started Publisher and subscriber node ...");

    }
    private:
    void callback_new_num(const std_msgs::msg::Int64::SharedPtr msg){
        num_counter_++;
        RCLCPP_INFO(this->get_logger(),"%ld",msg->data);
    }

    void sub_pub_count(){
        auto msg = std_msgs::msg::Int64();
        msg.data = num_counter_;
        publisher_->publish(msg);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Subscription<std_msgs::msg::Int64>::SharedPtr subscriber_;
    rclcpp::Publisher<std_msgs::msg::Int64>::SharedPtr publisher_;
    int num_counter_;


};

int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumberCounter>();
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}