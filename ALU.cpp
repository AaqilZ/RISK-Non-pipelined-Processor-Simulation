#include "ALU.h"

std::string ALU::
operate(std::string control, std::string& arg1, std::string& arg2){
  std::string add = "01";
  std::string final = "";
  if(control == add)
    final = ALU::add(arg1, arg2);

  return final;
}


std::string ALU::
add(std::string& arg1, std::string& arg2) { 
  std::string result;           // the final string that will be returned
 
  int length = arg1.length();     // get the length of the string
 
  int carry = 0;                // this will be use to 'carry the 1'
 
  // starting from the right, go through each bit position and add, tracking carry    
  for (int i = length - 1 ; i >= 0 ; i--)
  {
    char bitOneChar = arg1.at(i);     // grab the char at current index
    int bitOne = bitOneChar - '0';    // convert char to int the char represents
    
    char bitTwoChar = arg2.at(i);     // grab the char at current index
    int bitTwo = bitTwoChar - '0';      // convert char to int the char represents
 
    
    int sum = (bitOne ^ bitTwo ^ carry) + '0';    // sum the three bits using XOR operator 
 
    result = (char)sum + result;            // put the sum of the XORs into result as a char since char is a string
    
    // conduct bitwise AND on each possible pair
    int bitOneANDbitTwo = (bitOne & bitTwo);
    int bitOneANDcarry  = (bitOne & carry);
    int bitTwoANDcarry  = (bitTwo & carry);
    
    // set the carry variable for the next iteration using bitwise OR of each of the ANDs
    carry = bitOneANDbitTwo | bitOneANDcarry | bitTwoANDcarry;
  }
 
  // carry the 1 one last time if necessary by adding 1 to front of result string
  if (carry)
    result = '1' + result;
 
  return result;
}

std::string ALU::
twosComp(std::string& arg1){
  int carry = 1;
  
  for (int i = arg1.length(); i >= 0; i-- ) {
    // flip 0 to 1 or vice versa using XOR
    arg1[i] = (arg1[i] ^ 1); 
    // add carry from last loop through       
    arg1[i] += carry;
    // save the overflow in the carry variable
    carry = (arg1[i] & 2) >> 1;     
  }
  
  return arg1;
}

std::string ALU::
bitwiseAND(std::string& arg1, std::string& arg2){
  // string to build that will ultimately be returned
  std::string final = "";

  // loop through the string one bit at a time, right to left
  for(int i = 0; i < arg1.length(); i++){
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
  for(int i = 0; i < arg1.length(); i++){
    // if either bit is 1, append 1 to final (OR)
    if(arg1[i] == '1' || arg2[i] == '1')
      final += "1";
    else
      final += "0";
  }
  
  return final;
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

