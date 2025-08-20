#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"
#include "std_srvs/srv/set_bool.hpp"


using std::placeholders::_1;
using std::placeholders::_2;

class NumberCounter: public rclcpp::Node{

    public:
    NumberCounter():Node("number_counter"), num_counter_(0){
        publisher_ = this->create_publisher<std_msgs::msg::Int64>("number_count",10);

        subscriber_ = this->create_subscription<std_msgs::msg::Int64>("number", 10,
                            std::bind(&NumberCounter::callback_new_num, this,
                                std::placeholders::_1));
        server_   = this->create_service<std_srvs::srv::SetBool>("the_conter_reset",
                                std::bind(&NumberCounter::callback_conuter_reset,this, _1, _2));

        // timer_ = this->create_wall_timer(std::chrono::seconds(1),
        //                 std::bind(&NumberCounter::sub_pub_count, this));

        RCLCPP_INFO(this->get_logger(),"started Publisher and subscriber node ...");

    }
    private:
    void callback_new_num(const std_msgs::msg::Int64::SharedPtr msg){
        num_counter_++;
        RCLCPP_INFO(this->get_logger(),"%ld",msg->data);
        sub_pub_count();
    }

    void sub_pub_count(){
        auto msg = std_msgs::msg::Int64();
        msg.data = num_counter_;
        publisher_->publish(msg);
    }

    void callback_conuter_reset(const std_srvs::srv::SetBool::Request::SharedPtr request,
                            const std_srvs::srv::SetBool::Response::SharedPtr response){
                    
        if (request->data){
            num_counter_ = 0;
            RCLCPP_INFO(this->get_logger(), "conter reset to zero...");
            response->success = true;
            response->message = "Counter reset complete...";
        }
        else{
            RCLCPP_WARN(this->get_logger(),"reset command received as false...");
        }
    }

    // rclcpp::TimerBase::SharedPtr timer_; 
    rclcpp::Subscription<std_msgs::msg::Int64>::SharedPtr subscriber_;
    rclcpp::Publisher<std_msgs::msg::Int64>::SharedPtr publisher_;
    rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr server_;
    int num_counter_;


};

int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumberCounter>();
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}