#include "Control.h"

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
}

void
Control::setControlLines(const Instruction& inst){
  switch(inst.getOpcode()){
    //ADD + SUB + SLT   ->case "000000":
    //ADDI              ->case "001000":
    //LW                ->case "100011":
    //SW                ->case "101011":
    //j                 ->case "000010":
  }
}