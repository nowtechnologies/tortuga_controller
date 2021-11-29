#ifndef _ROS_SERVICE_SetCharge_h
#define _ROS_SERVICE_SetCharge_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Bool.h"
#include "std_msgs/Float32.h"

namespace nowtech_sensor_models
{

static const char SETCHARGE[] = "nowtech_sensor_models/SetCharge";

  class SetChargeRequest : public ros::Msg
  {
    public:
      typedef std_msgs::Float32 _charge_type;
      _charge_type charge;

    SetChargeRequest():
      charge()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->charge.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->charge.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return SETCHARGE; };
    virtual const char * getMD5() override { return "80f59c2acac1a7362fdf8f840f6184ab"; };

  };

  class SetChargeResponse : public ros::Msg
  {
    public:
      typedef std_msgs::Bool _set_type;
      _set_type set;

    SetChargeResponse():
      set()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->set.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->set.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return SETCHARGE; };
    virtual const char * getMD5() override { return "e32d9ae87ed2d440e676d16561c582ef"; };

  };

  class SetCharge {
    public:
    typedef SetChargeRequest Request;
    typedef SetChargeResponse Response;
  };

}
#endif
