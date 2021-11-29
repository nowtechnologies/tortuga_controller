#ifndef _ROS_glory_bridge_LinkHeadAngleData_h
#define _ROS_glory_bridge_LinkHeadAngleData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace glory_bridge
{

  class LinkHeadAngleData : public ros::Msg
  {
    public:
      typedef uint16_t _forward_type;
      _forward_type forward;
      typedef uint16_t _backward_type;
      _backward_type backward;
      typedef uint16_t _right_type;
      _right_type right;
      typedef uint16_t _left_type;
      _left_type left;

    LinkHeadAngleData():
      forward(0),
      backward(0),
      right(0),
      left(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->forward >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->forward >> (8 * 1)) & 0xFF;
      offset += sizeof(this->forward);
      *(outbuffer + offset + 0) = (this->backward >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->backward >> (8 * 1)) & 0xFF;
      offset += sizeof(this->backward);
      *(outbuffer + offset + 0) = (this->right >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->right >> (8 * 1)) & 0xFF;
      offset += sizeof(this->right);
      *(outbuffer + offset + 0) = (this->left >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->left >> (8 * 1)) & 0xFF;
      offset += sizeof(this->left);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->forward =  ((uint16_t) (*(inbuffer + offset)));
      this->forward |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->forward);
      this->backward =  ((uint16_t) (*(inbuffer + offset)));
      this->backward |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->backward);
      this->right =  ((uint16_t) (*(inbuffer + offset)));
      this->right |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->right);
      this->left =  ((uint16_t) (*(inbuffer + offset)));
      this->left |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->left);
     return offset;
    }

    virtual const char * getType() override { return "glory_bridge/LinkHeadAngleData"; };
    virtual const char * getMD5() override { return "130a0665f0cd26c0457f0aae1f99b277"; };

  };

}
#endif
