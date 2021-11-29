#include "odometry.h"

Odometry::Odometry(){
  float poseCovarianceMatrix[] =
  {
    0.001,  0,     0,         0,          0,          0,
    0,      0.001, 0,         0,          0,          0,
    0,      0,     1000000.0, 0,          0,          0,
    0,      0,     0,         1000000.0,  0,          0,
    0,      0,     0,         0,          1000000.0,  0,
    0,      0,     0,         0,          0,          0.03
  };
  for (uint8_t i = 0; i < 36; i++){
    message.pose.covariance[i] = poseCovarianceMatrix[i];
  }
  message.pose.pose.position.z = 0.0;
  message.header.frame_id = "odom";
  message.child_frame_id  = "base_footprint";
  trackWidth  = DEFAULT_TRACK_WIDTH;
  theta = 0.0f;
};

void Odometry::update(float rightWheelTangentVelocity, float leftWheelTangentVelocity, ros::Time stamp){

  message.header.stamp = stamp;

  double sumOfVelocities = rightWheelTangentVelocity + leftWheelTangentVelocity;
  double subOfVelocities = rightWheelTangentVelocity - leftWheelTangentVelocity;
  double baseLinearVelocity  = sumOfVelocities / 2.0f;
  double baseAngularVelocity = subOfVelocities / trackWidth;

  double dT = (stamp-lastTime).toSec();
  double wcdt = baseAngularVelocity * dT;
  double dx = 0;
  double dy = 0;
  double cosTheta = cos(theta);
  double sinTheta = sin(theta);
  double ds = baseLinearVelocity * dT; // m

  const double zeroThreshold = 0.005f;
  if (fabs(subOfVelocities) < zeroThreshold) {
    baseAngularVelocity = 0;
    wcdt = 0;
    dx = cosTheta*ds;
    dy = sinTheta*ds;
  } else {
    double radius = (trackWidth/2.0f) * (sumOfVelocities/subOfVelocities);
    double RcosTheta = radius * cosTheta;
    double RsinTheta = radius * sinTheta;
    dx = - RsinTheta + cos(wcdt) * RsinTheta + sin(wcdt) * RcosTheta;
    dy = + RcosTheta + sin(wcdt) * RsinTheta - cos(wcdt) * RcosTheta;
  }

  theta += wcdt;

  message.pose.pose.orientation.x = 0;
  message.pose.pose.orientation.y = 0;
  message.pose.pose.orientation.z = sin(theta * 0.5);
  message.pose.pose.orientation.w = cos(theta * 0.5);

  message.pose.pose.position.x += dx;
  message.pose.pose.position.y += dy;

  message.twist.twist.linear.x  = baseLinearVelocity;
  message.twist.twist.angular.z = baseAngularVelocity;

  lastTime = stamp;
}
