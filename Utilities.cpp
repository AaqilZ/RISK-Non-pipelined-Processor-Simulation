#include "Utilities.h"
#include <string>
#include <bitset>
#include <iostream>
#include <math.h>

using namespace std;

std::string 
bin2dec(const std::string& bin){
  int decimal = 0;
  for(int i = 0; i<bin.length(); i++){
    if(bin[i]=='1'){
      decimal += pow(2, bin.length()-i);
    }
  }
  return to_string(decimal);
}


std::string 
bin2hex(const std::string& bin){
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


std::string 
hex2bin(const std::string& hex){
  std::string nonConstHex = hex;
  std::string bin = "";
  if(hex[0]=='0' && tolower(hex[1])=='x'){nonConstHex = nonConstHex.erase(0,2);}
  for(size_t i = 0; i < nonConstHex.length(); i++){
    switch(tolower(nonConstHex[i])){
      case '0': bin+="0000";
        break;
      case '1': bin+="0001";
        break;
      case '2': bin+="0010";
        break;
      case '3': bin+="0011";
        break;
      case '4': bin+="0100";
        break;
      case '5': bin+="0101";
        break;
      case '6': bin+="0110";
        break;
      case '7': bin+="0111";
        break;
      case '8': bin+="1000";
        break;
      case '9': bin+="1001";
        break;
      case 'a': bin+="1010";
        break;
      case 'b': bin+="1011";
        break;
      case 'c': bin+="1100";
        break;
      case 'd': bin+="1101";
        break;
      case 'e': bin+="1110";
        break;
      case 'f': bin+="1111";
        break;
      default: continue;
    }
  }
  return bin;
}


std::string 
signExt(std::string& num, const std::string& value, size_t numDigits = 32){
  while(num.length()<numDigits)
    num.insert(0, value);
  return num; 
}


std::string 
shiftLeft2(const std::string& value) {
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

std::string 
hex2dec(std::string hex){ 
  return bin2dec(hex2bin(hex));
}

std::string 
dec2hex(int dec) { return ""; }

void 
testUtilities() { return ; }
