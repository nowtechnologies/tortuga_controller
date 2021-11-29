#ifndef _ROS_SERVICE_getWireState_h
#define _ROS_SERVICE_getWireState_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace glory_bridge
{

static const char GETWIRESTATE[] = "glory_bridge/getWireState";

  class getWireStateRequest : public ros::Msg
  {
    public:
      typedef bool _getWireState_type;
      _getWireState_type getWireState;

    getWireStateRequest():
      getWireState(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_getWireState;
      u_getWireState.real = this->getWireState;
      *(outbuffer + offset + 0) = (u_getWireState.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->getWireState);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_getWireState;
      u_getWireState.base = 0;
      u_getWireState.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->getWireState = u_getWireState.real;
      offset += sizeof(this->getWireState);
     return offset;
    }

    virtual const char * getType() override { return GETWIRESTATE; };
    virtual const char * getMD5() override { return "240b1c668aab9703aa376035efef2484"; };

  };

  class getWireStateResponse : public ros::Msg
  {
    public:
      typedef bool _wireState_type;
      _wireState_type wireState;

    getWireStateResponse():
      wireState(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_wireState;
      u_wireState.real = this->wireState;
      *(outbuffer + offset + 0) = (u_wireState.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wireState);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_wireState;
      u_wireState.base = 0;
      u_wireState.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->wireState = u_wireState.real;
      offset += sizeof(this->wireState);
     return offset;
    }

    virtual const char * getType() override { return GETWIRESTATE; };
    virtual const char * getMD5() override { return "80dd6855c866349064f9909982547dfa"; };

  };

  class getWireState {
    public:
    typedef getWireStateRequest Request;
    typedef getWireStateResponse Response;
  };

}
#endif
