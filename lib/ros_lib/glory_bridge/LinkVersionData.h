#ifndef _ROS_glory_bridge_LinkVersionData_h
#define _ROS_glory_bridge_LinkVersionData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace glory_bridge
{

  class LinkVersionData : public ros::Msg
  {
    public:
      typedef uint16_t _major_n_type;
      _major_n_type major_n;
      typedef uint16_t _minor_n_type;
      _minor_n_type minor_n;
      typedef uint16_t _fix_type;
      _fix_type fix;
      typedef uint16_t _build_type;
      _build_type build;

    LinkVersionData():
      major_n(0),
      minor_n(0),
      fix(0),
      build(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->major_n >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->major_n >> (8 * 1)) & 0xFF;
      offset += sizeof(this->major_n);
      *(outbuffer + offset + 0) = (this->minor_n >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->minor_n >> (8 * 1)) & 0xFF;
      offset += sizeof(this->minor_n);
      *(outbuffer + offset + 0) = (this->fix >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fix >> (8 * 1)) & 0xFF;
      offset += sizeof(this->fix);
      *(outbuffer + offset + 0) = (this->build >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->build >> (8 * 1)) & 0xFF;
      offset += sizeof(this->build);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->major_n =  ((uint16_t) (*(inbuffer + offset)));
      this->major_n |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->major_n);
      this->minor_n =  ((uint16_t) (*(inbuffer + offset)));
      this->minor_n |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->minor_n);
      this->fix =  ((uint16_t) (*(inbuffer + offset)));
      this->fix |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->fix);
      this->build =  ((uint16_t) (*(inbuffer + offset)));
      this->build |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->build);
     return offset;
    }

    virtual const char * getType() override { return "glory_bridge/LinkVersionData"; };
    virtual const char * getMD5() override { return "c5958fba090b49cf36095dece7fa31f4"; };

  };

}
#endif
