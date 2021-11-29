#ifndef TORTUGA_ENCODER_H
#define TORTUGA_ENCODER_H

#include <ESP32Encoder.h>
#include <std_msgs/Float32.h>
#include <ros/time.h>

#include "definitions.h"

class Encoder{
private:
  ESP32Encoder encoder;
  int32_t counter;
  int32_t lastCount;
  float tickAngle;
  ros::Time lastTime;
public:
  float wheelRadius;
  double wheelVelocity;
  bool tangentOutput;
  uint16_t resolution;
  uint16_t wheelToShaftRatio;
  std_msgs::Float32 message;
  Encoder();
  void init(uint8_t pin_a, uint8_t pin_b);
  void poll(ros::Time stamp);
  void setResolution(uint16_t res);
  void setGearBoxRatio(uint16_t ratio);
};

#endif
