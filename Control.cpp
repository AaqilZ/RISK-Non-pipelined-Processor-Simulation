#include "Control.h"
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
    memToReg=true; ALUOp0=true; ALUOp1=false; branch=true; ALUControl="0110"; jump=false; 
  }
}
