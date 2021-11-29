#ifndef _ROS_glory_bridge_LinkMainStateMachineData_h
#define _ROS_glory_bridge_LinkMainStateMachineData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace glory_bridge
{

  class LinkMainStateMachineData : public ros::Msg
  {
    public:
      typedef const char* _current_state_type;
      _current_state_type current_state;
      typedef const char* _last_event_type;
      _last_event_type last_event;

    LinkMainStateMachineData():
      current_state(""),
      last_event("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_current_state = strlen(this->current_state);
      varToArr(outbuffer + offset, length_current_state);
      offset += 4;
      memcpy(outbuffer + offset, this->current_state, length_current_state);
      offset += length_current_state;
      uint32_t length_last_event = strlen(this->last_event);
      varToArr(outbuffer + offset, length_last_event);
      offset += 4;
      memcpy(outbuffer + offset, this->last_event, length_last_event);
      offset += length_last_event;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_current_state;
      arrToVar(length_current_state, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_current_state; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_current_state-1]=0;
      this->current_state = (char *)(inbuffer + offset-1);
      offset += length_current_state;
      uint32_t length_last_event;
      arrToVar(length_last_event, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_last_event; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_last_event-1]=0;
      this->last_event = (char *)(inbuffer + offset-1);
      offset += length_last_event;
     return offset;
    }

    virtual const char * getType() override { return "glory_bridge/LinkMainStateMachineData"; };
    virtual const char * getMD5() override { return "61dd19384d6570701cee6ea8f762e902"; };

  };

}
#endif
