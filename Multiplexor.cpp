#include "Multiplexor.h"
#include "Utilities.h"

std::string Multiplexor::
operate(bool control, std::string arg1, std::string arg2) {
	// save variables for printing
  option1 = arg1;
  option2 = arg2;
  controlSignal = control;

  // std::cout << "arg1 " << option1 << std::endl;
  // std::cout << "arg2 " << option2 << std::endl;
  // std::cout << "control " << controlSignal << std::endl;

  // based on the control signal, return either arg1 or arg2
  if(control){
  	result = bin2hex(arg1);
    // std::cout << "control true result: " << result << std::endl;
    return result;
  }
  else{
  	result = bin2hex(arg2);
    // std::cout << "control false result: " << result << std::endl;
    return result;
  }
}

void Multiplexor::
print(){
  switch(getUnitNum()){
    case 1 :
      std::cout << "*********** MUX 1 ***********" << std::endl;
      break;
    case 2 :
      std::cout << "*********** MUX 2 ***********" << std::endl;
      break;
    case 3 :
      std::cout << "*********** MUX 3 ***********" << std::endl;
      break;
    case 4 :
      std::cout << "*********** MUX 4 ***********" << std::endl;
      break;
    case 5 :
      std::cout << "*********** MUX 5 ***********" << std::endl;
      break;
  }

  std::cout << "---Inputs---" << std::endl;
  std::cout << "Control Signal: " << controlSignal << std::endl;
  std::cout << "Option 1: " << option1 << std::endl;
  std::cout << "Option 2: " << option2 << std::endl;
  std::cout << "---Outputs---" << std::endl;
  std::cout << "Selected: " << result << std::endl << std::endl;
}
