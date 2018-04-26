#include "RegisterFile.h"
#include "Utilities.h"

void RegisterFile::
print(){
	if(writeToFile){
		o << "*********** Register File ***********" << std::endl;
		o << "---Inputs---" << std::endl;
		o << "Read  Register 1:" << readReg1 << std::endl;
		o << "Read  Register 2:" << readReg2 << std::endl;
		o << "Write Register  :" << writeReg << std::endl;
		o << "Write Data 1:" << writeData << std::endl;
		o << "---Outputs---" << std::endl;
		o << "Read  Data 1:" << readData1 << std::endl;
		o << "Read  Data 2:" << readData2 << std::endl;
	}
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