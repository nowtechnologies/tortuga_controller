#ifndef _ROS_glory_bridge_LinkHeadDriveData_h
#define _ROS_glory_bridge_LinkHeadDriveData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "glory_bridge/LinkHeadAngleData.h"
#include "glory_bridge/LinkHeadDeadzonePercentData.h"
#include "glory_bridge/LinkHeadTremorFilterData.h"
#include "glory_bridge/LinkHeadGesturesData.h"
#include "glory_bridge/LinkHeadPolarityData.h"

namespace glory_bridge
{

  class LinkHeadDriveData : public ros::Msg
  {
    public:
      typedef glory_bridge::LinkHeadAngleData _drive_angle_type;
      _drive_angle_type drive_angle;
      typedef glory_bridge::LinkHeadAngleData _safety_angle_type;
      _safety_angle_type safety_angle;
      typedef glory_bridge::LinkHeadDeadzonePercentData _deadzone_percent_type;
      _deadzone_percent_type deadzone_percent;
      typedef glory_bridge::LinkHeadTremorFilterData _tremor_type;
      _tremor_type tremor;
      typedef glory_bridge::LinkHeadGesturesData _gestures_type;
      _gestures_type gestures;
      typedef glory_bridge::LinkHeadPolarityData _polarity_type;
      _polarity_type polarity;

    LinkHeadDriveData():
      drive_angle(),
      safety_angle(),
      deadzone_percent(),
      tremor(),
      gestures(),
      polarity()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->drive_angle.serialize(outbuffer + offset);
      offset += this->safety_angle.serialize(outbuffer + offset);
      offset += this->deadzone_percent.serialize(outbuffer + offset);
      offset += this->tremor.serialize(outbuffer + offset);
      offset += this->gestures.serialize(outbuffer + offset);
      offset += this->polarity.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->drive_angle.deserialize(inbuffer + offset);
      offset += this->safety_angle.deserialize(inbuffer + offset);
      offset += this->deadzone_percent.deserialize(inbuffer + offset);
      offset += this->tremor.deserialize(inbuffer + offset);
      offset += this->gestures.deserialize(inbuffer + offset);
      offset += this->polarity.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "glory_bridge/LinkHeadDriveData"; };
    virtual const char * getMD5() override { return "d79e78aa3e5b26ee20f4fe412b62e9e5"; };

  };

}
#endif
