#include "Processor.h"
#include "Parser.h"

using namespace std;

#include <string>

Processor::
Processor() : Unit("Processor") {

}

void Processor::
print(){
	///@TODO Print instruction memory
	std::cout << "*********** Data Memory ***********" << std::endl;
  for (std::pair<std::string, std::string> element : MemoryData)
	{
		std::cout << element.first << " : " << element.second << std::endl << std::endl;
	}

	std::cout << "*********** Register Contents ***********" << std::endl;
	int regCount = 0;
	for(auto i = registerContents.begin(); i != registerContents.end(); ++i)
  {
  	std::cout << "$" << regCount << " : " << *i << std::endl << std::endl;
  	regCount++;
  }

  aluOne.print();
  aluTwo.print();
  aluThree.print();
  muxRegDist.print();
  muxJump.print();
  muxBranch.print();
  muxMemToReg.print();
  muxALUSrc.print();
  control.print();
  registerFile.print();
  programCounter.print();
}