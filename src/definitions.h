#ifndef _TORTUGA_DEFINITIONS_H_
#define _TORTUGA_DEFINITIONS_H_

// Arduino Pins
#define BNO_RES   13
#define BNO_INT   14
#define ENC1_B    26
#define ENC1_A    25
#define ENC2_B    27
#define ENC2_A    32

// Drive constants
#define RIGHT_MOTOR 1 // channel
#define LEFT_MOTOR  2
#define MAX_POWER_OUT  2047
#define LIGHT_CHANNEL 1
#define POWER_CHANNEL 2

// Wheel encoders
#define DEFAULT_ENC_PPR  11
#define DEFAULT_GEARBOX_RATIO 72 // 1:72 wheel:motor
#define DEFAULT_WHEEL_RADIUS 0.055 // m
#define ENC_TAN_OUTPUT 1 // 0 - angular velocity output

// Motor control
#define DEFAULT_KP 0.10
#define DEFAULT_KI 0.25
#define DEFAULT_KD 0.20

// Base
#define DEFAULT_TRACK_WIDTH 0.255 // m

// Timers
#define IMU_READ_MILLIS  50 // ms
#define ENC_READ_MILLIS  50
#define COMMAND_TIMEOUT  100
#define CONTROL_MILLIS   50
#define BATTERY_MILLIS   5000
#define ODOMETRY_MILLIS  50

#endif
