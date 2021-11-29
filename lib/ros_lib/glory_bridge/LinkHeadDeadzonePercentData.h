#ifndef _ROS_glory_bridge_LinkHeadDeadzonePercentData_h
#define _ROS_glory_bridge_LinkHeadDeadzonePercentData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace glory_bridge
{

  class LinkHeadDeadzonePercentData : public ros::Msg
  {
    public:
      typedef uint16_t _forward_in_type;
      _forward_in_type forward_in;
      typedef uint16_t _forward_out_type;
      _forward_out_type forward_out;
      typedef uint16_t _right_in_type;
      _right_in_type right_in;
      typedef uint16_t _right_out_type;
      _right_out_type right_out;

    LinkHeadDeadzonePercentData():
      forward_in(0),
      forward_out(0),
      right_in(0),
      right_out(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->forward_in >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->forward_in >> (8 * 1)) & 0xFF;
      offset += sizeof(this->forward_in);
      *(outbuffer + offset + 0) = (this->forward_out >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->forward_out >> (8 * 1)) & 0xFF;
      offset += sizeof(this->forward_out);
      *(outbuffer + offset + 0) = (this->right_in >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->right_in >> (8 * 1)) & 0xFF;
      offset += sizeof(this->right_in);
      *(outbuffer + offset + 0) = (this->right_out >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->right_out >> (8 * 1)) & 0xFF;
      offset += sizeof(this->right_out);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->forward_in =  ((uint16_t) (*(inbuffer + offset)));
      this->forward_in |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->forward_in);
      this->forward_out =  ((uint16_t) (*(inbuffer + offset)));
      this->forward_out |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->forward_out);
      this->right_in =  ((uint16_t) (*(inbuffer + offset)));
      this->right_in |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->right_in);
      this->right_out =  ((uint16_t) (*(inbuffer + offset)));
      this->right_out |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->right_out);
     return offset;
    }

    virtual const char * getType() override { return "glory_bridge/LinkHeadDeadzonePercentData"; };
    virtual const char * getMD5() override { return "48dd4b8fd1ba64ed9413356aa7d9c742"; };

  };

}
#endif
