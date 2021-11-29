#ifndef _ROS_glory_bridge_LinkStateMachineData_h
#define _ROS_glory_bridge_LinkStateMachineData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "glory_bridge/LinkMainStateMachineData.h"

namespace glory_bridge
{

  class LinkStateMachineData : public ros::Msg
  {
    public:
      typedef glory_bridge::LinkMainStateMachineData _main_type;
      _main_type main;

    LinkStateMachineData():
      main()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->main.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->main.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "glory_bridge/LinkStateMachineData"; };
    virtual const char * getMD5() override { return "df935cae74e60320c98e4c41c4d9a2f0"; };

  };

}
#endif
