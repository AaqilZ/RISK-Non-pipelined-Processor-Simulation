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
  print();
  int counter = 0;
  std::string initialPC =  programCounter.getPC();
  // cout << initialPC << endl;
// cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++Initial PC: " << stoi(hex2dec(programCounter.getPC())) << endl;
// cout << "MAX PC: " <<(stoi(hex2dec(initialPC))+4*(int)InstructionData.size()) << endl;
  while(stoi(hex2dec(programCounter.getPC())) < (stoi(hex2dec(initialPC))+4*(int)InstructionData.size())){
    if(singleStep) cin.get();
    // cout << "########################## 1 #############################" << endl;
    fetch();
    // cout << "########################## 2 #############################" << endl;
    decode();
    // cout << "########################## 3 #############################" << endl;
    execute();
    // cout << "########################## 4 #############################" << endl;
    memory();
    // cout << "########################## 5 #############################" << endl;
    writeback();
    // cout << "########################## 6 #############################" << endl;
    counter++;


    //muxJump.print();


    // cout << hex2dec(programCounter.getPC()) << endl;
    cout << "--------------------------------------------------------------------------------------------" << endl;
    cout << "--------------------------------------------------------------------------------------------" << endl;
    cout << "--------------------------------------------------------------------------------------------" << endl;
    cout << "-----------------------||||||||||<<<<<<<" + to_string(counter) + ">>>>>>>|||||||||-----------------------------------" << endl;
    cout << "--------------------------------------------------------------------------------------------" << endl;
    cout << "--------------------------------------------------------------------------------------------" << endl;
    cout << "--------------------------------------------------------------------------------------------" << endl;
  }
  print();
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
  // cout << "Decode 1" << endl;
  control.setControlLines(currentInstruction);
  // cout << "Decode 2" << endl;
  //   b. MUX1 gets RegDst and instruction 20-16 and 15-11
  // control.print();

  // TODO make an operate function for registerFile and put this logic inside

  // cout << "\t\t\t testing the first register now: " << (currentInstruction.getBits(15, 11)) << endl;
  muxRegDist.operate(control.getRegDst(), bin2hex(currentInstruction.getBits(15, 11)), bin2hex(currentInstruction.getBits(20, 16)));

  // muxRegDist.print();

  // cout << "Decode 3" << endl;
  //   c. Register things: 
  //       - Register gets RegWrite
  // cout << "///////////////////////////////////////////////////" << control.getRegDst() << endl;
  registerFile.setRegWrite(control.getRegWrite());

  // cout << "Decode 4" << endl;
  //       - Read Register 1 gets instruction 25-21
  registerFile.setReadReg1(stoi(bin2dec(currentInstruction.getBits(25, 21))));
  cout << "registerFile.getReadReg1(): " << registerFile.getReadReg1() << endl;
  cout << "registerContents.at(registerFile.getReadReg1()): " << registerContents.at(registerFile.getReadReg1()) << endl;
  registerFile.setReadData1(registerContents.at(registerFile.getReadReg1()));

  // cout << "Decode 5" << endl;
  //       - Read Register 2 gets instruction 20-16
  registerFile.setReadReg2(stoi(bin2dec(currentInstruction.getBits(20, 16))));
  registerFile.setReadData2(registerContents.at(registerFile.getReadReg2()));
  // cout << "Decode 6" << endl;
  //       - Write Register gets MUX1 return thing.

    // cout << "REGISTER BEING SET: " << stoi(bin2dec(muxRegDist.getResult())) << endl << endl;
    // muxRegDist.print();

    // cout << "\t\t\tThis is what is wrong with life: ~setWrite CURRENT INSTRUCTION  = " << currentInstruction.getRd() << endl;
    
    // cout << "-______________------__________ONLUU THING THAT MATTERS IN LIFE " << stoi(hex2dec(muxRegDist.getResult())) << endl;

    registerFile.setWriteReg(stoi(hex2dec(muxRegDist.getResult())));

    // registerFile.setWriteReg(stoi(bin2dec(muxRegDist.getResult())));
  
  // cout << "Decode 7" << endl;

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

  // cout << "\t\t\t LETS CHECK THAT THIS IS VALID HEX: " <<aluOne.getALUresult()<<endl; 

  aluTwo.operate(addCode, aluOne.getALUresult(), bin2hex(shiftLeft2(signExtendedNum, true)));   
  // aluTwo.print();
  // cout << "Decode 9  Good through here" << endl;
  // true = maintain number of bits. 
}

void Processor::
execute(){
  // Execute: 
  //   a. MUX2 gets ALUSrc and Read Data 2 and the 32 bit sign extended number
  //cout << "signExtNum: " << signExtendedNum << endl;
  //cout << "readData: " << registerFile.getReadData2() << endl;
  muxALUSrc.operate(control.getALUSrc(), bin2hex(signExtendedNum), registerFile.getReadData2());
  // muxALUSrc.print();
  // cout << "Execute 1" << endl;

  //   b. ALU3 gets ALU Control and Read Data 1 and result of MUX2
  // cout << "getaluop0: " << control.getALUOp0() << endl;
  // cout << "getaluop1: " << control.getALUOp1() << endl;
  // cout << "Func field of current inst: " << currentInstruction.getFuncField() << endl;
  aluThree.setControl(control.getALUOp0(), control.getALUOp1(), currentInstruction.getFuncField());
  // aluThree.print(); 
  // cout << "Execute 2" << endl;  
  // cout << "registerFile: " << registerFile.getReadData1() << endl;
  // cout << "Alu 3 control: " << aluThree.getControl() << endl; 
  // cout << "ALUControl from control: " << control.getALUControl() << endl;
  // cout << "MUX2 result: " << muxALUSrc.getResult() << endl;
  // cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << muxALUSrc.getResult() << endl;

  // cout << "aluthree /get control " << aluThree.getControl() << endl;
  aluThree.operate(aluThree.getControl(), muxALUSrc.getResult(), registerFile.getReadData1());
  // aluThree.print();
  // cout << "ALUTHREE RESULT: " << aluThree.getALUresult() << endl;
  // cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << aluThree.getALUresult() << endl;
  // aluThree.print();
  // cout << "Execute 3" << endl;
  //   c. send the result of ALU1 and ALU2 and (branch AND zero from ALU3) 
  //      to MUX5.
  muxBranch.operate((control.getBranch()&&aluThree.getZero()), aluTwo.getALUresult(), aluOne.getALUresult());
  // muxBranch.print();
  //   d. Shift left 2 takes instruction 25-0 and shifts 2(increasing 2 bits)
  //      and concatenate those 28 bits with the bits from ALU1. Send this(jump
  //      address) and result of MUX5 to MUX4.
  // cout << "Execute 4" << endl;

  //  cout << "PC: " << programCounter.getPC() << endl;
  //  cout << "Current Instruction: " << currentInstruction.getBits(25, 0) << endl;
  //  cout << "Shifted Instruction: " << shiftLeft2(currentInstruction.getBits(25, 0), false) << endl;
  //  cout << (hex2bin(programCounter.getPC()).substr(0, 4)+shiftLeft2(currentInstruction.getBits(25, 0), false)) << endl;


  std::string uglyString = bin2hex((hex2bin(programCounter.getPC()).substr(0, 4)+shiftLeft2(currentInstruction.getBits(25, 0), false)));

  muxJump.operate(control.getJump(), uglyString, muxBranch.getResult());
  // muxJump.print();
  //   e. Send result of MUX4 to PC?
  // cout << "Execute 5" << endl;
  // cout << "Printing Program counter before incrementing" << programCounter.getPC() << endl;
  programCounter.setPC(muxJump.getResult());
  // cout << "Printing Program counter after incrementing" << programCounter.getPC() << endl;
  // cout << "Execute 6" << endl;  
}

void Processor::
memory(){
  // Memory:
  //   a. Data Memory gets MemWrite and MemRead and Result of ALU3(address)
  //      and read data2(write data).
  /// @TODO DATA MEMORY NEEDS TO BE DONE 
  // cout << "Memory 0" << endl;

  if (control.getMemWrite()) {
    // cout << "Memory 1" << endl;  
    // do the things
    // cout << aluThree.getALUresult() << endl;
    // cout << bin2hex(aluThree.getALUresult()) << endl;
    MemoryData[aluThree.getALUresult()] = registerFile.getReadData2();
    // cout << "Memory 2" << endl;
  }
  // cout << "Memory 3" << endl;
}

void Processor::
writeback(){
  // cout << "Writeback 0" << endl;
  // Writeback:
  //   b. MUX3 gets MemtoReg and Read data(from data memory) and result of ALU3
  ///@TODO DO WHAT IS WRITTEN ABOVE  
  // cout << aluThree.getALUresult() << endl;
  // cout << "Printing the bool" << control.getMemToReg() << endl;

  // aluThree.print();
  //cout << "Printing the memData" <<InstructionData.at(aluThree.getALUresult()).getBits(32, 0) << endl; 
  //
  //MemoryData.at(aluThree.getALUresult()) << endl;
  cout << "////////////////////////// _1_ /////////////////////////////" << endl;
  if(control.getRegWrite()) {
    // cout << "THIS IF STATEMENT IS SATAN" << endl;
    // cout << aluThree.getALUresult() << endl;
    // cout << InstructionData.at((aluThree.getALUresult())).getBinStr() << endl;
    cout << "////////////////////////// _2_ /////////////////////////////" << endl;
    if(control.getMemRead()){
      // cout << "Hello darkness my old friend" << endl;
      // cout << "clearly this is wtorng" << endl;
      // cout << MemoryData.at(aluThree.getALUresult()) << endl;
      // muxALUSrc.print();

      // cout << registerContents.at(2) << endl;

      // cout << signExtendedNum<< endl;
      cout << "////////////////////////// _3_ /////////////////////////////" << endl;
      cout << "control.getMemToReg(): " << control.getMemToReg() << endl;
      cout << "aluThree.getALUresult(): " << aluThree.getALUresult()<< endl;
      aluThree.print();
      registerFile.print();
      cout << "MemoryData.at(aluThree.getALUresult()): " << MemoryData.at(aluThree.getALUresult()) << endl;
      cout << "aluThree.getALUresult(): " << aluThree.getALUresult()<< endl;
      muxMemToReg.operate(control.getMemToReg(), MemoryData.at(aluThree.getALUresult()), aluThree.getALUresult());
      cout << "////////////////////////// _3 and a half_ /////////////////////////////" << endl;
    }
    else {
      cout << "////////////////////////// _4_ /////////////////////////////" << endl;
      muxMemToReg.operate(control.getMemToReg(), "the cake is a lie", aluThree.getALUresult());
    }
  
    // muxMemToReg.print();
  }

  // cout << "Writeback 1" << endl;


  //   a. Write data in register file gets the result of MUX3.
  ///@TODO need to have functionality in registerFile to check boolean before 
  //       writing to the write data reg
  cout << "////////////////////////// _5_ /////////////////////////////" << endl;
  if(control.getRegWrite()){
    // if(registerFile.getWriteReg() == 3){
    //   cout << "HOLY FUCK NUGGETS THIS IS WHERE SHIT GOES DOWN!!!!!" << endl;
    //   cout << "\t\t RegisterFile Data: " << registerContents[registerFile.getWriteReg()] << endl;
    //   cout << "\t\t What we are trying to put here: " << registerFile.getWriteData() << endl;

    // }
    // cout << "REGISTER NUMBER: " << registerFile.getWriteReg() << endl;
    // cout << "\t\t\tThis is what is wrong with life: ~setWrite - MUX RESULT = " << muxMemToReg.getResult() << endl;
    cout << "////////////////////////// _6_ /////////////////////////////" << endl;
    registerFile.setWriteData(muxMemToReg.getResult());
    cout << "////////////////////////// _7_ /////////////////////////////" << endl;
    registerContents[registerFile.getWriteReg()] = registerFile.getWriteData();
    // cout << "Writeback 2" << endl;
  }
}


void Processor::
print(){
  ///@TODO Print instruction memory
  if(writeToFile){
    if(printMemory){
      o << "*********** Instruction Memory ***********" << std::endl;
      for (auto& element : InstructionData)
      {
        o << element.first << ":" << bin2hex(element.second.getBinStr()) << std::endl;
      }
      o << "*********** Data Memory ***********" << std::endl;
      for (std::pair<std::string, std::string> element : MemoryData)
      {
        o << element.first << ":" << element.second << std::endl;
      }
      o << "*********** Register Contents ***********" << std::endl;
      int regCount = 0;
      for(auto i = registerContents.begin(); i != registerContents.end(); ++i)
      {
        o << regCount << ":" << *i << std::endl;
        regCount++;
      }
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

  std::cout << "*********** Instruction Memory ***********" << endl;;
  for (auto& element : InstructionData)
  {
    std::cout << element.first << ":" << bin2hex(element.second.getBinStr()) << std::endl;
  }

  std::cout << "*********** Data Memory ***********" << std::endl;
  for (std::pair<std::string, std::string> element : MemoryData)
  {
    std::cout << element.first << ":" << element.second << std::endl;
  }

  std::cout << "*********** Register Contents ***********" << std::endl;
  int regCount = 0;
  for(auto i = registerContents.begin(); i != registerContents.end(); ++i)
  {
  std::cout << regCount << ":" << *i << std::endl;
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
