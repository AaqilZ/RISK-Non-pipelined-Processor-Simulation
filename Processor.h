#ifndef _PROCESSOR_H_
#define _PROCESSOR_H_

#include <string>
#include <unordered_map>
#include <vector>

#include "Unit.h"
#include "Instruction.h"
#include "ALU.h"
#include "Multiplexor.h"
#include "Control.h"
#include "RegisterFile.h"
#include "ProgramCounter.h"

extern bool singleStep;
extern bool printMemory;
extern bool writeToFile;
extern std::ofstream o;

//////////////////////////////////////////////////////////////////////////////////////////
/// @brief Processor class
/// @details Processor should be able to print the state of all objects and should own objects to complete functionality
/// @note We will likely add helper methods that will break process() into smaller parts as we implement
//////////////////////////////////////////////////////////////////////////////////////////
class Processor : public Unit {

  private:
    std::unordered_map<std::string, Instruction> InstructionData;   ///< hashmap to store instructions
    std::unordered_map<std::string, std::string> MemoryData;        ///< hashmap to store data
    std::vector<std::string> registerContents;                      ///< array to hold the register contents
    ALU aluOne{1};                                                  ///< ALU for adding 4 to immediate value
    ALU aluTwo{2};                                                  ///< ALU that receives from shift left 2 and sends data to mux
    ALU aluThree{3};                                                ///< ALU that receives from mux and read data one and sends data to data memory
    Multiplexor muxRegDist{1};                                      ///< MUX that receives the RegDist control signal
    Multiplexor muxJump{4};                                         ///< MUX that receives the Jump control signal
    Multiplexor muxBranch{5};                                       ///< MUX that receives the Branch control signal
    Multiplexor muxMemToReg{3};                                     ///< MUX that receives the MemToReg control signal
    Multiplexor muxALUSrc{2};                                       ///< MUX that receives the ALUSrc control signal
    Control control;                                                ///< Main Control unit, also contains ALU Controller
    RegisterFile registerFile;                                      ///< RegisterFile to store registers and writes data
    ProgramCounter programCounter;                                  ///< ProgramCounter to keep track of the address of the instruction being executed
    
    Instruction i;
    Instruction& currentInstruction = i;                                ///< a reference to the instruction that is currently being executed
    std::string signExtendedNum{""};                                    ///< the sign extended version of instruction bits 15-0

  public:
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Constructor for class
    //////////////////////////////////////////////////////////////////////////////////////
    Processor();

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Copy constructor
    //////////////////////////////////////////////////////////////////////////////////////
    Processor(const Processor& other) = delete;

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Destructor
    //////////////////////////////////////////////////////////////////////////////////////
    ~Processor() {}

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Method that runs the processor a single step
    //////////////////////////////////////////////////////////////////////////////////////
    void process();

    //////////////////////////////////////////////////////////////////////////////////////
    /// @name Getters
    /// @{
    
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief returns map of instruction objects
    std::unordered_map<std::string, Instruction>& getInstructionData() { return InstructionData; }
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief returns map of Memory data
    std::unordered_map<std::string, std::string>& getMemoryData() { return MemoryData; }
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief returns array of register contents
    std::vector<std::string>& getRegisterData() { return registerContents; }


    /// @}
    //////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief printing function
    //////////////////////////////////////////////////////////////////////////////////////
    virtual void print();

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief the fetch stage of the fetch execute cycle
    //////////////////////////////////////////////////////////////////////////////////////
    void fetch();

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief the decode stage of the fetch execute cycle
    //////////////////////////////////////////////////////////////////////////////////////
    void decode();

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief the execute stage of the fetch execute cycle
    //////////////////////////////////////////////////////////////////////////////////////
    void execute();

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief the memory stage of the fetch execute cycle
    //////////////////////////////////////////////////////////////////////////////////////
    void memory();

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief the writeback stage of the fetch execute cycle
    //////////////////////////////////////////////////////////////////////////////////////
    void writeback();

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief tests the Processor class
    //////////////////////////////////////////////////////////////////////////////////////
    void testProcessor() { }
};

#endif
