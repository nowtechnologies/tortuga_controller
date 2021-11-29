#ifndef _ROS_glory_bridge_LinkSelfTestData_h
#define _ROS_glory_bridge_LinkSelfTestData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace glory_bridge
{

  class LinkSelfTestData : public ros::Msg
  {
    public:
      typedef bool _bno_ok_type;
      _bno_ok_type bno_ok;
      typedef bool _truerng_ok_type;
      _truerng_ok_type truerng_ok;
      typedef bool _persistence_ok_type;
      _persistence_ok_type persistence_ok;

    LinkSelfTestData():
      bno_ok(0),
      truerng_ok(0),
      persistence_ok(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_bno_ok;
      u_bno_ok.real = this->bno_ok;
      *(outbuffer + offset + 0) = (u_bno_ok.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->bno_ok);
      union {
        bool real;
        uint8_t base;
      } u_truerng_ok;
      u_truerng_ok.real = this->truerng_ok;
      *(outbuffer + offset + 0) = (u_truerng_ok.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->truerng_ok);
      union {
        bool real;
        uint8_t base;
      } u_persistence_ok;
      u_persistence_ok.real = this->persistence_ok;
      *(outbuffer + offset + 0) = (u_persistence_ok.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->persistence_ok);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_bno_ok;
      u_bno_ok.base = 0;
      u_bno_ok.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->bno_ok = u_bno_ok.real;
      offset += sizeof(this->bno_ok);
      union {
        bool real;
        uint8_t base;
      } u_truerng_ok;
      u_truerng_ok.base = 0;
      u_truerng_ok.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->truerng_ok = u_truerng_ok.real;
      offset += sizeof(this->truerng_ok);
      union {
        bool real;
        uint8_t base;
      } u_persistence_ok;
      u_persistence_ok.base = 0;
      u_persistence_ok.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->persistence_ok = u_persistence_ok.real;
      offset += sizeof(this->persistence_ok);
     return offset;
    }

    virtual const char * getType() override { return "glory_bridge/LinkSelfTestData"; };
    virtual const char * getMD5() override { return "4de10a6d4fd9f81fb15b31f6d85eefb8"; };

  };

}
#endif
