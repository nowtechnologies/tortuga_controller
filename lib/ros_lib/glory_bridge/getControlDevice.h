#ifndef _ROS_SERVICE_getControlDevice_h
#define _ROS_SERVICE_getControlDevice_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace glory_bridge
{

static const char GETCONTROLDEVICE[] = "glory_bridge/getControlDevice";

  class getControlDeviceRequest : public ros::Msg
  {
    public:
      typedef bool _getControlDevice_type;
      _getControlDevice_type getControlDevice;

    getControlDeviceRequest():
      getControlDevice(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_getControlDevice;
      u_getControlDevice.real = this->getControlDevice;
      *(outbuffer + offset + 0) = (u_getControlDevice.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->getControlDevice);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_getControlDevice;
      u_getControlDevice.base = 0;
      u_getControlDevice.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->getControlDevice = u_getControlDevice.real;
      offset += sizeof(this->getControlDevice);
     return offset;
    }

    virtual const char * getType() override { return GETCONTROLDEVICE; };
    virtual const char * getMD5() override { return "7f9163c088e7a1cfb60058021369c201"; };

  };

  class getControlDeviceResponse : public ros::Msg
  {
    public:
      typedef uint8_t _controlledDevice_type;
      _controlledDevice_type controlledDevice;

    getControlDeviceResponse():
      controlledDevice(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->controlledDevice >> (8 * 0)) & 0xFF;
      offset += sizeof(this->controlledDevice);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->controlledDevice =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->controlledDevice);
     return offset;
    }

    virtual const char * getType() override { return GETCONTROLDEVICE; };
    virtual const char * getMD5() override { return "ad6b96b5edfb5aeeb03274b8e9e096a4"; };

  };

  class getControlDevice {
    public:
    typedef getControlDeviceRequest Request;
    typedef getControlDeviceResponse Response;
  };

}
#endif
