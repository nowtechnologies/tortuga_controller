#include <timer.h>
#include <ros.h>
#include <std_msgs/Float32.h>
#include <geometry_msgs/Twist.h>
#include <PID.h>

#include "definitions.h"
#include "drive.h"
#include "encoder.h"
#include "orientation.h"
#include "odometry.h"
#include "getparams.h"

ros::NodeHandle nh;

// TODO: add motor current reports

Drive   drive;
Timer   imuReportTimer;
Timer   encoderReportTimer;
Timer   commandTimeoutTimer;
Timer   batteryReportTimer;
Timer   odomReportTimer;
Encoder leftEncoder;
Encoder rightEncoder;
Orientation orientation;
Odometry odometry;

// ROS parameter variables
String  imuFrame     = "";
String  odomFrame    = "";
String  baseFrame    = "";
float   trackWidth   = 0.0;
float   wheelRadius  = 0.0;
float   leftWheelKp  = 0.0;
float   leftWheelKi  = 0.0;
float   leftWheelKd  = 0.0;
float   rightWheelKp = 0.0;
float   rightWheelKi = 0.0;
float   rightWheelKd = 0.0;
bool    publishOdometry  = false;

// motor control variables
double  leftWheelDesiredVelocity = 0.0;
double  rightWheelDesiredVelocity = 0.0;
double  leftMotorPowerOutput = 0.0;
double  rightMotorPowerOutput = 0.0;

PID leftWheelControl(&leftEncoder.wheelVelocity, &leftMotorPowerOutput, &leftWheelDesiredVelocity, leftWheelKp, leftWheelKi, leftWheelKd, false, DIRECT); // P_ON_M
PID rightWheelControl(&rightEncoder.wheelVelocity, &rightMotorPowerOutput, &rightWheelDesiredVelocity, rightWheelKp, rightWheelKi, rightWheelKd, false, DIRECT);

void haltBase(){
  leftWheelDesiredVelocity = 0.0f;
  leftMotorPowerOutput = 0.0f;
  leftWheelControl.SetMode(MANUAL);
  rightWheelDesiredVelocity = 0.0f;
  rightMotorPowerOutput = 0.0f;
  rightWheelControl.SetMode(MANUAL);
  drive.enable(false);
}

void cmdVelCallBack(const geometry_msgs::Twist& twist){
  leftWheelDesiredVelocity  = (2.0f*twist.linear.x - trackWidth * twist.angular.z)/2.0f;
  rightWheelDesiredVelocity = (2.0f*twist.linear.x + trackWidth * twist.angular.z)/2.0f;
  drive.enable(true);
  leftWheelControl.SetMode(AUTOMATIC);
  rightWheelControl.SetMode(AUTOMATIC);
  commandTimeoutTimer.set(COMMAND_TIMEOUT);
}

void lightCallback(const std_msgs::Float32& light){
  drive.powerOut(LIGHT_CHANNEL, (int)(constrain(light.data,-1.0,1.0)*MAX_POWER_OUT));
}

void powerCallback(const std_msgs::Float32& power){
  drive.powerOut(POWER_CHANNEL, (int)(constrain(power.data,-1.0,1.0)*MAX_POWER_OUT));
}

std_msgs::Float32 batteryMsg;
ros::Subscriber<geometry_msgs::Twist> velocityCommandSubscriber("cmd_vel", cmdVelCallBack);
ros::Subscriber<std_msgs::Float32> lightSubscriber("lights", lightCallback);
ros::Subscriber<std_msgs::Float32> powerSubscriber("power_out", powerCallback);
ros::Publisher batteryPublisher("battery/voltage", &batteryMsg);
ros::Publisher imuPublisher("imu", &orientation.message);
ros::Publisher leftEncoderPublisher("left_wheel/velocity", &leftEncoder.message);
ros::Publisher rightEncoderPublisher("right_wheel/velocity", &rightEncoder.message);
ros::Publisher odomPublisher("wheel_odom", &odometry.message);

/*
* Main init, pinned to core-1
*/

void setup(){

  drive.init();
  orientation.init();
  rightEncoder.init(ENC1_A, ENC1_B);
  leftEncoder.init(ENC2_A, ENC2_B);

  nh.getHardware()->setBaud(921600);
  nh.initNode();

  while (!nh.connected()){ nh.spinOnce(); }

  if (orientation.isPresent){nh.advertise(imuPublisher);}

  if (drive.isPresent){
    nh.subscribe(velocityCommandSubscriber);
    nh.subscribe(lightSubscriber);
    nh.subscribe(powerSubscriber);
    nh.advertise(batteryPublisher);
  }

  nh.loginfo("Trying to get ROS parameters...");
  bool loadDefaults = getBoolParam(&nh, "~load_default_params", true);

  trackWidth   = getFloatParam(&nh, "~track_width", DEFAULT_TRACK_WIDTH, loadDefaults);
  wheelRadius  = getFloatParam(&nh, "~wheel_radius", DEFAULT_WHEEL_RADIUS, loadDefaults);
  leftWheelKp  = getFloatParam(&nh, "~left_wheel_kp", DEFAULT_KP, loadDefaults);
  leftWheelKi  = getFloatParam(&nh, "~left_wheel_ki", DEFAULT_KI, loadDefaults);
  leftWheelKd  = getFloatParam(&nh, "~left_wheel_kd", DEFAULT_KD, loadDefaults);
  rightWheelKp = getFloatParam(&nh, "~right_wheel_kp", DEFAULT_KP, loadDefaults);
  rightWheelKi = getFloatParam(&nh, "~right_wheel_ki", DEFAULT_KI, loadDefaults);
  rightWheelKd = getFloatParam(&nh, "~right_wheel_kd", DEFAULT_KD, loadDefaults);

  imuFrame = getStringParam(&nh, "~imu_frame", "imu_link", loadDefaults);
  orientation.message.header.frame_id = imuFrame.c_str();


  publishOdometry = getBoolParam(&nh, "~publish_odometry", true, loadDefaults);
  if (publishOdometry){
    odomFrame = getStringParam(&nh, "~odom_frame", "odom", loadDefaults);
    baseFrame = getStringParam(&nh, "~base_frame", "base_footprint", loadDefaults);
    odometry.trackWidth  = trackWidth;
    odometry.message.header.frame_id = odomFrame.c_str();
    odometry.message.child_frame_id  = baseFrame.c_str();
    nh.advertise(odomPublisher);
  }
  else {
    nh.advertise(leftEncoderPublisher);
    nh.advertise(rightEncoderPublisher);
  }

  float encoderResolution  = getFloatParam(&nh, "~encoder_ppr", DEFAULT_ENC_PPR, loadDefaults);
  float wheelToShaftRatio  = getFloatParam(&nh, "~gearbox_ratio", DEFAULT_GEARBOX_RATIO, loadDefaults);
  leftEncoder.wheelToShaftRatio = (int)(wheelToShaftRatio);
  rightEncoder.wheelToShaftRatio = (int)(wheelToShaftRatio);
  leftEncoder.resolution   = (int)(encoderResolution);
  rightEncoder.resolution  = (int)(encoderResolution);
  leftEncoder.wheelRadius  = wheelRadius;
  rightEncoder.wheelRadius = wheelRadius;

  leftWheelControl.SetOutputLimits(-1.0, 1.0);
  leftWheelControl.SetMode(AUTOMATIC);
  leftWheelControl.SetTunings(leftWheelKp, leftWheelKi, leftWheelKd);
  leftWheelControl.SetContinuous(true);

  rightWheelControl.SetOutputLimits(-1.0, 1.0);
  rightWheelControl.SetMode(AUTOMATIC);
  rightWheelControl.SetTunings(rightWheelKp, rightWheelKi, rightWheelKd);
  rightWheelControl.SetContinuous(true);

  imuReportTimer.set(IMU_READ_MILLIS);
  encoderReportTimer.set(ENC_READ_MILLIS);
  commandTimeoutTimer.set(COMMAND_TIMEOUT);
  batteryReportTimer.set(BATTERY_MILLIS);
  odomReportTimer.set(ODOMETRY_MILLIS+20); // NOTE: odometry ~700bytes / 6.5ms @ 921600 bps
  nh.loginfo("Base controller started.");
}

/*
* Main loop, pinned to core-1
*/

void loop(){

  if (orientation.isPresent&&imuReportTimer.poll()){
    imuReportTimer.set(IMU_READ_MILLIS);
    orientation.poll(nh.now());
    imuPublisher.publish(&orientation.message);
  }
  else if (publishOdometry&&odomReportTimer.poll()){
    odomReportTimer.set(ODOMETRY_MILLIS);
    odomPublisher.publish(&odometry.message);
  }

  if (encoderReportTimer.poll()){
    encoderReportTimer.set(ENC_READ_MILLIS);
    leftEncoder.poll(nh.now());
    rightEncoder.poll(nh.now());
    if (publishOdometry) {
      odometry.update(rightEncoder.wheelVelocity, leftEncoder.wheelVelocity, nh.now());
    }
    else {
      leftEncoderPublisher.publish(&leftEncoder.message);
      rightEncoderPublisher.publish(&rightEncoder.message);
    }
  }

  if (commandTimeoutTimer.poll()){
    haltBase();
  }

  if (drive.isPresent&&batteryReportTimer.poll()){
    batteryReportTimer.set(BATTERY_MILLIS);
    batteryMsg.data = drive.getBattery(); // volts
    batteryPublisher.publish(&batteryMsg);
  }

  leftWheelControl.Compute();
  rightWheelControl.Compute();

  if (drive.isPresent){
    drive.motor(LEFT_MOTOR,  leftMotorPowerOutput*MAX_POWER_OUT);
    drive.motor(RIGHT_MOTOR, rightMotorPowerOutput*MAX_POWER_OUT);
  }

  nh.spinOnce();
}
