#ifndef _ROS_SERVICE_enableControl_h
#define _ROS_SERVICE_enableControl_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace nowtech_teleoperator
{

static const char ENABLECONTROL[] = "nowtech_teleoperator/enableControl";

  class enableControlRequest : public ros::Msg
  {
    public:
      typedef bool _enableControl_type;
      _enableControl_type enableControl;

    enableControlRequest():
      enableControl(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enableControl;
      u_enableControl.real = this->enableControl;
      *(outbuffer + offset + 0) = (u_enableControl.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enableControl);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enableControl;
      u_enableControl.base = 0;
      u_enableControl.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enableControl = u_enableControl.real;
      offset += sizeof(this->enableControl);
     return offset;
    }

    virtual const char * getType() override { return ENABLECONTROL; };
    virtual const char * getMD5() override { return "9832398be814564292f9c4a93259c73c"; };

  };

  class enableControlResponse : public ros::Msg
  {
    public:
      typedef bool _result_type;
      _result_type result;

    enableControlResponse():
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

    virtual const char * getType() override { return ENABLECONTROL; };
    virtual const char * getMD5() override { return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class enableControl {
    public:
    typedef enableControlRequest Request;
    typedef enableControlResponse Response;
  };

}
#endif
