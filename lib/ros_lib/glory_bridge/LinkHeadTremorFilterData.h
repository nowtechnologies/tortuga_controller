#ifndef _ROS_glory_bridge_LinkHeadTremorFilterData_h
#define _ROS_glory_bridge_LinkHeadTremorFilterData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace glory_bridge
{

  class LinkHeadTremorFilterData : public ros::Msg
  {
    public:
      typedef uint16_t _ratio_type;
      _ratio_type ratio;

    LinkHeadTremorFilterData():
      ratio(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->ratio >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ratio >> (8 * 1)) & 0xFF;
      offset += sizeof(this->ratio);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->ratio =  ((uint16_t) (*(inbuffer + offset)));
      this->ratio |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->ratio);
     return offset;
    }

    virtual const char * getType() override { return "glory_bridge/LinkHeadTremorFilterData"; };
    virtual const char * getMD5() override { return "ff9a1e2e21df4493a9a8e274d26323f2"; };

  };

}
#endif
