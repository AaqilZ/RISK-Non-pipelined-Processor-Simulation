#include "ProgramCounter.h"

void ProgramCounter::
print(){
	std::cout << "*********** Program Counter ***********" << std::endl;
	std::cout << "Current Instruction Address: " << getPC() << std::endl;
}