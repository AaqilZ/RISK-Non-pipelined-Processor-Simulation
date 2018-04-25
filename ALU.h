#ifndef _ALU_H_
#define _ALU_H_

#include "OperationUnit.h"

//////////////////////////////////////////////////////////////////////////////////////////
/// @brief Class for general ALU functionality
//////////////////////////////////////////////////////////////////////////////////////////
class ALU : public OperationUnit {
  private:
    std::string control;      ///< control signal that will tell the ALU what operation to do
    std::string inputOne;     ///< first input for ALU
    std::string inputTwo;     ///< second input for ALU
    std::string ALUresult;    ///< the result of the intended ALU operation
    std::string funcCode;     ///< the function code for ALUcontrol
    bool ALUop1;              ///< the ALUop1 control signal
    bool ALUop2;              ///< the ALUop2 control signal
    bool zero;                ///< the zero contorl signal
    
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
    virtual std::string operate(std::string control, std::string arg1, std::string arg2);

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Determines which other function to call
    ///
    /// @param control bool Control line
    /// @param arg1 first argument for arithmetic
    /// @param arg2 second argument for arithmetic
    //////////////////////////////////////////////////////////////////////////////////////
    virtual std::string operate(bool control, std::string arg1, std::string arg2) { return ""; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Handles addition
    //////////////////////////////////////////////////////////////////////////////////////
    std::string add(std::string& arg1, std::string& arg2);

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief handles twos comp for subtraction
    ///
    /// @param arg2 the argument to be converted to twos comp for subtraction
    //////////////////////////////////////////////////////////////////////////////////////
    // std::string twosComp(std::string& arg1);

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
    /// @brief printing function
    //////////////////////////////////////////////////////////////////////////////////////
    virtual void print();

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief sets the value of the ALU control signal
    //////////////////////////////////////////////////////////////////////////////////////
    void setControl(bool ALUop1, bool ALUop2, std::string func);

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief sets the value of the ALU inputOne
    //////////////////////////////////////////////////////////////////////////////////////
    void setInputOne(std::string input) { inputOne = input; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief sets the value of the ALU inputTwo
    //////////////////////////////////////////////////////////////////////////////////////
    void setInputTwo(std::string input) { inputTwo = input; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief sets the value of the ALU result
    //////////////////////////////////////////////////////////////////////////////////////
    void setALUresult(std::string result) { ALUresult = result; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief sets the value of funcCode
    //////////////////////////////////////////////////////////////////////////////////////
    void setFuncCode(std::string code) { funcCode = code; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief sets the value of the ALUop1
    //////////////////////////////////////////////////////////////////////////////////////
    void setALUop1(bool op) { ALUop1 = op; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief sets the value of the ALUop2
    //////////////////////////////////////////////////////////////////////////////////////
    void setALUop2(bool op) { ALUop2 = op; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief sets the value of the ALUop2
    //////////////////////////////////////////////////////////////////////////////////////
    void setZero(bool zed) { zero = zed; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief gets the value of the ALU inputOne
    /// @return value of inputOne
    //////////////////////////////////////////////////////////////////////////////////////
    std::string getInputOne() { return inputOne; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief gets the value of the ALU inputTwo
    /// @return value of inputTwo
    //////////////////////////////////////////////////////////////////////////////////////
    std::string getInputTwo() { return inputTwo; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief gets the value of the ALU result
    /// @return the value of ALUresult
    //////////////////////////////////////////////////////////////////////////////////////
    std::string getALUresult() { return ALUresult; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief gets the value of funcCode
    /// @return the value of
    //////////////////////////////////////////////////////////////////////////////////////
    std::string getFuncCode() { return funcCode; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief gets the value of the ALUop1
    /// @return the value of
    //////////////////////////////////////////////////////////////////////////////////////
    bool getALUop1() { return ALUop1; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief gets the value of the ALUop2
    /// @return the value of ALUop2
    //////////////////////////////////////////////////////////////////////////////////////
    bool getALUop2() { return ALUop2; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief sets the value of the ALUop2
    /// @return bool zero
    //////////////////////////////////////////////////////////////////////////////////////
    bool getZero() { return zero; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief tests the ALU class
    //////////////////////////////////////////////////////////////////////////////////////
    void testALU();
};

#endif