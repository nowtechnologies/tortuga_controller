#ifndef _ROS_SERVICE_getOriginState_h
#define _ROS_SERVICE_getOriginState_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace nowtech_teleoperator
{

static const char GETORIGINSTATE[] = "nowtech_teleoperator/getOriginState";

  class getOriginStateRequest : public ros::Msg
  {
    public:
      typedef bool _getOriginState_type;
      _getOriginState_type getOriginState;

    getOriginStateRequest():
      getOriginState(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_getOriginState;
      u_getOriginState.real = this->getOriginState;
      *(outbuffer + offset + 0) = (u_getOriginState.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->getOriginState);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_getOriginState;
      u_getOriginState.base = 0;
      u_getOriginState.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->getOriginState = u_getOriginState.real;
      offset += sizeof(this->getOriginState);
     return offset;
    }

    virtual const char * getType() override { return GETORIGINSTATE; };
    virtual const char * getMD5() override { return "c6c652c55c7cc17ea16326e27a6bedeb"; };

  };

  class getOriginStateResponse : public ros::Msg
  {
    public:
      typedef bool _originState_type;
      _originState_type originState;

    getOriginStateResponse():
      originState(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_originState;
      u_originState.real = this->originState;
      *(outbuffer + offset + 0) = (u_originState.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->originState);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_originState;
      u_originState.base = 0;
      u_originState.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->originState = u_originState.real;
      offset += sizeof(this->originState);
     return offset;
    }

    virtual const char * getType() override { return GETORIGINSTATE; };
    virtual const char * getMD5() override { return "d6448d9f3ae1fddf43d67ec127f71c40"; };

  };

  class getOriginState {
    public:
    typedef getOriginStateRequest Request;
    typedef getOriginStateResponse Response;
  };

}
#endif
