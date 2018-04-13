#ifndef _ALU_H_
#define _ALU_H_

#include "OperationUnit.h"

//////////////////////////////////////////////////////////////////////////////////////////
/// @brief Class for general ALU functionality
//////////////////////////////////////////////////////////////////////////////////////////
class ALU : public OperationUnit {
    
  public:
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Constructor for ALU unit class
    ///
    /// @param num number of this ALU instance (valid options 1-3)
    //////////////////////////////////////////////////////////////////////////////////////
    ALU(const int num) : OperationUnit(num, "ALU" + std::to_string(num)) {}

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief deleted copy constructor
    ///
    /// @param other Other instance to copy
    //////////////////////////////////////////////////////////////////////////////////////
    ALU(const ALU& other) = delete;

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Destructor
    //////////////////////////////////////////////////////////////////////////////////////
    ~ALU() = default;

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Determines which other function to call
    ///
    /// @param c bit string Control line
    /// @param arg1 first argument for arithmetic
    /// @param arg2 second argument for arithmetic
    /// 
    /// @return string the argument to be chosen based on control
    //////////////////////////////////////////////////////////////////////////////////////
    virtual std::string operate(std::string control, std::string& arg1, std::string& arg2) { return ""; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Handles addition
    //////////////////////////////////////////////////////////////////////////////////////
    std::string add(std::string& arg1, std::string& arg2);

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief handles twos comp for subtraction
    ///
    /// @param arg2 the argument to be converted to twos comp for subtraction
    //////////////////////////////////////////////////////////////////////////////////////
    std::string twosComp(std::string& arg1);

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief handles bitwise AND
    //////////////////////////////////////////////////////////////////////////////////////
    std::string bitwiseAND(std::string& arg1, std::string& arg2);

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief handles bitwise OR
    //////////////////////////////////////////////////////////////////////////////////////
    std::string bitwiseOR(std::string& arg1, std::string& arg2);

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief runs everything in the ALU
    /// @return result
    //////////////////////////////////////////////////////////////////////////////////////
    std::string run() { return ""; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief prints the current state of the ALU
    //////////////////////////////////////////////////////////////////////////////////////
    virtual std::ostream& operator<<(std::ostream& os) { return os; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief tests the ALU class
    //////////////////////////////////////////////////////////////////////////////////////
    void testALU();
};

#endif