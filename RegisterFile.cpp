#include "RegisterFile.h"
#include "Utilities.h"

void RegisterFile::
print(){
	std::cout << "*********** Register File ***********" << std::endl;
	std::cout << "---Inputs---" << std::endl;
	std::cout << "Read  Register 1:" << getReadReg1() << std::endl;
	std::cout << "Read  Register 2:" << getReadReg2() << std::endl;
	std::cout << "Write Register  :" << getReadReg2() << std::endl;
	std::cout << "Write Data 1:" << bin2hex(getWriteData()) << std::endl;
	std::cout << "---Outputs---" << std::endl;
	std::cout << "Read  Data 1:" << bin2hex(getWriteData()) << std::endl;
	std::cout << "Read  Data 2:" << bin2hex(getWriteData()) << std::endl;
}