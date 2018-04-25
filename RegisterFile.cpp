#include "RegisterFile.h"
#include "Utilities.h"

void RegisterFile::
print(){
	std::cout << "*********** Register File ***********" << std::endl;
	std::cout << "---Inputs---" << std::endl;
	std::cout << "Read  Register 1:" << readReg1 << std::endl;
	std::cout << "Read  Register 2:" << readReg2 << std::endl;
	std::cout << "Write Register  :" << writeReg << std::endl;
	std::cout << "Write Data 1:" << writeData << std::endl;
	std::cout << "---Outputs---" << std::endl;
	std::cout << "Read  Data 1:" << readData1 << std::endl;
	std::cout << "Read  Data 2:" << readData2 << std::endl;
}