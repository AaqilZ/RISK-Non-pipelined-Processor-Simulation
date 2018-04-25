#include "Instruction.h"

#include "Utilities.h"

using namespace std;

#include <sstream>
#include <cstdlib>


void
Instruction::
parseInstruction(string inst){
  stringstream s(inst);
  // variables for args
  string command, arg1, arg2, arg3;
  // extract the first word of the instruction
  s >> command;
  // cout << type << endl;

  if(command == "add"){
    opcode = "000000";
    func = "100100";
    s >> arg1;
    rd = parseRegisterNumber(arg1);
    s >> arg2;
    rs = parseRegisterNumber(arg2);
    s >> arg3;
    rt = parseRegisterNumber(arg3);
    type = RTYPE;
  }
  else if (command == "addi"){
    opcode = "001000";
    s >> arg1;
    rt = parseRegisterNumber(arg1);
    s >> arg2;
    rs = parseRegisterNumber(arg2);
    s >> arg3;
    imm = parseImmediate(arg3);
    type = ITYPE;
  }
  else if (command == "sub"){
    opcode = "000000";
    func = "100010";
    s >> arg1;
    rd = parseRegisterNumber(arg1);
    s >> arg2;
    rs = parseRegisterNumber(arg2);
    s >> arg3;
    rt = parseRegisterNumber(arg3);
    type = RTYPE;
  }
  else if (command == "slt"){
    opcode = "000000";
    func = "101010";
    s >> arg1;
    rd = parseRegisterNumber(arg1);
    s >> arg2;
    rs = parseRegisterNumber(arg2);
    s >> arg3;
    rt = parseRegisterNumber(arg3);
    type = RTYPE;
  }
  else if (command == "lw"){
    opcode = "100011";
    s >> arg1;
    rt = parseRegisterNumber(arg1);
    s >> arg2;
    imm = parseOffset(arg2);
    rs = parseRegisterNumber(arg2);
    type = ITYPE;
  }
  else if(command == "sw"){
    opcode = "101011";
    s >> arg1;
    rt = parseRegisterNumber(arg1);
    s >> arg2;
    imm = parseOffset(arg2);
    rs = parseRegisterNumber(arg2);
    type = ITYPE;
  }
  else if(command == "beq"){
    opcode = "000100";
    s >> arg1;
    rs = parseRegisterNumber(arg1);
    s >> arg2;
    rt = parseRegisterNumber(arg2);
    s >> arg3;
    imm = parseImmediate(arg3);
    type = ITYPE;
  }
  else if(command == "j"){
    opcode = "000010";
    s >> arg1;
    imm = parseImmediate(arg1);
    type = JTYPE;
  }
  computeBinaryEncoding();
}

void
Instruction::
computeBinaryEncoding(){
  binStr+= opcode;
      cout << binStr << endl;
      cout << "The cake is a lie." << endl;
  switch (type){
    case(RTYPE):
      binStr += unsignedExt(dec2bin(rs), 5);
      binStr += unsignedExt(dec2bin(rt), 5);
      binStr += unsignedExt(dec2bin(rd), 5);
      binStr += "00000";
      binStr += func;
      break;
    case(ITYPE):
      cout << binStr << endl;
      cout << "The cake is a lie." << endl;
      binStr += unsignedExt(dec2bin(rs), 5);
      binStr += unsignedExt(dec2bin(rt), 5);
      binStr += dec2bin(imm,16);
      break;
    case(JTYPE):
      binStr += dec2bin(imm,26);
      break;
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
  if(o.find("x") != string::npos){
    return parseImmediate(o.substr(0,splitInd).c_str());
  }
  return atoi(o.substr(0,splitInd).c_str());
}

int
Instruction::
parseImmediate(string i){
  bool neg{false};
  int result;
  // cout << "Input string: " << i << endl;
  // detect if immediate value is negative
  if(i.at(0) == '-'){
    neg = true;
    i = i.substr(1);
    // cout << "Input Substring: " << i << endl;
  }
  // handle hex immediate values
  if(i.find("x") != string::npos){
    result = stoi(hex2dec(i));
  }
  // handle decimal values
  else
    result = stoi(i);
  // handle negative values
  // cout << "Positive Result: " << result << endl;
  if(neg){
    result *= -1;
  }
  // cout << "Result: " << result << endl;
  return result;
}

string 
Instruction::
getBits(int max, int min){
    //cout << "max: " << max << "min: " << min << endl;
    //cout << "index of substring: " << binStr.length() - max - 1 << endl;
    //cout << binStr << endl;
    return binStr.substr(binStr.length() - max - 1, max - min + 1);
}

void
Instruction::
testInstruction(){
  cout << "Testing Instruction" << endl;
  cout << "Testing parseInstruction: " << endl;

  string add = "add $2, $12, $30";
  cout << "\t" << add << endl;
  Instruction i(add);
  cout << "\t\tOpcode: " << i.opcode << endl;
  cout << "\t\trs: " << i.rs << " \tFor binStr: " << unsignedExt(dec2bin(i.rs), 5) << endl;
  cout << "\t\trt: " << i.rt << " \tFor binstr: " << unsignedExt(dec2bin(i.rt), 5) << endl;
  cout << "\t\trd: " << i.rd << " \tFor binstr: " << unsignedExt(dec2bin(i.rd), 5) << endl;  
  cout << "\t\timmediate: " << i.imm << endl;
  cout << "\t\tfunc: " << i.func << endl;
  cout << "\t\ttype: " << i.type << endl;
  cout << "\t\tbinary encoding: " << i.binStr << endl;
  cout << "\t\thex encoding: " << bin2hex(i.binStr) << endl;

  string addi = "addi $3, $4, -16";
  cout << "\t" << addi << endl;
  Instruction ai(addi);
  cout << "\t\tOpcode: " << ai.opcode << endl;
  cout << "\t\trs: " << ai.rs << " \tFor binStr: " << unsignedExt(dec2bin(ai.rs), 5) << endl;
  cout << "\t\trt: " << ai.rt << " \tFor binStr: " << unsignedExt(dec2bin(ai.rt), 5) << endl;
  cout << "\t\trd: " << ai.rd << " \tFor binStr: " << unsignedExt(dec2bin(ai.rd), 5) << endl; 
  cout << "\t\timmediate: " << ai.imm << " \tFor binStr: " << unsignedExt(dec2bin(ai.imm), 16) << endl;
  cout << "\t\tfunc: " << ai.func << endl;
  cout << "\t\ttype: " << ai.type << endl;
  cout << "\t\tbinary encoding: " << ai.binStr << endl;
  cout << "\t\thex encoding: " << bin2hex(ai.binStr) << endl;
  
  string addih = "addi $4, $8, 0xb34";
  cout << "\t" << addih << endl;
  Instruction ah(addih);
  cout << "\t\tOpcode: " << ah.opcode << endl;
  cout << "\t\trs: " << ah.rs << endl;
  cout << "\t\trt: " << ah.rt << endl;
  cout << "\t\trd: " << ah.rd << endl;  
  cout << "\t\timmediate: " << ah.imm << endl;
  cout << "\t\tfunc: " << ah.func << endl;
  cout << "\t\ttype: " << ah.type << endl;
  cout << "\t\tbinary encoding: " << ah.binStr << endl;
  cout << "\t\thex encoding: " << bin2hex(ah.binStr) << endl;

  string slt = "slt $1, $2, $10";
  cout << "\t" << slt << endl;
  Instruction sl(slt);
  cout << "\t\tOpcode: " << sl.opcode << endl;
  cout << "\t\trs: " << sl.rs << endl;
  cout << "\t\trt: " << sl.rt << endl;
  cout << "\t\trd: " << sl.rd << endl;  
  cout << "\t\timmediate: " << sl.imm << endl;
  cout << "\t\tfunc: " << sl.func << endl;
  cout << "\t\ttype: " << sl.type << endl;
  cout << "\t\tbinary encoding: " << sl.binStr << endl;
  cout << "\t\thex encoding: " << bin2hex(sl.binStr) << endl; 

  string beq = "beq $5, $16, 0x3400";
  cout << "\t" << beq << endl;
  Instruction b(beq);
  cout << "\t\tOpcode: " << b.opcode << endl;
  cout << "\t\trs: " << b.rs << endl;
  cout << "\t\trt: " << b.rt << endl;
  cout << "\t\trd: " << b.rd << endl;  
  cout << "\t\timmediate: " << b.imm << endl;
  cout << "\t\tfunc: " << b.func << endl;
  cout << "\t\ttype: " << b.type << endl;
  cout << "\t\tbinary encoding: " << b.binStr << endl;
  cout << "\t\thex encoding: " << bin2hex(b.binStr) << endl; 

  i.getBits(15,11);
}

const ostream&
Instruction::
operator<<(ostream& os){
  return os;
}
