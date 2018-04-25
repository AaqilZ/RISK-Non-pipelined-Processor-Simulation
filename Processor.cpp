#include "Processor.h"
#include "Parser.h"
#include "Utilities.h"

using namespace std;

#include <string>

Processor::
Processor() : Unit("Processor") { 
}

void Processor::
process() {
	std::string initialPC =  programCounter.getPC();
  while(stoi(programCounter.getPC()) <= stoi(initialPC)+InstructionData.size()){
    fetch();
    decode();
    execute();
    memory();
    writeback();
  }
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

void Processor::
fetch() { 
	currentInstruction = InstructionData.at(programCounter.getPC());
	std::string currentPC = programCounter.getPC();
	std::string four = "00000000000000000000000000000100";
  aluOne.add(currentPC, four);
}

void Processor::
decode(){
  //Decode:
  //   a. Control gets Instruction. 
  control.setControlLines(currentInstruction);
  //   b. MUX1 gets RegDst and instruction 20-16 and 15-11
  muxRegDist.operate(control.getRegDst(), currentInstruction.getBits(15, 11), currentInstruction.getBits(20, 16));
  //   c. Register things: 
  //       - Register gets RegWrite
  registerFile.setRegWrite(control.getRegDst());
  //       - Read Register 1 gets instruction 25-21
  registerFile.setReadReg1(stoi(bin2dec(currentInstruction.getBits(25, 21))));
  //       - Read Register 2 gets instruction 20-16
  registerFile.setReadReg2(stoi(bin2dec(currentInstruction.getBits(20, 16))));
  //       - Write Register gets MUX1 return thing.
  registerFile.setWriteReg(stoi(bin2dec(muxRegDist.getResult())));
  //   d. Sign extend instruction 15-0 and send it to shift left 2 while
  //      maintaining the number of bits. Send the result of this and 
  //      ALU1 to ALU2.
  signExtendedNum = signExt(currentInstruction.getBits(15, 0));
  aluTwo.operate("0010", aluOne.getALUresult(), shiftLeft2(signExtendedNum, true)); //  alu1Result will magically come from somewhere.
                                                                              // true = maintain number of bits. 
}

void Processor::
execute(){
  // Execute: 
  //   a. MUX2 gets ALUSrc and Read Data 2 and the 32 bit sign extended number
  muxALUSrc.operate(control.getALUSrc(), signExtendedNum, registerFile.getReadData2());
  //   b. ALU3 gets ALU Control and Read Data 1 and result of MUX2
  aluThree.operate(control.getALUControl(), muxALUSrc.getResult(), registerFile.getReadData1());
  //   c. send the result of ALU1 and ALU2 and (branch AND zero from ALU3) 
  //      to MUX5.
  muxBranch.operate((control.getBranch()&&aluThree.getZero()), aluTwo.getALUresult(), aluOne.getALUresult());
  //   d. Shift left 2 takes instruction 25-0 and shifts 2(increasing 2 bits)
  //      and concatenate those 28 bits with the bits from ALU1. Send this(jump
  //      address) and result of MUX5 to MUX4.
  muxJump.operate(control.getJump(), (programCounter.getPC()+shiftLeft2(currentInstruction.getBits(25, 0), false)), muxBranch.getResult());
  //   e. Send result of MUX4 to PC?
  programCounter.setPC(muxJump.getResult());
}