#ifndef _CONTROL_H_
#define _CONTROL_H_

#include "Unit.h"

class Control : Unit {
  private:
    bool regDst;                          ///< 
    bool jump;                            ///< whether to have PC jump
    bool branch;                          ///< whether to branch
    bool memRead;                         ///< 
    bool memToReg;                        ///< 
    bool ALUOp0;                          ///< 
    bool ALUOp1;                          ///< 
    bool memWrite;                        ///< 
    bool ALUSrc;                          ///< 
    bool regWrite;                        ///< whether to write to a register
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
    /// @brief Operator << overload
    /// @param os Reference to ostream
    virtual std::ostream& operator<<(const std::ostream& os) {}

};

#endif