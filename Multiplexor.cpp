#include "Multiplexor.h"

std::string Multiplexor::
operate(std::string control, std::string& arg1, std::string& arg2) {
  // based on the control signal, return either arg1 or arg2
  if(control == "1")
    return arg1;
  else
    return arg2;
}