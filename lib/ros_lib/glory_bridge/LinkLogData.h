#ifndef _ROS_glory_bridge_LinkLogData_h
#define _ROS_glory_bridge_LinkLogData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "glory_bridge/LinkSystemData.h"
#include "glory_bridge/LinkPersistenceData.h"
#include "glory_bridge/LinkWatchDogData.h"
#include "glory_bridge/LinkBlackBoxData.h"
#include "glory_bridge/LinkStateMachineData.h"
#include "glory_bridge/LinkSelfTestData.h"
#include "glory_bridge/LinkPacketsData.h"
#include "glory_bridge/LinkUserFeedbackData.h"
#include "glory_bridge/LinkHeadDriveData.h"
#include "glory_bridge/LinkSafetyViolationData.h"

namespace glory_bridge
{

  class LinkLogData : public ros::Msg
  {
    public:
      typedef glory_bridge::LinkSystemData _system_type;
      _system_type system;
      typedef glory_bridge::LinkPersistenceData _persistence_type;
      _persistence_type persistence;
      typedef glory_bridge::LinkWatchDogData _watchdog_type;
      _watchdog_type watchdog;
      typedef glory_bridge::LinkBlackBoxData _blackbox_type;
      _blackbox_type blackbox;
      typedef glory_bridge::LinkStateMachineData _statemachine_type;
      _statemachine_type statemachine;
      typedef glory_bridge::LinkSelfTestData _selftest_type;
      _selftest_type selftest;
      typedef glory_bridge::LinkPacketsData _packets_type;
      _packets_type packets;
      typedef glory_bridge::LinkUserFeedbackData _userfeedback_type;
      _userfeedback_type userfeedback;
      typedef glory_bridge::LinkHeadDriveData _headdrive_type;
      _headdrive_type headdrive;
      typedef glory_bridge::LinkSafetyViolationData _safetyviolation_type;
      _safetyviolation_type safetyviolation;

    LinkLogData():
      system(),
      persistence(),
      watchdog(),
      blackbox(),
      statemachine(),
      selftest(),
      packets(),
      userfeedback(),
      headdrive(),
      safetyviolation()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->system.serialize(outbuffer + offset);
      offset += this->persistence.serialize(outbuffer + offset);
      offset += this->watchdog.serialize(outbuffer + offset);
      offset += this->blackbox.serialize(outbuffer + offset);
      offset += this->statemachine.serialize(outbuffer + offset);
      offset += this->selftest.serialize(outbuffer + offset);
      offset += this->packets.serialize(outbuffer + offset);
      offset += this->userfeedback.serialize(outbuffer + offset);
      offset += this->headdrive.serialize(outbuffer + offset);
      offset += this->safetyviolation.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->system.deserialize(inbuffer + offset);
      offset += this->persistence.deserialize(inbuffer + offset);
      offset += this->watchdog.deserialize(inbuffer + offset);
      offset += this->blackbox.deserialize(inbuffer + offset);
      offset += this->statemachine.deserialize(inbuffer + offset);
      offset += this->selftest.deserialize(inbuffer + offset);
      offset += this->packets.deserialize(inbuffer + offset);
      offset += this->userfeedback.deserialize(inbuffer + offset);
      offset += this->headdrive.deserialize(inbuffer + offset);
      offset += this->safetyviolation.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "glory_bridge/LinkLogData"; };
    virtual const char * getMD5() override { return "04e433fb13e7e51bda2d1f3d4d37ce88"; };

  };

}
#endif
