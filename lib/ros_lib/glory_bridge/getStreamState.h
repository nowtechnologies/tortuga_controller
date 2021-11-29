#ifndef _ROS_SERVICE_getStreamState_h
#define _ROS_SERVICE_getStreamState_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace glory_bridge
{

static const char GETSTREAMSTATE[] = "glory_bridge/getStreamState";

  class getStreamStateRequest : public ros::Msg
  {
    public:
      typedef bool _getStreamState_type;
      _getStreamState_type getStreamState;

    getStreamStateRequest():
      getStreamState(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_getStreamState;
      u_getStreamState.real = this->getStreamState;
      *(outbuffer + offset + 0) = (u_getStreamState.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->getStreamState);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_getStreamState;
      u_getStreamState.base = 0;
      u_getStreamState.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->getStreamState = u_getStreamState.real;
      offset += sizeof(this->getStreamState);
     return offset;
    }

    virtual const char * getType() override { return GETSTREAMSTATE; };
    virtual const char * getMD5() override { return "fc6c5e4f297abaa1597907ffd55a4824"; };

  };

  class getStreamStateResponse : public ros::Msg
  {
    public:
      typedef bool _streamState_type;
      _streamState_type streamState;

    getStreamStateResponse():
      streamState(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_streamState;
      u_streamState.real = this->streamState;
      *(outbuffer + offset + 0) = (u_streamState.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->streamState);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_streamState;
      u_streamState.base = 0;
      u_streamState.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->streamState = u_streamState.real;
      offset += sizeof(this->streamState);
     return offset;
    }

    virtual const char * getType() override { return GETSTREAMSTATE; };
    virtual const char * getMD5() override { return "db37b9e7f631717baeb5902eae527d82"; };

  };

  class getStreamState {
    public:
    typedef getStreamStateRequest Request;
    typedef getStreamStateResponse Response;
  };

}
#endif
