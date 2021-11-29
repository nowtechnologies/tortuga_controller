#ifndef _ROS_glory_bridge_LinkHeadBackEmergencyData_h
#define _ROS_glory_bridge_LinkHeadBackEmergencyData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace glory_bridge
{

  class LinkHeadBackEmergencyData : public ros::Msg
  {
    public:
      typedef uint16_t _scantime_type;
      _scantime_type scantime;
      typedef uint16_t _y_amplitude_percent_type;
      _y_amplitude_percent_type y_amplitude_percent;
      typedef bool _y_negative_required_type;
      _y_negative_required_type y_negative_required;

    LinkHeadBackEmergencyData():
      scantime(0),
      y_amplitude_percent(0),
      y_negative_required(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->scantime >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->scantime >> (8 * 1)) & 0xFF;
      offset += sizeof(this->scantime);
      *(outbuffer + offset + 0) = (this->y_amplitude_percent >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->y_amplitude_percent >> (8 * 1)) & 0xFF;
      offset += sizeof(this->y_amplitude_percent);
      union {
        bool real;
        uint8_t base;
      } u_y_negative_required;
      u_y_negative_required.real = this->y_negative_required;
      *(outbuffer + offset + 0) = (u_y_negative_required.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->y_negative_required);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->scantime =  ((uint16_t) (*(inbuffer + offset)));
      this->scantime |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->scantime);
      this->y_amplitude_percent =  ((uint16_t) (*(inbuffer + offset)));
      this->y_amplitude_percent |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->y_amplitude_percent);
      union {
        bool real;
        uint8_t base;
      } u_y_negative_required;
      u_y_negative_required.base = 0;
      u_y_negative_required.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->y_negative_required = u_y_negative_required.real;
      offset += sizeof(this->y_negative_required);
     return offset;
    }

    virtual const char * getType() override { return "glory_bridge/LinkHeadBackEmergencyData"; };
    virtual const char * getMD5() override { return "d88c1b66c0b2a294301bb3ca9efb5ad5"; };

  };

}
#endif
