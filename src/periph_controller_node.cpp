#include "periph_controller/periph_controller.hpp"

int main(int argc, char ** argv) {
    ros::init(argc, argv,"controller");
    ros::NodeHandle nh;
    Controller controller(&nh);
    controller.Run();
    return 0;
}