#ifndef _ROS_SERVICE_resetOrigin_h
#define _ROS_SERVICE_resetOrigin_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace nowtech_teleoperator
{

static const char RESETORIGIN[] = "nowtech_teleoperator/resetOrigin";

  class resetOriginRequest : public ros::Msg
  {
    public:
      typedef bool _resetOrigin_type;
      _resetOrigin_type resetOrigin;

    resetOriginRequest():
      resetOrigin(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_resetOrigin;
      u_resetOrigin.real = this->resetOrigin;
      *(outbuffer + offset + 0) = (u_resetOrigin.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->resetOrigin);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_resetOrigin;
      u_resetOrigin.base = 0;
      u_resetOrigin.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->resetOrigin = u_resetOrigin.real;
      offset += sizeof(this->resetOrigin);
     return offset;
    }

    virtual const char * getType() override { return RESETORIGIN; };
    virtual const char * getMD5() override { return "23317e4690487baf7aaa59a4bcac48a8"; };

  };

  class resetOriginResponse : public ros::Msg
  {
    public:
      typedef bool _result_type;
      _result_type result;

    resetOriginResponse():
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

    virtual const char * getType() override { return RESETORIGIN; };
    virtual const char * getMD5() override { return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class resetOrigin {
    public:
    typedef resetOriginRequest Request;
    typedef resetOriginResponse Response;
  };

}
#endif
