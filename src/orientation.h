#ifndef TORTUGA_IMU_H
#define TORTUGA_IMU_H

#include <sensor_msgs/Imu.h>
#include <ros/time.h>
#include <bno055.h>

#include "definitions.h"

class Orientation {
private:
  Bosch_BNO055 bno = Bosch_BNO055(55);
  imu::Vector<3> gyroscope;
  imu::Vector<3> accelerometer;
  imu::Quaternion quaternion;
public:
  Orientation();
  void init();
  void poll(ros::Time stamp);
  void spin();
  bool isPresent;
  sensor_msgs::Imu message;
};

#endif
