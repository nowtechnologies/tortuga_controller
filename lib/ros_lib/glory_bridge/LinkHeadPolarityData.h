#ifndef _ROS_glory_bridge_LinkHeadPolarityData_h
#define _ROS_glory_bridge_LinkHeadPolarityData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace glory_bridge
{

  class LinkHeadPolarityData : public ros::Msg
  {
    public:
      typedef bool _forward_reversed_type;
      _forward_reversed_type forward_reversed;
      typedef bool _right_reversed_type;
      _right_reversed_type right_reversed;

    LinkHeadPolarityData():
      forward_reversed(0),
      right_reversed(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_forward_reversed;
      u_forward_reversed.real = this->forward_reversed;
      *(outbuffer + offset + 0) = (u_forward_reversed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->forward_reversed);
      union {
        bool real;
        uint8_t base;
      } u_right_reversed;
      u_right_reversed.real = this->right_reversed;
      *(outbuffer + offset + 0) = (u_right_reversed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->right_reversed);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_forward_reversed;
      u_forward_reversed.base = 0;
      u_forward_reversed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->forward_reversed = u_forward_reversed.real;
      offset += sizeof(this->forward_reversed);
      union {
        bool real;
        uint8_t base;
      } u_right_reversed;
      u_right_reversed.base = 0;
      u_right_reversed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->right_reversed = u_right_reversed.real;
      offset += sizeof(this->right_reversed);
     return offset;
    }

    virtual const char * getType() override { return "glory_bridge/LinkHeadPolarityData"; };
    virtual const char * getMD5() override { return "22c4c8598157d7e764f2a1e748bc70a7"; };

  };

}
#endif
