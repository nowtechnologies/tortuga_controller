#include "orientation.h"

Orientation::Orientation(){
  isPresent = false;
  message.header.frame_id = "imu_link";
};

void Orientation::init(){ // TODO: operation mode argument from rosparam
  bno.hardReset(BNO_RES);
  isPresent = bno.begin(Bosch_BNO055::OPERATION_MODE_IMUPLUS);
  if (isPresent){
    bno.setExtCrystalUse(true);
  }

  float accel_rms = 150.0;
  float accel_cas = 0.005;
  float accel_rms_SI = accel_rms*9.81*0.001; // ~1.47
  float accel_variance = accel_rms_SI*accel_rms_SI;
  float linear_acceleration_covariance[] =
      { accel_variance,            accel_cas*accel_variance, accel_cas*accel_variance,
        accel_cas*accel_variance,  accel_variance,           accel_cas*accel_variance,
        accel_cas*accel_variance,  accel_cas*accel_variance, accel_variance };
  for (uint8_t i = 0; i < 9; i++){
    message.linear_acceleration_covariance[i] = linear_acceleration_covariance[i];
  }

  // rms = 0.1 deg/sec NDOF_FMC_OFF -> gyro_range = 2000 deg/sec
  // cross axis sensitivity  = 1% typical
  float gyro_rms = 0.1;
  float gyro_cas = 0.005;
  float gyro_rms_SI = gyro_rms*M_PI/180.0; // ~0.00174
  float gyro_variance = gyro_rms_SI*gyro_rms_SI;
  float angular_velocity_covariance[] =
      { gyro_variance,          gyro_cas*gyro_variance,   gyro_cas*gyro_variance,
        gyro_cas*gyro_variance, gyro_variance,            gyro_cas*gyro_variance,
        gyro_cas*gyro_variance, gyro_cas*gyro_variance,   gyro_variance };
  for (uint8_t i = 0; i < 9; i++){
    message.angular_velocity_covariance[i] = angular_velocity_covariance[i];
  }

  // Orientation RMS is originated from gyro
  float samples_per_sec = 2.0;
  float quat_cas = 0.005;
  float quat_rms_SI = gyro_rms_SI/samples_per_sec; // ~0.00017 [rad]
  float quat_variance = quat_rms_SI*quat_rms_SI;
  float orientation_covariance[] =
      { quat_variance,          quat_cas*quat_variance,  quat_cas*quat_variance,
        quat_cas*quat_variance, quat_variance,           quat_cas*quat_variance,
        quat_cas*quat_variance, quat_cas*quat_variance,  quat_variance };
  for (uint8_t i = 0; i < 9; i++){
    message.orientation_covariance[i] = orientation_covariance[i];
  }

  // TODO: add magnetometer topic if enabled

  /*
  // rms = 0.3uT *high accuracy preset
  // mag_range_xy = 1300uT, mag_range_z = 2500uT
  float mag_rms = 0.3;
  float mag_cas = 0.005;
  float mag_rms_SI = mag_rms/1000; // ~0.0003
  float mag_variance = mag_rms_SI*mag_rms_SI;
  float magnetic_field_covariance[] =
      { mag_variance,         mag_cas*mag_variance,  mag_cas*mag_variance,
        mag_cas*mag_variance, mag_variance,          mag_cas*mag_variance,
        mag_cas*mag_variance, mag_cas*mag_variance,  mag_variance };
  for (uint8_t i = 0; i < 9; i++){
    compass.magnetic_field_covariance[i] = magnetic_field_covariance[i];
  }
  */

};

void Orientation::poll(ros::Time stamp){
  quaternion    = bno.getQuat();
  gyroscope     = bno.getVector(Bosch_BNO055::VECTOR_GYROSCOPE);
  accelerometer = bno.getVector(Bosch_BNO055::VECTOR_LINEARACCEL);
  message.header.stamp  = stamp;
  message.orientation.w = quaternion.w();
  message.orientation.x = quaternion.x();
  message.orientation.y = quaternion.y();
  message.orientation.z = quaternion.z();
  message.angular_velocity.x = gyroscope.x();
  message.angular_velocity.y = gyroscope.y();
  message.angular_velocity.z = gyroscope.z();
  message.linear_acceleration.x = accelerometer.x();
  message.linear_acceleration.y = accelerometer.y();
  message.linear_acceleration.z = accelerometer.z();
};
