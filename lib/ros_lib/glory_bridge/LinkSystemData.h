#ifndef _ROS_glory_bridge_LinkSystemData_h
#define _ROS_glory_bridge_LinkSystemData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "glory_bridge/LinkVersionData.h"

namespace glory_bridge
{

  class LinkSystemData : public ros::Msg
  {
    public:
      typedef glory_bridge::LinkVersionData _version_type;
      _version_type version;

    LinkSystemData():
      version()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->version.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->version.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "glory_bridge/LinkSystemData"; };
    virtual const char * getMD5() override { return "57b4bf3c2c02b7ef109e9e395b59970f"; };

  };

}
#endif
