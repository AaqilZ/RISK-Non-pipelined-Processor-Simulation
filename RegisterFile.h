#ifndef _REGISTER_FILE_H_
#define _REGISTER_FILE_H_

#include "Unit.h"
//////////////////////////////////////////////////////////////////////////////////////////
/// @brief class for RegisterFile
//////////////////////////////////////////////////////////////////////////////////////////
class RegisterFile : public Unit {
  private:
    bool regWrite;                         ///< control line for writing to register
    int writeReg;                          ///< number of write register
    int readReg1;                          ///< number of read register 1
    int readReg2;                          ///< number of read register 2
    std::string readData1;                 ///< data from readReg1
    std::string readData2;                 ///< data from readReg2
    std::string writeData;                 ///< data to write
  public:
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Constructor for register file object
    //////////////////////////////////////////////////////////////////////////////////////
    RegisterFile() : Unit("RegisterFile") {}

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief deleted copy constructor
    //////////////////////////////////////////////////////////////////////////////////////
    RegisterFile(const RegisterFile& other) = delete;

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief destructor
    //////////////////////////////////////////////////////////////////////////////////////
    ~RegisterFile() {}

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief overloaded operator << for printing current state of register file
    /// @param os reference to ostream
    //////////////////////////////////////////////////////////////////////////////////////
    virtual std::ostream& operator<<(std::ostream& os) { return os; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @name Getters/Setters
    /// @{

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Accessor for the control value
    bool getRegWrite() { return regWrite; }
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief set control line
    /// @param control boolean value to set control line
    void setRegWrite(const bool control) {}
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Accessor for writeReg
    int getWriteReg() { return writeReg; }
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Setter for writeReg
    /// @param regNum number of the register to write
    void setWriteReg(const int regNum) {}
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Set the data to write to memory
    void setWriteData(const std::string data) {}
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Accessor for writeData
    std::string getWriteData() { return writeData; }
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Accessor for readReg1
    int getReadReg1() { return readReg1; }
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Setter for readReg1
    /// @param regNum number of the register to read
    void setReadReg1(const int regNum) {}
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Accessor for readReg2
    int getReadReg2() { return readReg2; }
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Setter for readReg2
    /// @param regNum number of the register to read
    void setReadReg2(const int regNum) {}
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Accessor for readData1
    std::string getReadData1() { return readData1; }
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Accessor for readData2
    std::string getReadData2() { return readData2; }

    /// @}
    //////////////////////////////////////////////////////////////////////////////////////

};

#endif