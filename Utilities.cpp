#include "Utilities.h"
#include <string>
#include <bitset>
#include <iostream>


std::string bin2dec(const std::string& bin){
  std::string localBin = bin;
  std::string dec = "";
  if(bin.length()>4){
    for(size_t i = 0; i < localBin.length() - 3; i+=4){ //This assumes that the bin 
      dec += (std::bitset<4>(localBin.substr(i, i+4))).to_ulong();  //numb is in groups of 4 bit
    }
  }  
  else
    dec = (std::bitset<4>(bin)).to_ulong();
  return dec;;
}


std::string bin2hex(const std::string& bin){
  std::string localBin = bin;
  std::string hex = "0x";
  for(size_t i = 0; i < localBin.length() - 3; i+=4){ //This assumes that the bin 
    std::string dec = localBin.substr(i, i+4);     //numb is in groups of 4 bit
    dec = bin2dec(dec);
    if(stoi(dec) < 10)
      hex+=dec;
    else if(dec == "10")
      hex+="a";
    else if(dec == "11")
      hex+="b";
    else if(dec == "12")
      hex+="c";
    else if(dec == "13")
      hex+="d";
    else if(dec == "14")
      hex+="e";
    else if(dec == "15")
      hex+="f";
  }
  return hex; 
}


std::string hex2bin(const std::string& hex){
  std::string nonConstHex = hex;
  std::string bin = "";
  if(hex[0]=='0' && tolower(hex[1])=='x'){nonConstHex = nonConstHex.erase(0,2);}
  for(size_t i = 0; i < hex.length(); i++){
    switch(tolower(hex[i])){
      case '0': bin+="0000";
      case '1': bin+="0001";
      case '2': bin+="0010";
      case '3': bin+="0011";
      case '4': bin+="0100";
      case '5': bin+="0101";
      case '6': bin+="0110";
      case '7': bin+="0111";
      case '8': bin+="1000";
      case '9': bin+="1001";
      case 'a': bin+="1010";
      case 'b': bin+="1011";
      case 'c': bin+="1100";
      case 'd': bin+="1101";
      case 'e': bin+="1110";
      case 'f': bin+="1111";
      default: continue;
    }
  }
  return bin;
}


std::string signExt(std::string& num, const std::string& value, size_t numDigits = 32){
  while(num.length()<numDigits)
    num.insert(0, value);
  return num; 
}


std::string shiftLeft2(const std::string& value) {
  std::string bin = "";
  if(tolower(value[1])=='x'){
    bin = hex2bin(value);
    bin = bin.erase(0, 2);
    bin += "00";
  }
  else{     // Here I am assuming that we only get hex/bin values
    bin = value;
    bin = bin.erase(0, 2);
    bin += "00"; 
  }
  return bin; 
}
