#include "Instruction.h"
using namespace std;

#include <sstream>
#include <cstdlib>


void
Instruction::
parseInstruction(string inst){
  binStr = inst;
  stringstream s(inst);
  // variables for args
  string type, arg1, arg2, arg3;
  // extract the first word of the instruction
  s >> type;
  // cout << type << endl;

  if(type == "add"){
    opcode = "000000";
    s >> arg1;
    rd = getRegisterNumber(arg1);
    s >> arg2;
    rs = getRegisterNumber(arg2);
    s >> arg3;
    rt = getRegisterNumber(arg3);
  }
  else if (type == "addi"){
    opcode = "000000";
    s >> arg1;
    rt = getRegisterNumber(arg1);
    s >> arg2;
    rs = getRegisterNumber(arg2);
    s >> arg3;
    imm = atoi(arg3.c_str());
  }
  else if (type == "sub"){
    opcode = "000000";
    s >> arg1;
    rd = getRegisterNumber(arg1);
    s >> arg2;
    rs = getRegisterNumber(arg2);
    s >> arg3;
    rt = getRegisterNumber(arg3);
  }
  else if (type == "slt"){
    opcode = "000000";
    s >> arg1;
    rd = getRegisterNumber(arg1);
    s >> arg2;
    rs = getRegisterNumber(arg2);
    s >> arg3;
    rt = getRegisterNumber(arg3);
  }
  else if (type == "lw"){
    opcode = "110001";
    s >> arg1;
    rt = getRegisterNumber(arg1);
    s >> arg2;
    imm = getOffset(arg2);
    rs = getRegisterNumber(arg2);
  }
  else if(type == "sw"){
    opcode = "110101";
    s >> arg1;
    rt = getRegisterNumber(arg1);
    s >> arg2;
    imm = getOffset(arg2);
    rs = getRegisterNumber(arg2);
  }
  else if(type == "beq"){
    opcode = "001000";
    s >> arg1;
    rs = getRegisterNumber(arg1);
    s >> arg2;
    rt = getRegisterNumber(arg2);
    s >> arg3;
    imm = atoi(arg3.c_str());
  }
  else if(type == "j"){
    opcode = "000010";
    s >> arg1;
    imm = atoi(arg1.c_str());
    // cout << imm;
  }
}

int
Instruction::
getRegisterNumber(string r){
  int subStrStart = 1;
  int subStrLength = r.length() - 1;
  if(r.find(',') != string::npos){
    --subStrLength;
  }
  if(r.find('(') != string::npos){
    subStrStart = r.find('(') + 2;
    subStrLength = (r.length() - subStrStart) - 1;
  }
  string tmp = r.substr(subStrStart, subStrLength);
  // cout << tmp;
  return atoi(tmp.c_str());
}

int
Instruction::
getOffset(string o){
  int splitInd = o.find('(');
  // cout << o.substr(0, splitInd) << endl;
  return atoi(o.substr(0,splitInd).c_str());
}

const ostream&
Instruction::
operator<<(ostream& os){
  cout << binStr << endl;
  return os;
}