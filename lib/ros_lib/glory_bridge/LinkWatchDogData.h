#ifndef _ROS_glory_bridge_LinkWatchDogData_h
#define _ROS_glory_bridge_LinkWatchDogData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace glory_bridge
{

  class LinkWatchDogData : public ros::Msg
  {
    public:
      typedef uint16_t _registered_threads_type;
      _registered_threads_type registered_threads;

    LinkWatchDogData():
      registered_threads(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->registered_threads >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->registered_threads >> (8 * 1)) & 0xFF;
      offset += sizeof(this->registered_threads);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->registered_threads =  ((uint16_t) (*(inbuffer + offset)));
      this->registered_threads |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->registered_threads);
     return offset;
    }

    virtual const char * getType() override { return "glory_bridge/LinkWatchDogData"; };
    virtual const char * getMD5() override { return "96f2b6d3b08c67c1bd793c0a52ebf317"; };

  };

}
#endif
