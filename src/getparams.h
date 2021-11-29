#ifndef _TORTUGA_GET_ROSPARAMS_UTILS_H_
#define _TORTUGA_GET_ROSPARAMS_UTILS_H_

#define GET_PARAM_RETRIES 1

float getBoolParam(ros::NodeHandle* nh, String name, bool defValue, bool loadDefault=false){
  bool paramReceived = false;
  uint8_t retries = GET_PARAM_RETRIES;
  bool variable = false;
  if (loadDefault){
    String msg = "Default loaded for "+name+": "+String(defValue);
    nh->logwarn(msg.c_str());
    return defValue;
  }
  else {
    while (!paramReceived){
      nh->spinOnce();
      paramReceived = nh->getParam(name.c_str(), &variable, 1, 100);
      if (retries<1) {
        String msg = "Default loaded for "+name+": "+String(defValue);
        nh->logwarn(msg.c_str());
        return defValue;
        break;
      }
      retries--;
    }
    String msg = name+": "+String(variable);
    nh->loginfo(msg.c_str());
    return variable;
  }
}

float getFloatParam(ros::NodeHandle* nh, String name, float defValue, bool loadDefault){
  bool paramReceived = false;
  uint8_t retries = GET_PARAM_RETRIES;
  float variable = 0;
  if (loadDefault){
    String msg = "Default loaded for "+name+": "+String(defValue);
    nh->logwarn(msg.c_str());
    return defValue;
  }
  else {
    while (!paramReceived){
      nh->spinOnce();
      paramReceived = nh->getParam(name.c_str(), &variable, 1, 100);
      if (retries<1) {
        String msg = "Default loaded for "+name+": "+String(defValue);
        nh->logwarn(msg.c_str());
        return defValue;
        break;
      }
      retries--;
    }
    String msg = name+": "+String(variable);
    nh->loginfo(msg.c_str());
    return variable;
  }
}

String getStringParam(ros::NodeHandle* nh, String name, String defValue, bool loadDefault=false){
  bool paramReceived = false;
  uint8_t retries = GET_PARAM_RETRIES;
  char charBuffer[50] = "";
  char *charBuffer_ptr[1] = {charBuffer};
  if (loadDefault){
    String msg = "Default loaded for "+name+": "+ defValue;
    nh->logwarn(msg.c_str());
    return defValue;
  }
  else {
    while (!paramReceived){
      nh->spinOnce();
      paramReceived = nh->getParam(name.c_str(), charBuffer_ptr, 1, 100);
      if (retries<1) {
        String msg = "Default loaded for "+name+": "+ defValue;
        nh->logwarn(msg.c_str());
        return defValue;
        break;
      }
      retries--;
    }
    String msg = name+": "+ charBuffer;
    nh->loginfo(msg.c_str());
    return charBuffer;
  }
}

#endif
