#include "ProgramCounter.h"
#include "Utilities.h"

void ProgramCounter::
print(){
	std::cout << "*********** Program Counter ***********" << std::endl;
	std::cout << "Current Instruction Address: " << bin2hex(getPC()) << std::endl;
}