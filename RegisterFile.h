#ifndef _REGISTER_FILE_H_
#define _REGISTER_FILE_H_

#include <fstream>

extern bool printMemory;
extern bool writeToFile;
extern std::ofstream o;

#include "Unit.h"
//////////////////////////////////////////////////////////////////////////////////////////
/// @brief class for RegisterFile
//////////////////////////////////////////////////////////////////////////////////////////
class RegisterFile : public Unit {
  private:
    bool regWrite{false};                         ///< control line for writing to register
    int writeReg{0};                          ///< number of write register
    int readReg1{0};                          ///< number of read register 1
    int readReg2{0};                          ///< number of read register 2
    std::string readData1{""};                 ///< data from readReg1
    std::string readData2{""};                 ///< data from readReg2
    std::string writeData{""};                 ///< data to write
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
    /// @brief printing function
    //////////////////////////////////////////////////////////////////////////////////////
    virtual void print();

    //////////////////////////////////////////////////////////////////////////////////////
    /// @name Getters/Setters
    /// @{

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Accessor for the control value
    bool getRegWrite() { return regWrite; }
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief set control line
    /// @param control boolean value to set control line
    void setRegWrite(const bool control) { regWrite = control; }
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Accessor for writeReg
    int getWriteReg() { return writeReg; }
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Setter for writeReg
    /// @param regNum number of the register to write
    void setWriteReg(const int regNum) { writeReg = regNum; }
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Set the data to write to memory
    void setWriteData(const std::string data) { writeData = data; }
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Accessor for writeData
    std::string getWriteData() { return writeData; }
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Accessor for readReg1
    int getReadReg1() { return readReg1; }
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Setter for readReg1
    /// @param regNum number of the register to read
    void setReadReg1(const int regNum) { readReg1 = regNum; }
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Accessor for readReg2
    int getReadReg2() { return readReg2; }
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Setter for readReg2
    /// @param regNum number of the register to read
    void setReadReg2(const int regNum) { readReg2 = regNum; }
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Setter for readData1
    /// @param data data to set
    void setReadData1(std::string data) { readData1 = data; }
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Setter for readData2
    /// @param data data to set
    void setReadData2(std::string data) { readData2 = data; }
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Accessor for readData1
    std::string& getReadData1() { return readData1; }
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Accessor for readData2
    std::string& getReadData2() { return readData2; }

    /// @}
    //////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief tests the RegisterFile class
    //////////////////////////////////////////////////////////////////////////////////////
    void testRegisterFile() { }

};

#endif