#include "Multiplexor.h"

std::string Multiplexor::
operate(bool control, std::string& arg1, std::string& arg2) {
	// save variables for printing
	setControlSignal(control);
	setOption1(arg1);
	setOption2(arg2);

  // based on the control signal, return either arg1 or arg2
  if(control){
  	setResult(arg1);
    return arg1;
  }
  else{
  	setResult(arg2);
    return arg2;
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