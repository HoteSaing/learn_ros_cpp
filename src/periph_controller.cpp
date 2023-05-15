#include "periph_controller/periph_controller.hpp"

// byte byte_array[5];

Controller::Controller(ros::NodeHandle *nh) : nh_(nh) {
  extend_basket_srv_ =
      nh_->advertiseService("/extend_basket", &Controller::ExtendBasket, this);
  retract_basket_srv_ = nh_->advertiseService("/retract_basket",
                                              &Controller::RetractBasket, this);

  activate_pump_srv_ =
      nh_->advertiseService("/activate_pump", &Controller::ActivatePump, this);
  deactivate_pump_srv_ = nh_->advertiseService("/deactivate_pump",
                                              &Controller::DeactivatePump, this);
  ROS_INFO("Peripheral Controller services initialised");

  ROS_INFO("Configure serial");
  try
		{
			ser_handle.setPort("/dev/ttyUSB0");
			ser_handle.setBaudrate(9600);
			serial::Timeout to = serial::Timeout::simpleTimeout(1000);
			ser_handle.setTimeout(to);
			ser_handle.open();
		}
		catch (serial::IOException &e)
		{
			ROS_INFO("Unable to open port\n");
		}
		if (ser_handle.isOpen())
		{
			ROS_INFO("Port initialized\n");
		}
}

void Controller::Run() {
  ros::Rate rate_loop(10);
  ros::spin();
}

bool Controller::ExtendBasket(periph_controller::ExtendBasket::Request &req,
                              periph_controller::ExtendBasket::Response &res) {
  const uint8_t byte_array[5] = {0x75, 0x74, 0x32, 0x00, 0x32};
  ser_handle.write(byte_array, 5);
  res.success = true;
  return true;
}
bool Controller::RetractBasket(
    periph_controller::RetractBasket::Request &req,
    periph_controller::RetractBasket::Response &res) {
  const uint8_t byte_array[5] = {0x75, 0x74, 0x32, 0x01, 0x33};
  ser_handle.write(byte_array, 5);
  res.success = true;
  return true;
}

bool Controller::ActivatePump(periph_controller::ActivatePump::Request &req,
                              periph_controller::ActivatePump::Response &res) {
  const uint8_t byte_array[5] = {0x75, 0x74, 0x30, 0x7F, 0x4F};
  ser_handle.write(byte_array, 5);
  res.success = true;
  return true;
}

bool Controller::DeactivatePump(
    periph_controller::DeactivatePump::Request &req,
    periph_controller::DeactivatePump::Response &res) {
  const uint8_t byte_array[5] = {0x75, 0x74, 0x30, 0x00, 0x30};
  ser_handle.write(byte_array, 5);
  res.success = true;
  return true;
}