#ifndef _MULTIPLEXOR_H_
#define _MULTIPLEXOR_H_

#include <string>

#include "OperationUnit.h"

//////////////////////////////////////////////////////////////////////////////////////////
/// @brief Multiplexor class
//////////////////////////////////////////////////////////////////////////////////////////

class Multiplexor : public OperationUnit {
  private:
    bool controlSignal{false};   ///< the control signal for the mux
    std::string option1{""};  ///< option 1 for the mux to select
    std::string option2{""};  ///< option 2 for the mux to select
    std::string result{""};   ///< the option that the mux selects

  public:
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Constructor for Multiplexor class
    ///
    /// @param num for this multiplexor instance (valid options 1-5)
    //////////////////////////////////////////////////////////////////////////////////////
    Multiplexor(const int num) : OperationUnit (num, "Multiplexor" + std::to_string(num)) {}

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Deleted Copy Constructor
    //////////////////////////////////////////////////////////////////////////////////////
    Multiplexor(const Multiplexor& other) = delete;

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Default destructor
    //////////////////////////////////////////////////////////////////////////////////////
    ~Multiplexor() = default;

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief sets the value of control signal
    //////////////////////////////////////////////////////////////////////////////////////
    void setControlSignal(bool control) { controlSignal = control; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief sets the value of option1
    //////////////////////////////////////////////////////////////////////////////////////
    void setOption1(std::string opt1) { option1 = opt1; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief sets the value of option2
    //////////////////////////////////////////////////////////////////////////////////////
    void setOption2(std::string opt2) { option2 = opt2; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief sets the value of result
    //////////////////////////////////////////////////////////////////////////////////////
    void setResult(std::string res) { result = res; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief gets the value of result
    /// @return string result value
    //////////////////////////////////////////////////////////////////////////////////////
    std::string& getResult() { return result; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief printing function
    //////////////////////////////////////////////////////////////////////////////////////
    virtual void print();

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Determines which other function to call
    ///
    /// @param c bit string Control line
    /// @param arg1 first argument for arithmetic
    /// @param arg2 second argument for arithmetic
    /// 
    /// @return string the argument to be chosen based on control
    //////////////////////////////////////////////////////////////////////////////////////
    virtual std::string operate(std::string control, std::string arg1, std::string arg2) { return ""; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Determines which other function to call
    ///
    /// @param control bool Control line
    /// @param arg1 first argument for arithmetic
    /// @param arg2 second argument for arithmetic
    //////////////////////////////////////////////////////////////////////////////////////
    virtual std::string operate(bool control, std::string arg1, std::string arg2);

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief tests the Multiplexor class
    //////////////////////////////////////////////////////////////////////////////////////
    void testMultiplexor() { }
};


#endif
