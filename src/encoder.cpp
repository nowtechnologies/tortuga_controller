#include "encoder.h"

Encoder::Encoder(){
  resolution = DEFAULT_ENC_PPR;
  tickAngle = TWO_PI / (resolution*2); // NOTE: half quad double count
  wheelToShaftRatio = DEFAULT_GEARBOX_RATIO;
  wheelRadius = DEFAULT_WHEEL_RADIUS; // m
  counter = 0;
  lastCount = 0;
  tangentOutput = bool(ENC_TAN_OUTPUT);
};

void Encoder::init(uint8_t pin_a, uint8_t pin_b){
  ESP32Encoder::useInternalWeakPullResistors=UP;
  encoder.attachHalfQuad(pin_a, pin_b);
  encoder.clearCount();
};

void Encoder::poll(ros::Time stamp){
  double dT = (stamp-lastTime).toSec();
  counter = (int32_t)encoder.getCount();
  int32_t ticks = abs(counter - lastCount);
  float motorShaftVelocity = ticks * tickAngle * (1.0/dT);
  wheelVelocity = counter>=lastCount?-motorShaftVelocity/wheelToShaftRatio:motorShaftVelocity/wheelToShaftRatio;
  if (tangentOutput) wheelVelocity = wheelVelocity * wheelRadius;
  message.data = wheelVelocity;
  lastTime = stamp;
  lastCount = counter;
};

void Encoder::setResolution(uint16_t res){
  resolution = res;
  tickAngle  = TWO_PI / (resolution*2);
}

void Encoder::setGearBoxRatio(uint16_t ratio){
  wheelToShaftRatio = ratio;
}
