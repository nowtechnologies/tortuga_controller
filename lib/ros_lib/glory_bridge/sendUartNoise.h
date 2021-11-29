#ifndef _ROS_SERVICE_sendUartNoise_h
#define _ROS_SERVICE_sendUartNoise_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace glory_bridge
{

static const char SENDUARTNOISE[] = "glory_bridge/sendUartNoise";

  class sendUartNoiseRequest : public ros::Msg
  {
    public:
      typedef uint16_t _length_type;
      _length_type length;
      typedef uint64_t _baud_type;
      _baud_type baud;
      typedef bool _continuous_type;
      _continuous_type continuous;

    sendUartNoiseRequest():
      length(0),
      baud(0),
      continuous(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->length >> (8 * 1)) & 0xFF;
      offset += sizeof(this->length);
      *(outbuffer + offset + 0) = (this->baud >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->baud >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->baud >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->baud >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->baud >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->baud >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->baud >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->baud >> (8 * 7)) & 0xFF;
      offset += sizeof(this->baud);
      union {
        bool real;
        uint8_t base;
      } u_continuous;
      u_continuous.real = this->continuous;
      *(outbuffer + offset + 0) = (u_continuous.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->continuous);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->length =  ((uint16_t) (*(inbuffer + offset)));
      this->length |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->length);
      this->baud =  ((uint64_t) (*(inbuffer + offset)));
      this->baud |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->baud |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->baud |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->baud |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->baud |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->baud |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->baud |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->baud);
      union {
        bool real;
        uint8_t base;
      } u_continuous;
      u_continuous.base = 0;
      u_continuous.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->continuous = u_continuous.real;
      offset += sizeof(this->continuous);
     return offset;
    }

    virtual const char * getType() override { return SENDUARTNOISE; };
    virtual const char * getMD5() override { return "3ab47e9d00481d14297cc624c97cb9a8"; };

  };

  class sendUartNoiseResponse : public ros::Msg
  {
    public:
      typedef bool _accepted_type;
      _accepted_type accepted;

    sendUartNoiseResponse():
      accepted(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_accepted;
      u_accepted.real = this->accepted;
      *(outbuffer + offset + 0) = (u_accepted.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->accepted);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_accepted;
      u_accepted.base = 0;
      u_accepted.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->accepted = u_accepted.real;
      offset += sizeof(this->accepted);
     return offset;
    }

    virtual const char * getType() override { return SENDUARTNOISE; };
    virtual const char * getMD5() override { return "1ea39b897cc8620c46aaa14cb60920cd"; };

  };

  class sendUartNoise {
    public:
    typedef sendUartNoiseRequest Request;
    typedef sendUartNoiseResponse Response;
  };

}
#endif
