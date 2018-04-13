#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <string>

//////////////////////////////////////////////////////////////////////////////////////////
/// @brief helper function to translate a binary string to decimal string
/// @param bin binary string to be translated
//////////////////////////////////////////////////////////////////////////////////////////
std::string bin2dec(const std::string& bin);
//TODO should these functions return a value or modify the parameter?

//////////////////////////////////////////////////////////////////////////////////////////
/// @brief helper function to translate a decimal value into a hex string
/// @param dec the decimal value to translate
//////////////////////////////////////////////////////////////////////////////////////////
std::string dec2hex(int dec) { return ""; }

//////////////////////////////////////////////////////////////////////////////////////////
/// @brief helper function to translate hex to integer
/// @param hex the hex string to translate
//////////////////////////////////////////////////////////////////////////////////////////
int hex2dec(std::string hex) { return -1; }

//////////////////////////////////////////////////////////////////////////////////////////
/// @brief helper function to translate a binary string to hex
/// @param bin binary string to be translated
//////////////////////////////////////////////////////////////////////////////////////////
std::string bin2hex(const std::string& bin);

//////////////////////////////////////////////////////////////////////////////////////////
/// @brief helper function to translate a hexadecimal string to binary
/// @param hex hexadecimal string to be translated
//////////////////////////////////////////////////////////////////////////////////////////
std::string hex2bin(const std::string& hex);

//////////////////////////////////////////////////////////////////////////////////////////
/// @brief function to sign extend values
/// @param value the value to be sign extended
/// @param numDigits the number of digits to include in the return string; default 32
//////////////////////////////////////////////////////////////////////////////////////////
std::string signExt(std::string& num, const std::string& value, int numDigits);

//////////////////////////////////////////////////////////////////////////////////////////
/// @brief function to shift left 2
/// @param value the value to be shifted. Assumes either bin or hex.
//////////////////////////////////////////////////////////////////////////////////////////
std::string shiftLeft2(const std::string& value);

//////////////////////////////////////////////////////////////////////////////////////
/// @brief tests the Utilities class
//////////////////////////////////////////////////////////////////////////////////////
void testUtilities() { }

#endif
