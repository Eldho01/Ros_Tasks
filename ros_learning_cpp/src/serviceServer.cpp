#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

using std::placeholders::_1;
using std::placeholders::_2;


class AddTwoInts_server: public rclcpp::Node{
    public:
    AddTwoInts_server():Node("Add_Two_Ints"){
        server_ = this->create_service<example_interfaces::srv::AddTwoInts>("the_addition_of_twoInts",
                    std::bind(&AddTwoInts_server::callback_addition_of_TwoInsts, this, _1, _2)); // service name, callbackfuc
        RCLCPP_INFO(this->get_logger(),"Add_Two_ints started...");

    }
    private:
    void callback_addition_of_TwoInsts(const example_interfaces::srv::AddTwoInts::Request::SharedPtr request,
                            const example_interfaces::srv::AddTwoInts::Response::SharedPtr response){
        response->sum = request->a +request->b;
        RCLCPP_INFO(this->get_logger(),"sum of %ld and %ld = %ld",request->a, request->b,response->sum);
            }
            
    rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr server_;

};



int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<AddTwoInts_server>();
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}