#ifndef _ROS_SERVICE_SetTemperature_h
#define _ROS_SERVICE_SetTemperature_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Float32.h"

namespace nowtech_sensor_models
{

static const char SETTEMPERATURE[] = "nowtech_sensor_models/SetTemperature";

  class SetTemperatureRequest : public ros::Msg
  {
    public:
      typedef std_msgs::Float32 _temperature_type;
      _temperature_type temperature;

    SetTemperatureRequest():
      temperature()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->temperature.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->temperature.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return SETTEMPERATURE; };
    virtual const char * getMD5() override { return "ef84ef3026ebaa21b37f5b167de3d809"; };

  };

  class SetTemperatureResponse : public ros::Msg
  {
    public:
      typedef std_msgs::Float32 _temperature_type;
      _temperature_type temperature;

    SetTemperatureResponse():
      temperature()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->temperature.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->temperature.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return SETTEMPERATURE; };
    virtual const char * getMD5() override { return "ef84ef3026ebaa21b37f5b167de3d809"; };

  };

  class SetTemperature {
    public:
    typedef SetTemperatureRequest Request;
    typedef SetTemperatureResponse Response;
  };

}
#endif
