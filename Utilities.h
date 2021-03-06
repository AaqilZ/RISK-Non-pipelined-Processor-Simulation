#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <string>


//////////////////////////////////////////////////////////////////////////////////////////
/// @brief helper function to translate a binary string to decimal string
/// @param bin binary string to be translated
//////////////////////////////////////////////////////////////////////////////////////////
std::string bin2dec(const std::string& bin);

//////////////////////////////////////////////////////////////////////////////////////////
/// @brief helper function to translate a decimal value into a hex string
/// @param dec the decimal value to translate
//////////////////////////////////////////////////////////////////////////////////////////
std::string dec2hex(int dec); 

//////////////////////////////////////////////////////////////////////////////////////////
/// @brief helper function to translate hex to integer
/// @param hex the hex string to translate
//////////////////////////////////////////////////////////////////////////////////////////
std::string hex2dec(std::string hex); 

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
std::string signExt(const std::string& value, size_t numDigits = 32);

//////////////////////////////////////////////////////////////////////////////////////////
/// @brief unsigned extend
//////////////////////////////////////////////////////////////////////////////////////////
std::string unsignedExt(const std::string& value, size_t numDigits);

//////////////////////////////////////////////////////////////////////////////////////////
/// @brief function to shift left 2
/// @param value the value to be shifted. Assumes either bin or hex.
//////////////////////////////////////////////////////////////////////////////////////////
std::string shiftLeft2(const std::string& value, bool conserveBits);

//////////////////////////////////////////////////////////////////////////////////////////
/// @brief converts a decimal value to a binary string
/// @param value the value to convert
//////////////////////////////////////////////////////////////////////////////////////////
std::string dec2bin(int value);

//////////////////////////////////////////////////////////////////////////////////////////
/// @brief converts a decimal value to a binary string
/// @param value decimal value to convert
/// @param length the number of digits in the resulting string
//////////////////////////////////////////////////////////////////////////////////////////
std::string dec2bin(int value, size_t length);

//////////////////////////////////////////////////////////////////////////////////////
/// @brief handles twos comp for subtraction
///
/// @param arg2 the argument to be converted to twos comp for subtraction
//////////////////////////////////////////////////////////////////////////////////////
std::string twosComp(std::string& arg1);

//////////////////////////////////////////////////////////////////////////////////////////
/// @brief tests the Utilities class
//////////////////////////////////////////////////////////////////////////////////////////
void testUtilities();

#endif
