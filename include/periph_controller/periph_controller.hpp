#ifndef PERIPH_CONTROLLER_PERIPH_CONTROLLER_HPP
#define PERIPH_CONTROLLER_PERIPH_CONTROLLER_HPP

#include "ros/ros.h"
#include "periph_controller/ExtendBasket.h"
#include "periph_controller/RetractBasket.h"
#include "periph_controller/ActivatePump.h"
#include "periph_controller/DeactivatePump.h"
#include "periph_controller/StartVision.h"
#include "serial/serial.h"

class Controller {
 public:
  Controller(ros::NodeHandle *nh);

  void Run();

 private:
  ros::NodeHandle *nh_;
  ros::ServiceServer extend_basket_srv_;
  ros::ServiceServer retract_basket_srv_;
  ros::ServiceServer activate_pump_srv_;
  ros::ServiceServer deactivate_pump_srv_;
  serial::Serial ser_handle;

  // Services
  bool ExtendBasket(periph_controller::ExtendBasket::Request &req,
                    periph_controller::ExtendBasket::Response &res);
  bool RetractBasket(periph_controller::RetractBasket::Request &req,
                     periph_controller::RetractBasket::Response &res);
  bool ActivatePump(periph_controller::ActivatePump::Request &req,
                    periph_controller::ActivatePump::Response &res);
  bool DeactivatePump(periph_controller::DeactivatePump::Request &req,
                      periph_controller::DeactivatePump::Response &res);
};

#endif /* PERIPH_CONTROLLER_PERIPH_CONTROLLER_HPP */
