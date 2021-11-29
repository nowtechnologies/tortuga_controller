#ifndef _TORTUGA_WHEEL_ODOMETRY_H_
#define _TORTUGA_WHEEL_ODOMETRY_H_

#include <ros/time.h>
#include <nav_msgs/Odometry.h>

#include "definitions.h"

class Odometry{
private:
  ros::Time lastTime;
  float theta;
public:
  float trackWidth;
  nav_msgs::Odometry message;
  Odometry();
  void update(float rightWheelTangentVelocity, float leftWheelTangentVelocity, ros::Time stamp);
};

#endif
