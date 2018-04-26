#include "ProgramCounter.h"
#include "Utilities.h"

void ProgramCounter::
print(){
	if(writeToFile){
		o << "*********** Program Counter ***********" << std::endl;
		o << "Current Instruction Address: " << bin2hex(getPC()) << std::endl;
	}
	std::cout << "*********** Program Counter ***********" << std::endl;
	std::cout << "Current Instruction Address: " << bin2hex(getPC()) << std::endl;
}