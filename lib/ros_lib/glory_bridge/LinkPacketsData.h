#ifndef _ROS_glory_bridge_LinkPacketsData_h
#define _ROS_glory_bridge_LinkPacketsData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "glory_bridge/LinkPacketData.h"

namespace glory_bridge
{

  class LinkPacketsData : public ros::Msg
  {
    public:
      typedef glory_bridge::LinkPacketData _hcp_type;
      _hcp_type hcp;
      typedef glory_bridge::LinkPacketData _grcp_type;
      _grcp_type grcp;
      typedef glory_bridge::LinkPacketData _vcp_type;
      _vcp_type vcp;

    LinkPacketsData():
      hcp(),
      grcp(),
      vcp()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->hcp.serialize(outbuffer + offset);
      offset += this->grcp.serialize(outbuffer + offset);
      offset += this->vcp.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->hcp.deserialize(inbuffer + offset);
      offset += this->grcp.deserialize(inbuffer + offset);
      offset += this->vcp.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "glory_bridge/LinkPacketsData"; };
    virtual const char * getMD5() override { return "780fa668fe4cf09461a2f0e6392c35b9"; };

  };

}
#endif
