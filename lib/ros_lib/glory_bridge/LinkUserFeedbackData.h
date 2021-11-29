#ifndef _ROS_glory_bridge_LinkUserFeedbackData_h
#define _ROS_glory_bridge_LinkUserFeedbackData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace glory_bridge
{

  class LinkUserFeedbackData : public ros::Msg
  {
    public:
      typedef bool _fifth_up_type;
      _fifth_up_type fifth_up;

    LinkUserFeedbackData():
      fifth_up(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_fifth_up;
      u_fifth_up.real = this->fifth_up;
      *(outbuffer + offset + 0) = (u_fifth_up.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->fifth_up);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_fifth_up;
      u_fifth_up.base = 0;
      u_fifth_up.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->fifth_up = u_fifth_up.real;
      offset += sizeof(this->fifth_up);
     return offset;
    }

    virtual const char * getType() override { return "glory_bridge/LinkUserFeedbackData"; };
    virtual const char * getMD5() override { return "e2f0731d2fcfe7a9e9df0ab7e2e1513f"; };

  };

}
#endif
