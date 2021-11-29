#ifndef _ROS_SERVICE_enableStream_h
#define _ROS_SERVICE_enableStream_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace glory_bridge
{

static const char ENABLESTREAM[] = "glory_bridge/enableStream";

  class enableStreamRequest : public ros::Msg
  {
    public:
      typedef bool _enableStream_type;
      _enableStream_type enableStream;

    enableStreamRequest():
      enableStream(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enableStream;
      u_enableStream.real = this->enableStream;
      *(outbuffer + offset + 0) = (u_enableStream.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enableStream);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enableStream;
      u_enableStream.base = 0;
      u_enableStream.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enableStream = u_enableStream.real;
      offset += sizeof(this->enableStream);
     return offset;
    }

    virtual const char * getType() override { return ENABLESTREAM; };
    virtual const char * getMD5() override { return "b1efdda25b3e364fab614e2400086e72"; };

  };

  class enableStreamResponse : public ros::Msg
  {
    public:
      typedef bool _result_type;
      _result_type result;

    enableStreamResponse():
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

    virtual const char * getType() override { return ENABLESTREAM; };
    virtual const char * getMD5() override { return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class enableStream {
    public:
    typedef enableStreamRequest Request;
    typedef enableStreamResponse Response;
  };

}
#endif
