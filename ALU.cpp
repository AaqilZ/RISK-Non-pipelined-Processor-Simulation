#include "ALU.h"
#include "Utilities.h"
#include <iostream>

/*
INPUT: four bit binary control line, hex result of alu1, hex result of shift left2
OUTPUT: Hex
*/
std::string ALU::
operate(std::string c, std::string arg1, std::string arg2){
  std::string add = "0010";
  std::string subtract = "0110";
  std::string slt = "0111";
  std::string result = "";

  // std::cout << "Input control: " << c << std::endl;
  control = c;
  inputOne = arg1;
  inputTwo = arg2;

  setInputOne(arg1);
  setInputTwo(arg2);

  // 00101110110001001111001000011001    input one
  // 00101110110001001111001000011001

  // 00110000010111110111111010100001    input two
  // 

  // std::cout << std::endl;
  // std::cout << std::endl;
  // std::cout << "unit number :" << getUnitNum() << std::endl;
  // std::cout << "control :" << control << std::endl;
  // std::cout << "arg1 :" << inputOne << std::endl;
  // std::cout << "arg2 :" << inputTwo << std::endl;
  // std::cout << std::endl;
  // std::cout << std::endl;

  if(control == add){
    // std::cout << "printing hex conversions: " << hex2bin(arg1) << " " << hex2bin(arg2) << std::endl;
    result = ALU::add(arg1, arg2);
  }
  
  ///SUBTRACT
  else if(control == subtract){
    // std::cout << arg1 << std::endl;
    arg2 = hex2bin(arg2);
     // std::cout << arg2 << std::endl;
    arg2 = twosComp(arg2);
     // std::cout << arg2 << std::endl;
    arg2 = bin2hex(arg2);
     // std::cout << arg2 << std::endl;
    //arg2 = bin2hex(twosComp(hex2bin(arg2)));          // make arg2 a negative
    result = ALU::add(arg1, arg2);   // add arg1 and -arg2
    // std::cout << "RESULT" << result << std::endl;
    if (stoi(hex2dec(result)) == 0) {setZero(true); std::cout << "ZERO" << std::endl;}
  } 
  
  ///SLT
  else if(control == slt){
    int one = stoi(hex2dec(arg1));  // convert arg1 to int for easy comparison
    int two = stoi(hex2dec(arg2));  // convert arg2 to int for easy comparison
    if(one < two)
      result = "0x00000001";
    else{
      zero = one==two;
      result = "0x00000000";
    }
  }


  //11001111101000001000000101011111
  //11001111101000001000000101011111


  // std::cout << "Control: " << control << std::endl << "Arg1: " << arg1 << std::endl << "Arg2: " << arg2 << std::endl;
  ALUresult = result;

  return result;
}

/*
Input: Hex
Output: Hex
*/
std::string ALU::
add(std::string arg1, std::string arg2) {   
  setInputOne(arg1);
  setInputTwo(arg2);
  // std::cout << "add arg1 " << arg1 << std::endl;
  // std::cout << "add arg2 " << arg2 << std::endl;

  arg1 = hex2bin(arg1);
  arg2 = hex2bin(arg2);

  // std::cout << "POTATO SOOOOOUUUUUUPPPPPP" << std::endl;
  // std::cout << "POTATO SOOOOOUUUUUUPPPPPP " << getUnitNum() << std::endl;
  if(getUnitNum() != 3)
    setControl("0010");
  

  // std::cout << "add arg1(bin expected) " << arg1 << std::endl;
  // std::cout << "add arg2(bin expected) " << arg2 << std::endl;
  std::string result{""};             // the final string that will be returned

  int lengthOne = arg1.length();     // get the length of the string
  int lengthTwo = arg2.length();

  if(lengthOne > lengthTwo){
    for(int i = 0; i < (lengthOne - lengthTwo); i++){
      arg2 = "0" + arg2;
    }
  } else if(lengthOne < lengthTwo){
    for(int j = 0; j < (lengthTwo - lengthOne); j++){
      arg1 = "0" + arg1;
    }
  }


  int carry = 0;                  // this will be use to 'carry the 1'

  // starting from the right, go through each bit position and add, tracking carry    
  for (int i = arg1.length() - 1 ; i >= 0 ; i--)
  {
    char bitOneChar = arg1.at(i);     // grab the char at current index
    int bitOne = bitOneChar - '0';    // convert char to int the char represents

    char bitTwoChar = arg2.at(i);     // grab the char at current index
    int bitTwo = bitTwoChar - '0';    // convert char to int the char represents


    int sum = (bitOne ^ bitTwo ^ carry) + '0';    // sum the three bits using XOR operator 

    result = (char)sum + result;    // put the sum of the XORs into result as a char since char is a string

    // conduct bitwise AND on each possible pair
    int bitOneANDbitTwo = (bitOne & bitTwo);
    int bitOneANDcarry  = (bitOne & carry);
    int bitTwoANDcarry  = (bitTwo & carry);

    // set the carry variable for the next iteration using bitwise OR of each of the ANDs
    carry = bitOneANDbitTwo | bitOneANDcarry | bitTwoANDcarry;
  }

  // carry the 1 one last time if necessary by adding 1 to front of result string
  if (carry && control == "0010")
    result = '1' + result;
  setALUresult(bin2hex(result));
  // std::cout << "Result: " << bin2hex(result) << std::endl;
  return bin2hex(result);
  }

  // std::string ALU::
  // twosComp(std::string& arg1){
  //   int carry = 1;

  //   for (int i = arg1.length(); i >= 0; i-- ) {
  //     // flip 0 to 1 or vice versa using XOR
  //     arg1[i] = (arg1[i] ^ 1); 
  //     // add carry from last loop through       
  //     arg1[i] += carry;
  //     // save the overflow in the carry variable
  //     carry = (arg1[i] & 2) >> 1;     
  //   }

  //   return arg1;
  // }

  std::string ALU::
    bitwiseAND(std::string& arg1, std::string& arg2){
      // string to build that will ultimately be returned
      std::string final = "";

      // loop through the string one bit at a time, right to left
      for(size_t i = 0; i < arg1.length(); i++){
        // if both are 1, append 1 to final (AND)
        if(arg1[i] == arg2[i] && arg1[i] == '1')
          final += "1";
        else
          final += "0";
      }

      return final;
    }

  std::string ALU::
    bitwiseOR(std::string& arg1, std::string& arg2){
      // string to build that will ultimately be re
      std::string final = "";

      // loop through the string one bit at a time, right to left
      for(size_t i = 0; i < arg1.length(); i++){
        // if either bit is 1, append 1 to final (OR)
        if(arg1[i] == '1' || arg2[i] == '1')
          final += "1";
        else
          final += "0";
      }

      return final;
    }

  void ALU::setControl(bool ALUop0, bool ALUop1, std::string func){
    setALUop0(ALUop0);
    setALUop1(ALUop1);
    setFuncCode(func);

    //  lw or sw
    //  00
    if(!ALUop0 && !ALUop1)
      control = "0010";   // alu: add()

    //  beq
    //  01
    if(ALUop0 && !ALUop1){
      // std::cout << "HEEEEEEEERRRRRRRRRRREEEEEEEEEEEEEEEEEE" << std::endl;
      control = "0110";   // alu: subtract()
      // std::cout << "HEEEEEEEERRRRRRRRRRREEEEEEEEEEEEEEEEEE " << bin2hex(control) << std::endl;
      // std::cout << "HEEEEEEEERRRRRRRRRRREEEEEEEEEEEEEEEEEE " << getUnitNum() << std::endl;
    }

    //  R-type
    //  11
    if(!ALUop0 && ALUop1){
      //  add + addi
      if(func == "100000" || func == "000000")
        control ="0010";  // alu: add()

      //  sub
      if(func == "100010")
        control = "0110"; // alu: subtract()

      //  slt
      if(func == "101010")
        control = "0111"; // alu: slt()
    }
  }

  void ALU::
    print(){
      if(writeToFile){
        switch(getUnitNum()){
          case 3 :
            o << "*********** ALU Control ***********" << std::endl;
            o << "---Inputs---" << std::endl;
            o << "ALUop0: " << ALUop0 << std::endl;
            o << "ALUop1: " << ALUop1 << std::endl;
            o << "Function Code: " << bin2hex(funcCode) << std::endl;
            o << "---Outputs---" << std::endl;
            o << "ALU control: " << bin2hex(control) << std::endl << std::endl;

            o << "*********** ALU 3 ***********" << std::endl;
            o << "---Inputs---" << std::endl;
            o << "ALU control: " << bin2hex(control) << std::endl;
            o << "ALU input 1: " << inputOne << std::endl;
            o << "ALU input 2: " << inputTwo << std::endl;
            o << "---Outputs---" << std::endl;
            o << "Zero: " << zero << std::endl;
            o << "ALU result:  " << ALUresult << std::endl << std::endl;
            break;
          case 1 :
            o << "*********** ALU 1 ***********" << std::endl;
            o << "---Inputs---" << std::endl;
            o << "Control: " << control << std::endl;      
            o << "ALU input 1: " << inputOne << std::endl;
            o << "ALU input 2: " << inputTwo << std::endl;
            o << "---Outputs---" << std::endl;
            o << "ALU result:  " << ALUresult << std::endl << std::endl;
            break;
          case 2 :
            o << "*********** ALU 2 ***********" << std::endl;
            o << "---Inputs---" << std::endl;
            o << "Control: " << control << std::endl;
            o << "ALU input 1: " << inputOne << std::endl;
            o << "ALU input 2: " << inputTwo << std::endl;
            o << "---Outputs---" << std::endl;
            o << "ALU result:  " << ALUresult << std::endl << std::endl;
            break;
        }
      }
    switch(getUnitNum()){
        case 3 :
          std::cout << "*********** ALU Control ***********" << std::endl;
          std::cout << "---Inputs---" << std::endl;
          std::cout << "ALUop0: " << ALUop0 << std::endl;
          std::cout << "ALUop1: " << ALUop1 << std::endl;
          std::cout << "Function Code: " << bin2hex(funcCode) << std::endl;
          std::cout << "---Outputs---" << std::endl;
          std::cout << "ALU control: " << bin2hex(control) << std::endl << std::endl;
          std::cout << "*********** ALU 3 ***********" << std::endl;
          std::cout << "---Inputs---" << std::endl;
          std::cout << "ALU control: " << bin2hex(control) << std::endl;
          std::cout << "ALU input 1: " << inputOne << std::endl;
          std::cout << "ALU input 2: " << inputTwo << std::endl;
          std::cout << "---Outputs---" << std::endl;
          std::cout << "Zero: " << zero << std::endl;
          std::cout << "ALU result:  " << ALUresult << std::endl << std::endl;
          break;
        case 1 :
          std::cout << "*********** ALU 1 ***********" << std::endl;
          std::cout << "---Inputs---" << std::endl;
          std::cout << "Control: " << control << std::endl;      
          std::cout << "ALU input 1: " << inputOne << std::endl;
          std::cout << "ALU input 2: " << inputTwo << std::endl;
          std::cout << "---Outputs---" << std::endl;
          std::cout << "ALU result:  " << ALUresult << std::endl << std::endl;
          break;
        case 2 :
          std::cout << "*********** ALU 2 ***********" << std::endl;
          std::cout << "---Inputs---" << std::endl;
          std::cout << "Control: " << control << std::endl;
          std::cout << "ALU input 1: " << inputOne << std::endl;
          std::cout << "ALU input 2: " << inputTwo << std::endl;
          std::cout << "---Outputs---" << std::endl;
          std::cout << "ALU result:  " << ALUresult << std::endl << std::endl;
          break;
    }
  }

  void ALU::
  testALU(){
    std::cout << "ALU TESTING" << std::endl;

      // Test add()
      std::string str1 = "1100011";
      std::string str2 = "1001011";

      std::string sum = add(str1, str2);
      std::string correctSum = "10101110";

      if(sum == correctSum)
        std::cout << "add(): Pass" << std::endl;
      else
        std::cout << "add(): Fail" << std::endl;

      // Test twosComp()
      std::string negative = twosComp(str1);
      std::string correctTwosComp = "0011101";
      if(negative == correctTwosComp)
        std::cout << "twosComp(): Pass" << std::endl;
      else
        std::cout << "twosComp(): Fail" << std::endl;


      // Test bitwiseAND()
      std::string myAND = bitwiseAND(str1, str2);
      std::string correctAND = "1000011";
      if(myAND == correctAND)
        std::cout << "bitwiseAND(): Pass" << std::endl;
      else
        std::cout << "bitwiseAND(): Fail" << std::endl;

      // Test bitwiseOR()
      std::string myOR = bitwiseOR(str1, str2);
      std::string correctOR = "1101011";
      if(myOR == correctOR)
        std::cout << "bitwiseOR(): Pass" << std::endl;
      else
        std::cout << "bitwiseOR(): Fail" << std::endl;
    }
