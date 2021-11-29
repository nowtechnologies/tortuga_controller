#ifndef _ROS_glory_bridge_LinkHeadBackTiltDelayData_h
#define _ROS_glory_bridge_LinkHeadBackTiltDelayData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace glory_bridge
{

  class LinkHeadBackTiltDelayData : public ros::Msg
  {
    public:
      typedef uint16_t _scantime_type;
      _scantime_type scantime;
      typedef uint16_t _timeout_type;
      _timeout_type timeout;
      typedef uint16_t _x_window_percent_type;
      _x_window_percent_type x_window_percent;

    LinkHeadBackTiltDelayData():
      scantime(0),
      timeout(0),
      x_window_percent(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->scantime >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->scantime >> (8 * 1)) & 0xFF;
      offset += sizeof(this->scantime);
      *(outbuffer + offset + 0) = (this->timeout >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timeout >> (8 * 1)) & 0xFF;
      offset += sizeof(this->timeout);
      *(outbuffer + offset + 0) = (this->x_window_percent >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->x_window_percent >> (8 * 1)) & 0xFF;
      offset += sizeof(this->x_window_percent);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->scantime =  ((uint16_t) (*(inbuffer + offset)));
      this->scantime |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->scantime);
      this->timeout =  ((uint16_t) (*(inbuffer + offset)));
      this->timeout |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->timeout);
      this->x_window_percent =  ((uint16_t) (*(inbuffer + offset)));
      this->x_window_percent |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->x_window_percent);
     return offset;
    }

    virtual const char * getType() override { return "glory_bridge/LinkHeadBackTiltDelayData"; };
    virtual const char * getMD5() override { return "3f09df0dcc290e5828a87e1682bf9651"; };

  };

}
#endif
