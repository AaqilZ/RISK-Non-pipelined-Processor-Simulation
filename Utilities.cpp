#include "Utilities.h"
#include <string>
#include <bitset>
#include <iostream>
#include <math.h>

using namespace std;

string 
bin2dec(const string& bin){
  int decimal = 0;
  for(int i = 0; i < bin.length(); i++){
    if(bin[i]=='1'){
      decimal += pow(2, bin.length()-i-1);
    }
  }
  return to_string(decimal);
}


string 
bin2hex(const string& bin){
  string localBin = bin;
  string hex = "0x";
  for(size_t i = 0; i < localBin.length() - 3; i+=4){ //This assumes that the bin 
    string dec = localBin.substr(i, i+4);     //numb is in groups of 4 bit
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


string 
hex2bin(const string& hex){
  string nonConstHex = hex;
  string bin = "";
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


string 
signExt(const string& value, size_t numDigits = 32){
  string num = value;
  while(num.length()<numDigits)
    num.insert(0, "0");
  return num; 
}


string 
shiftLeft2(const string& value) {
  string bin = "";
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

string 
hex2dec(string hex){ 
  return bin2dec(hex2bin(hex));
}

string 
dec2hex(int dec) { return ""; }

void 
testUtilities() { 
  cout << "Testing Utility Functions" << endl << endl;

  cout << "Testing bin2dec(\"010101\");" << endl;
  cout << "\t" << bin2dec("010101") << " [Expected: 21]" << endl << endl;

  cout << "Testing bin2hex(\"10100011\");" << endl;
  cout << "\t" << bin2hex("10100011") << " [Expected: 0xa3]" << endl << endl;

  cout << "Testing hex2bin(\"0xaf24\");" << endl;
  cout << "\t" << hex2bin("0xaf24") << " [Expected: 1010111100100100]" << endl;
  cout << "Testing hex2bin(\"af24\");" << endl;
  cout << "\t" << hex2bin("af24") << " [Expected: 1010111100100100]" << endl << endl;

  cout << "Testing signExt(\"0010010\", 10);" << endl;
  cout << "\t" << signExt("0010010", 10) << " [Expected: 0000010010]" << endl << endl;
}
