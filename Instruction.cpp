#include "Instruction.h"

#include "Utilities.h"

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
    func = "100100";
    s >> arg1;
    rd = parseRegisterNumber(arg1);
    s >> arg2;
    rs = parseRegisterNumber(arg2);
    s >> arg3;
    rt = parseRegisterNumber(arg3);
  }
  else if (type == "addi"){
    opcode = "001000";
    s >> arg1;
    rt = parseRegisterNumber(arg1);
    s >> arg2;
    rs = parseRegisterNumber(arg2);
    s >> arg3;
    imm = parseImmediate(arg3);
  }
  else if (type == "sub"){
    opcode = "000000";
    func = "100010";
    s >> arg1;
    rd = parseRegisterNumber(arg1);
    s >> arg2;
    rs = parseRegisterNumber(arg2);
    s >> arg3;
    rt = parseRegisterNumber(arg3);
  }
  else if (type == "slt"){
    opcode = "000000";
    func = "101010";
    s >> arg1;
    rd = parseRegisterNumber(arg1);
    s >> arg2;
    rs = parseRegisterNumber(arg2);
    s >> arg3;
    rt = parseRegisterNumber(arg3);
  }
  else if (type == "lw"){
    opcode = "100011";
    s >> arg1;
    rt = parseRegisterNumber(arg1);
    s >> arg2;
    imm = parseOffset(arg2);
    rs = parseRegisterNumber(arg2);
  }
  else if(type == "sw"){
    opcode = "101011";
    s >> arg1;
    rt = parseRegisterNumber(arg1);
    s >> arg2;
    imm = parseOffset(arg2);
    rs = parseRegisterNumber(arg2);
  }
  else if(type == "beq"){
    opcode = "000100";
    s >> arg1;
    rs = parseRegisterNumber(arg1);
    s >> arg2;
    rt = parseRegisterNumber(arg2);
    s >> arg3;
    imm = parseImmediate(arg3);
  }
  else if(type == "j"){
    opcode = "000010";
    s >> arg1;
    // cout << arg1;
    imm = parseImmediate(arg1);
  }
}

int
Instruction::
parseRegisterNumber(string r){
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
  return atoi(tmp.c_str());
}

int
Instruction::
parseOffset(string o){
  int splitInd = o.find('(');
  return atoi(o.substr(0,splitInd).c_str());
}

int
Instruction::
parseImmediate(string i){
  if(i.find("x") != string::npos){
    return atoi(hex2dec(i).c_str());
  }
  return atoi(i.c_str());
}

const ostream&
Instruction::
operator<<(ostream& os){
  cout << binStr << endl;
  return os;
}
