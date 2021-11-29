#ifndef _ROS_glory_bridge_LinkPersistenceData_h
#define _ROS_glory_bridge_LinkPersistenceData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace glory_bridge
{

  class LinkPersistenceData : public ros::Msg
  {
    public:
      typedef uint16_t _pan_type;
      _pan_type pan;
      typedef uint16_t _address_type;
      _address_type address;

    LinkPersistenceData():
      pan(0),
      address(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->pan >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pan >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pan);
      *(outbuffer + offset + 0) = (this->address >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->address >> (8 * 1)) & 0xFF;
      offset += sizeof(this->address);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->pan =  ((uint16_t) (*(inbuffer + offset)));
      this->pan |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->pan);
      this->address =  ((uint16_t) (*(inbuffer + offset)));
      this->address |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->address);
     return offset;
    }

    virtual const char * getType() override { return "glory_bridge/LinkPersistenceData"; };
    virtual const char * getMD5() override { return "bde6088398a70bbc324f51b0410e3654"; };

  };

}
#endif
