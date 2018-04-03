#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <string>

//TODO should these functions return a value or modify the parameter?

//////////////////////////////////////////////////////////////////////////////////////////
/// @brief helper function to translate a decimal value into a hex string
/// @param dec the decimal value to translate
//////////////////////////////////////////////////////////////////////////////////////////
std::string dec2hex(int dec) { return ""; }

//////////////////////////////////////////////////////////////////////////////////////////
/// @brief helper function to translate a binary string to hex
/// @param bin binary string to be translated
//////////////////////////////////////////////////////////////////////////////////////////
std::string bin2hex(const std::string& bin) { return ""; }

//////////////////////////////////////////////////////////////////////////////////////////
/// @brief helper function to translate a hexadecimal string to binary
/// @param hex hexadecimal string to be translated
//////////////////////////////////////////////////////////////////////////////////////////
std::string hex2bin(const std::string& hex) { return ""; }

//////////////////////////////////////////////////////////////////////////////////////////
/// @brief function to sign extend values
/// @param value the value to be sign extended
/// @param numDigits the number of digits to include in the return string; default 32
//////////////////////////////////////////////////////////////////////////////////////////
std::string signExt(const std::string& value, int numDigits = 32) { return ""; }

//////////////////////////////////////////////////////////////////////////////////////////
/// @brief function to shift left 2
/// @param value the value to be shifted
//////////////////////////////////////////////////////////////////////////////////////////
std::string shiftLeft2(const std::string& value) { return ""; }

//////////////////////////////////////////////////////////////////////////////////////
/// @brief tests the Utilities class
//////////////////////////////////////////////////////////////////////////////////////
void testUtilities() { }

#endif