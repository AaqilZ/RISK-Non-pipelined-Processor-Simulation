#include "Control.h"

void
Control::clear(){
  regDst    = "";    
  jump      = "";      
  branch    = "";    
  memRead   = "";   
  memToReg  = "";  

  ALUOp0    = "";    
  ALUOp1    = "";    
  memWrite  = "";  
  ALUSrc    = "";    
  regWrite  = "";  
}

void
Control::setControlLines(const Instruction& inst){
  //switch(inst.getOpcode()){
    //ADD + SUB + SLT   ->case "000000":
    //ADDI              ->case "001000":
    //LW                ->case "100011":
    //SW                ->case "101011":
    //j                 ->case "000010":
 // }
}
