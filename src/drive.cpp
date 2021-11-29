#include "drive.h"

USBSabertoothSerial C(Serial2);
USBSabertooth 	    ST(C, 128);

Drive::Drive(){
  isPresent = false;
  isEnabled = false;
};

void Drive::motor(uint8_t ID, float output)
{
  if (isEnabled) ST.motor(ID, output);
};

void Drive::powerOut(uint8_t ID, int output){
  ST.power(ID, output);
};

void Drive::stop()
{
  ST.motor(1, 0);
  ST.motor(2, 0);
};

float Drive::getBattery()
{
  return (ST.getBattery(1,false))*0.1f;
};

bool Drive::present()
{
  if (getBattery() > 0 ) return true;
  else return false;
}

void Drive::init()
{
  Serial2.begin(115200);
  ST.setGetTimeout(1000);
  ST.setTimeout(100);
  stop();
  isPresent = present();
};

void Drive::enable(bool state){
  isEnabled = state;
}
