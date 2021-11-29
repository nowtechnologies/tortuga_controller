#ifndef _ROS_SERVICE_getControlState_h
#define _ROS_SERVICE_getControlState_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace nowtech_teleoperator
{

static const char GETCONTROLSTATE[] = "nowtech_teleoperator/getControlState";

  class getControlStateRequest : public ros::Msg
  {
    public:
      typedef bool _getControlState_type;
      _getControlState_type getControlState;

    getControlStateRequest():
      getControlState(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_getControlState;
      u_getControlState.real = this->getControlState;
      *(outbuffer + offset + 0) = (u_getControlState.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->getControlState);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_getControlState;
      u_getControlState.base = 0;
      u_getControlState.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->getControlState = u_getControlState.real;
      offset += sizeof(this->getControlState);
     return offset;
    }

    virtual const char * getType() override { return GETCONTROLSTATE; };
    virtual const char * getMD5() override { return "b98a5ea02c642396cff2ae286c009499"; };

  };

  class getControlStateResponse : public ros::Msg
  {
    public:
      typedef bool _controlState_type;
      _controlState_type controlState;

    getControlStateResponse():
      controlState(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_controlState;
      u_controlState.real = this->controlState;
      *(outbuffer + offset + 0) = (u_controlState.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->controlState);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_controlState;
      u_controlState.base = 0;
      u_controlState.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->controlState = u_controlState.real;
      offset += sizeof(this->controlState);
     return offset;
    }

    virtual const char * getType() override { return GETCONTROLSTATE; };
    virtual const char * getMD5() override { return "095a25a665bab9abdf36c93880001eda"; };

  };

  class getControlState {
    public:
    typedef getControlStateRequest Request;
    typedef getControlStateResponse Response;
  };

}
#endif
