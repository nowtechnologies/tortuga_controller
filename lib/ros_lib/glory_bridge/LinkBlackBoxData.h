#ifndef _ROS_glory_bridge_LinkBlackBoxData_h
#define _ROS_glory_bridge_LinkBlackBoxData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace glory_bridge
{

  class LinkBlackBoxData : public ros::Msg
  {
    public:
      typedef uint16_t _expected_type;
      _expected_type expected;
      typedef uint16_t _read_type;
      _read_type read;

    LinkBlackBoxData():
      expected(0),
      read(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->expected >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->expected >> (8 * 1)) & 0xFF;
      offset += sizeof(this->expected);
      *(outbuffer + offset + 0) = (this->read >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->read >> (8 * 1)) & 0xFF;
      offset += sizeof(this->read);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->expected =  ((uint16_t) (*(inbuffer + offset)));
      this->expected |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->expected);
      this->read =  ((uint16_t) (*(inbuffer + offset)));
      this->read |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->read);
     return offset;
    }

    virtual const char * getType() override { return "glory_bridge/LinkBlackBoxData"; };
    virtual const char * getMD5() override { return "76f593675fa6e5d00aaba637a7765639"; };

  };

}
#endif
