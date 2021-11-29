#ifndef _ROS_SERVICE_Reset_h
#define _ROS_SERVICE_Reset_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Bool.h"

namespace nowtech_sensor_models
{

static const char RESET[] = "nowtech_sensor_models/Reset";

  class ResetRequest : public ros::Msg
  {
    public:
      typedef std_msgs::Bool _reset_type;
      _reset_type reset;

    ResetRequest():
      reset()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->reset.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->reset.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return RESET; };
    virtual const char * getMD5() override { return "192b1618ba2ef027b56fe4cf66db1afe"; };

  };

  class ResetResponse : public ros::Msg
  {
    public:
      typedef std_msgs::Bool _state_type;
      _state_type state;

    ResetResponse():
      state()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->state.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->state.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return RESET; };
    virtual const char * getMD5() override { return "77ad911625be62b50f7cac9a1a4304ea"; };

  };

  class Reset {
    public:
    typedef ResetRequest Request;
    typedef ResetResponse Response;
  };

}
#endif
