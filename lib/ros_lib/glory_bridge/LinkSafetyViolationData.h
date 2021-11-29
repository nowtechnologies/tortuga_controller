#ifndef _ROS_glory_bridge_LinkSafetyViolationData_h
#define _ROS_glory_bridge_LinkSafetyViolationData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace glory_bridge
{

  class LinkSafetyViolationData : public ros::Msg
  {
    public:
      typedef uint32_t _timestamp_type;
      _timestamp_type timestamp;
      typedef const char* _message_type;
      _message_type message;

    LinkSafetyViolationData():
      timestamp(0),
      message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->timestamp >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timestamp >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timestamp >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timestamp >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timestamp);
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->timestamp =  ((uint32_t) (*(inbuffer + offset)));
      this->timestamp |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timestamp |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timestamp |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timestamp);
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
     return offset;
    }

    virtual const char * getType() override { return "glory_bridge/LinkSafetyViolationData"; };
    virtual const char * getMD5() override { return "494f3a16aac1ce97adad6eb19ca9aec6"; };

  };

}
#endif
