#include "Control.h"
#include "Utilities.h"
#include <string>

void
Control::clear(){
  regDst    = false;    
  jump      = false;      
  branch    = false;    
  memRead   = false;   
  memToReg  = false;  

  ALUOp0    = false;    
  ALUOp1    = false;    
  memWrite  = false;  
  ALUSrc    = false;    
  regWrite  = false; 

  ALUControl = ""; 
}

void
Control::setControlLines(const Instruction& inst){
  std::string op = inst.getOpcode();

  opCode = op;

  // ADD + SUB + SLT
  if(op == "000000"){ 
    regDst=true; regWrite=true; ALUSrc=false; memWrite=false; memRead=false; 
    memToReg=false; ALUOp0=false; ALUOp1=true; branch=false; jump=false;
  }      

  // ADDI
  /// @TODO Not sure about the memRead on this thing
  else if(op == "001000"){
    regDst=false; regWrite=true; ALUSrc=true; memWrite=false; memRead=false;  
    memToReg=false; ALUOp0=false; ALUOp1=false; branch=false; jump=false;
  }                  

  // LW
  else if(op == "100011"){
    regDst=false; regWrite=true; ALUSrc=true; memWrite=false; memRead=true; 
    memToReg=true; ALUOp0=false; ALUOp1=false; branch=false; jump=false;
  }    

  // SW
  else if (op == "101011"){
    regDst=false; regWrite=false; ALUSrc=true; memWrite=true; memRead=false; 
    memToReg=true; ALUOp0=false; ALUOp1=false; branch=false; jump=false;
  }

  // J - Jump                
  else if(op == "000010"){
    regDst=false; regWrite=false; ALUSrc=false; memWrite=false; memRead=false; 
    memToReg=false; ALUOp0=false; ALUOp1=false; branch=false; ALUControl=""; jump=true; 
  }

  // BEQ 
  else if(op == "000100"){
    regDst=false; regWrite=false; ALUSrc=false; memWrite=false; memRead=false; 
    memToReg=true; ALUOp0=true; ALUOp1=false; branch=true; ALUControl="6969"; jump=false; 
  }
}

void
Control::print(){
  if(writeToFile){
    o << "*********** Control Unit ***********" << std::endl;
    o << "---Inputs---" << std::endl;
    o << "Op Code  : " << bin2hex(getOpCode()) << std::endl;
    o << "---Outputs---" << std::endl;
    o << "regDst   : " << getRegDst() << std::endl;
    o << "jump     : " << getJump() << std::endl;
    o << "branch   : " << getBranch() << std::endl;
    o << "memRead  : " << getMemRead() << std::endl;
    o << "memToReg : " << getMemToReg() << std::endl;
    o << "ALUOp0   : " << getALUOp0() << std::endl;
    o << "ALUOp1   : " << getALUOp1() << std::endl;
    o << "memWrite : " << getMemWrite() << std::endl;
    o << "ALUSrc   : " << getALUSrc() << std::endl;
    o << "regWrite : " << getRegWrite() << std::endl << std::endl;
  }
    std::cout << "*********** Control Unit ***********" << std::endl;
    std::cout << "---Inputs---" << std::endl;
    std::cout << "Op Code  : " << bin2hex(getOpCode()) << std::endl;
    std::cout << "---Outputs---" << std::endl;
    std::cout << "regDst   : " << getRegDst() << std::endl;
    std::cout << "jump     : " << getJump() << std::endl;
    std::cout << "branch   : " << getBranch() << std::endl;
    std::cout << "memRead  : " << getMemRead() << std::endl;
    std::cout << "memToReg : " << getMemToReg() << std::endl;
    std::cout << "ALUOp0   : " << getALUOp0() << std::endl;
    std::cout << "ALUOp1   : " << getALUOp1() << std::endl;
    std::cout << "memWrite : " << getMemWrite() << std::endl;
    std::cout << "ALUSrc   : " << getALUSrc() << std::endl;
    std::cout << "regWrite : " << getRegWrite() << std::endl << std::endl;
}
