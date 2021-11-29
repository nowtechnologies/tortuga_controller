#ifndef _ROS_SERVICE_enableWire_h
#define _ROS_SERVICE_enableWire_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace glory_bridge
{

static const char ENABLEWIRE[] = "glory_bridge/enableWire";

  class enableWireRequest : public ros::Msg
  {
    public:
      typedef bool _enableWire_type;
      _enableWire_type enableWire;

    enableWireRequest():
      enableWire(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enableWire;
      u_enableWire.real = this->enableWire;
      *(outbuffer + offset + 0) = (u_enableWire.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enableWire);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enableWire;
      u_enableWire.base = 0;
      u_enableWire.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enableWire = u_enableWire.real;
      offset += sizeof(this->enableWire);
     return offset;
    }

    virtual const char * getType() override { return ENABLEWIRE; };
    virtual const char * getMD5() override { return "04a13d20e30bdea11145f4775ef08c8c"; };

  };

  class enableWireResponse : public ros::Msg
  {
    public:
      typedef bool _result_type;
      _result_type result;

    enableWireResponse():
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

    virtual const char * getType() override { return ENABLEWIRE; };
    virtual const char * getMD5() override { return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class enableWire {
    public:
    typedef enableWireRequest Request;
    typedef enableWireResponse Response;
  };

}
#endif
