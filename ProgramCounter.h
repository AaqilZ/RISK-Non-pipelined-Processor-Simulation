#ifndef _PROGRAM_COUNTER_H_
#define _PROGRAM_COUNTER_H_

#include "ALU.h"
#include "Unit.h"

class ALU;

class ProgramCounter : Unit {

  private:
    std::string instrAddr;                   ///< current instruction address

  public:
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Constructor
    /// 
    /// @param addr First address to initialize the PC
    //////////////////////////////////////////////////////////////////////////////////////
    ProgramCounter(std::string& addr) : Unit("Program Counter") { instrAddr = addr; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Copy Constructor
    //////////////////////////////////////////////////////////////////////////////////////
    ProgramCounter(const ProgramCounter& other) = delete;

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Destructor
    //////////////////////////////////////////////////////////////////////////////////////
    ~ProgramCounter() {}

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Getter
    //////////////////////////////////////////////////////////////////////////////////////
    std::string getPC() { return instrAddr; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Setter
    //////////////////////////////////////////////////////////////////////////////////////
    void setPC(std::string& addr) { instAddr = addr; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief overload operator << to output the current state of the program counter
    //////////////////////////////////////////////////////////////////////////////////////
    virtual ostream& operator<<(ostream& os) {}
};

#endif