#ifndef _ROS_glory_bridge_LinkHeadGesturesData_h
#define _ROS_glory_bridge_LinkHeadGesturesData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "glory_bridge/LinkHeadBackTiltDelayData.h"
#include "glory_bridge/LinkHeadBackEmergencyData.h"

namespace glory_bridge
{

  class LinkHeadGesturesData : public ros::Msg
  {
    public:
      typedef glory_bridge::LinkHeadBackTiltDelayData _backtiltdelay_type;
      _backtiltdelay_type backtiltdelay;
      typedef glory_bridge::LinkHeadBackEmergencyData _backemergency_type;
      _backemergency_type backemergency;

    LinkHeadGesturesData():
      backtiltdelay(),
      backemergency()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->backtiltdelay.serialize(outbuffer + offset);
      offset += this->backemergency.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->backtiltdelay.deserialize(inbuffer + offset);
      offset += this->backemergency.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "glory_bridge/LinkHeadGesturesData"; };
    virtual const char * getMD5() override { return "bca3878e8137bb70fb9dc8146afe4f81"; };

  };

}
#endif
