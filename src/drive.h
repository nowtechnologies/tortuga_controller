#ifndef TORTUGA_DRIVE_H
#define TORTUGA_DRIVE_H

#include <Arduino.h>
#include <USBSabertooth.h>

class Drive {
private:
  bool isEnabled;
public:
  Drive();
  void  init();
  void  motor(uint8_t ID, float output);
  void  powerOut(uint8_t ID, int output);
  void  stop();
  float getBattery();
  bool  present();
  bool  isPresent;
  void  enable(bool state);
};

#endif
