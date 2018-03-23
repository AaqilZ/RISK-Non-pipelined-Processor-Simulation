#ifndef _CONTROL_H_
#define _CONTROL_H_

#include "Unit.h"

class Control : Unit {
  private:
    bool regDst;                          ///< false: write reg # from rt; true: write reg from rd
    bool jump;                            ///< whether to have PC jump
    bool branch;                          ///< false: PC = PC + 4; true: PC = branch
    bool memRead;                         ///< False: none; true: data memory designated by address input are moved to Read data output
    bool memToReg;                        ///< false: value fed to register Write data input comes from ALU; true: value fed to the register Write data comes from the data memory
    bool ALUOp0;                          ///< true for branch
    bool ALUOp1;                          ///< true for r-format
    bool memWrite;                        ///< false: none; true: data memory designated by adddress input are replaced by value on Write data input
    bool ALUSrc;                          ///< false: 2nd ALU op from 2nd reg file output; true: 2nd ALU op is sign extended 16 bits of instruction
    bool regWrite;                        ///< write to reg with value on Write data input
    std::string ALUControl;               ///< control signal for main ALU (4 digits)

  public:
    //////////////////////////////////////////////////////////////////////////////////////
    /// @name Constructors and Destructor
    /// @{

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Constructor 
    Control() : Unit("Control") {}

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Deleted copy constructor
    Control(const Control& other) = delete;

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Destructor
    ~Control() {}

    /// @}
    //////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////
    /// @name Getters/Setters
    /// @{

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Clear all control lines
    void clear() {}

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Set regDst
    /// @param control Value to set
    void setRegDst(bool control) { regDst = control; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Get regDst
    bool getRegDst() { return regDst; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Set jump control value
    /// @param control Value to set
    void setJump(bool control) { jump = control; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Get jump control value
    bool getJump() { return jump; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Set branch control value
    /// @param control Value to set
    void setBranch(bool control) { branch = control; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Get branch control value
    bool getBranch() { return branch; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Set memRead control value
    /// @param control Value to set
    void setMemRead(bool control) { memRead = control; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Get memRead control value
    bool getMemRead() { return memRead; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Set memToReg control value
    /// @param control Value to set
    void setMemToReg(bool control) { memToReg = control; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Get memToReg control value
    bool getMemToReg() { return memToReg; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Set ALUOp0 control value
    /// @param control Value to set
    void setALUOp0(bool control) { ALUOp0 = control; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Get ALUOp0 control value
    bool getALUOp0() { return ALUOp0; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Set ALUOp1 control value
    /// @param control Value to set
    void setALUOp1(bool control) { ALUOp1 = control; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Get ALUOp1 control value
    bool getALUOp1() { return ALUOp1; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Set memWrite control value
    /// @param control Value to set
    void setMemWrite(bool control) { memWrite = control; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Get memWrite control value
    bool getMemWrite() { return memWrite; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Set ALUSrc control value
    /// @param control Value to set
    void setALUSrc(bool control) { ALUSrc = control; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Get ALUSrc control value
    bool getALUSrc() { return ALUSrc; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Set regWrite control value
    /// @param control Value to set
    void setRegWrite(bool control) { regWrite = control; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Get regWrite control value
    bool getRegWrite() { return regWrite; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Set ALUControl control value
    /// @param control Value to set
    void setALUControl(std::string control) { ALUControl = control; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Get ALUControl control value
    std::string getALUControl() { return ALUControl; }

    /// @}
    //////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Operator << overload
    /// @param os Reference to ostream
    virtual std::ostream& operator<<(const std::ostream& os) {}

};

#endif