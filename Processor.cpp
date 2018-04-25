#include "Processor.h"
#include "Parser.h"
#include "Utilities.h"
#include <iostream>

using namespace std;

#include <string>

Processor::
Processor() : Unit("Processor") { 
}

void Processor::
process() {
  std::string initialPC =  programCounter.getPC();
  // cout << initialPC << endl;
  while(stoi(hex2dec(programCounter.getPC())) <= (stoi(hex2dec(initialPC))+4*(int)InstructionData.size())){
    fetch();
    decode();
    execute();
    memory();
    writeback();
    
    cout << hex2dec(programCounter.getPC()) << endl;
  }
}


void Processor::
fetch() { 
  // cout << programCounter.getPC() << endl;
  
  // for(auto iter = InstructionData.begin(); iter != InstructionData.end(); ++iter){
  //   cout << "\t\t" << iter->first << " : " << iter->second.getOpcode() << endl;
  // }

  currentInstruction = InstructionData.at(programCounter.getPC());
  std::string currentPC = programCounter.getPC();
  std::string four = "00000000000000000000000000000100";
  aluOne.add(currentPC, bin2hex(four));
  
}

void Processor::
decode(){
  //Decode:
  //   a. Control gets Instruction. 
  cout << "Decode 1" << endl;
  control.setControlLines(currentInstruction);
  cout << "Decode 2" << endl;
  //   b. MUX1 gets RegDst and instruction 20-16 and 15-11
  // control.print();

  // TODO make an operate function for registerFile and put this logic inside
  muxRegDist.operate(control.getRegDst(), registerContents.at(stoi(bin2dec(currentInstruction.getBits(15, 11)))), registerContents.at(stoi(bin2dec(currentInstruction.getBits(20, 16)))));


  cout << "Decode 3" << endl;
  //   c. Register things: 
  //       - Register gets RegWrite
  registerFile.setRegWrite(control.getRegDst());

  cout << "Decode 4" << endl;
  //       - Read Register 1 gets instruction 25-21
  registerFile.setReadReg1(stoi(bin2dec(currentInstruction.getBits(25, 21))));
  registerFile.setReadData1(registerContents.at(registerFile.getReadReg1()));

  cout << "Decode 5" << endl;
  //       - Read Register 2 gets instruction 20-16
  registerFile.setReadReg2(stoi(bin2dec(currentInstruction.getBits(20, 16))));
  registerFile.setReadData2(registerContents.at(registerFile.getReadReg2()));
  cout << "Decode 6" << endl;
  //       - Write Register gets MUX1 return thing.
  if(registerFile.getRegWrite()){
    registerFile.setWriteReg(stoi(bin2dec(muxRegDist.getResult())));
  }
  cout << "Decode 7" << endl;

  // registerFile.print();
  //   d. Sign extend instruction 15-0 and send it to shift left 2 while
  //      maintaining the number of bits. Send the result of this and 
  //      ALU1 to ALU2.
  signExtendedNum = signExt(currentInstruction.getBits(15, 0));
  // cout << "Decode 8" << endl;
  // cout << "alu 1 result: " << aluOne.getALUresult() << endl;
  // cout << "sl2 : " << shiftLeft2(signExtendedNum, true) << endl;

  // cout << "Printing ALU1 result" << aluOne.getALUresult() << endl;
  // cout << bin2hex(shiftLeft2(signExtendedNum, true)) << endl;

  string addCode = "0010";
  aluTwo.operate(addCode, aluOne.getALUresult(), bin2hex(shiftLeft2(signExtendedNum, true)));   
  // aluTwo.print();
  cout << "Decode 9  Good through here" << endl;
                                                                              // true = maintain number of bits. 
}

void Processor::
execute(){
  // Execute: 
  //   a. MUX2 gets ALUSrc and Read Data 2 and the 32 bit sign extended number
  cout << "signExtNum: " << signExtendedNum << endl;
  cout << "readData: " << registerFile.getReadData2() << endl;
  muxALUSrc.operate(control.getALUSrc(), signExtendedNum, registerFile.getReadData2());
  cout << "Execute 1" << endl;
  
  //   b. ALU3 gets ALU Control and Read Data 1 and result of MUX2
  aluThree.setControl(control.getALUOp0(), control.getALUOp1(), currentInstruction.getFuncField());
  cout << "Execute 2" << endl;  
  cout << "aluMux: " << muxALUSrc.getResult() << endl;
  cout << "registerFile: " << registerFile.getReadData1() << endl;
  aluThree.operate(control.getALUControl(), muxALUSrc.getResult(), registerFile.getReadData1());
  //aluThree.print();
  cout << "Execute 3" << endl;
  //   c. send the result of ALU1 and ALU2 and (branch AND zero from ALU3) 
  //      to MUX5.
  muxBranch.operate((control.getBranch()&&aluThree.getZero()), aluTwo.getALUresult(), aluOne.getALUresult());
  //   d. Shift left 2 takes instruction 25-0 and shifts 2(increasing 2 bits)
  //      and concatenate those 28 bits with the bits from ALU1. Send this(jump
  //      address) and result of MUX5 to MUX4.
  cout << "Execute 4" << endl;
  muxJump.operate(control.getJump(), (programCounter.getPC()+shiftLeft2(currentInstruction.getBits(25, 0), false)), muxBranch.getResult());
  //   e. Send result of MUX4 to PC?
  cout << "Execute 5" << endl;
  programCounter.setPC(muxJump.getResult());
  cout << "Execute 6" << endl;  
}

void Processor::
memory(){
  // Memory:
  //   a. Data Memory gets MemWrite and MemRead and Result of ALU3(address)
  //      and read data2(write data).
  /// @TODO DATA MEMORY NEEDS TO BE DONE 
  cout << "Memory 0" << endl;

  if (control.getMemWrite()) {
    cout << "Memory 1" << endl;  
    // do the things
    cout << aluThree.getALUresult() << endl;
    cout << bin2hex(aluThree.getALUresult()) << endl;
    MemoryData[bin2hex(aluThree.getALUresult())] = registerFile.getReadData2();
    cout << "Memory 2" << endl;
  }
  cout << "Memory 3" << endl;
}

void Processor::
writeback(){
  cout << "Writeback 0" << endl;
  // Writeback:
  //   b. MUX3 gets MemtoReg and Read data(from data memory) and result of ALU3
  ///@TODO DO WHAT IS WRITTEN ABOVE  
  cout << aluThree.getALUresult() << endl;
  cout << bin2hex(aluThree.getALUresult()) << endl;
  muxMemToReg.operate(control.getMemToReg(), MemoryData.at(bin2hex(aluThree.getALUresult())), aluThree.getALUresult());
  cout << "Writeback 1" << endl;
  

  //   a. Write data in register file gets the result of MUX3.
  ///@TODO need to have functionality in registerFile to check boolean before 
  //       writing to the write data reg
  registerFile.setWriteData(muxMemToReg.getResult());
  cout << "Writeback 2" << endl;

  registerContents[registerFile.getWriteReg()] = registerFile.getWriteData();
  cout << "Writeback 3" << endl;
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
