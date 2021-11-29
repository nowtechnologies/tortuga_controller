#ifndef _ROS_SERVICE_deviceToControl_h
#define _ROS_SERVICE_deviceToControl_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace glory_bridge
{

static const char DEVICETOCONTROL[] = "glory_bridge/deviceToControl";

  class deviceToControlRequest : public ros::Msg
  {
    public:
      typedef uint8_t _deviceToControl_type;
      _deviceToControl_type deviceToControl;

    deviceToControlRequest():
      deviceToControl(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->deviceToControl >> (8 * 0)) & 0xFF;
      offset += sizeof(this->deviceToControl);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->deviceToControl =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->deviceToControl);
     return offset;
    }

    virtual const char * getType() override { return DEVICETOCONTROL; };
    virtual const char * getMD5() override { return "f7edb22b1db8bed38c8cc660230b6b44"; };

  };

  class deviceToControlResponse : public ros::Msg
  {
    public:
      typedef bool _result_type;
      _result_type result;

    deviceToControlResponse():
      result(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
     return offset;
    }

    virtual const char * getType() override { return DEVICETOCONTROL; };
    virtual const char * getMD5() override { return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class deviceToControl {
    public:
    typedef deviceToControlRequest Request;
    typedef deviceToControlResponse Response;
  };

}
#endif
