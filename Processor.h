#ifndef _PROCESSOR_H_
#define _PROCESSOR_H_

#include <string>
#include <unordered_map>

#include "Unit.h"
#include "Instruction.h"
#include "ALU.h"
#include "Multiplexor.h"
#include "Control.h"
#include "RegisterFile.h"
#include "ProgramCounter.h"

//////////////////////////////////////////////////////////////////////////////////////////
/// @brief Processor class
/// @detail Processor should be able to print the state of all objects and should own objects to complete functionality
/// @note We will likely add helper methods that will break process() into smaller parts as we implement
//////////////////////////////////////////////////////////////////////////////////////////
class Processor : public Unit {

  private:
    std::unordered_map<std::string, Instruction> InstructionData;   ///< hashmap to store instructions
    std::unordered_map<std::string, std::string> MemoryData;        ///< hashmap to store data
    ALU* aluOne = new ALU(1);                                            ///< ALU for adding 4 to immediate value
    ALU* aluTwo = new ALU(2);                                            ///< ALU that receives from shift left 2 and sends data to mux
    ALU* aluThree = new ALU(3);                                          ///< ALU that receives from mux and read data one and sends data to data memory
    Multiplexor* muxRegDist = new Multiplexor(1);                        ///< MUX that receives the RegDist control signal
    Multiplexor* muxJump = new Multiplexor(2);                           ///< MUX that receives the Jump control signal
    Multiplexor* muxBranch = new Multiplexor(3);                         ///< MUX that receives the Branch control signal
    Multiplexor* muxMemToReg = new Multiplexor(4);                       ///< MUX that receives the MemToReg control signal
    Multiplexor* muxALUSrc = new Multiplexor(5);                         ///< MUX that receives the ALUSrc control signal
    Control* control = new Control();                                    ///< Main Control unit, also contains ALU Controller
    RegisterFile* registerFile = new RegisterFile();                     ///< RegisterFile to store registers and writes data
    ProgramCounter* programCounter = new ProgramCounter();               ///< ProgramCounter to keep track of the address of the instruction being executed

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
    /// @brief Method that runs the processor
    //////////////////////////////////////////////////////////////////////////////////////
    void process() {}

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief function that must be overridden by all children
    //////////////////////////////////////////////////////////////////////////////////////
    virtual std::ostream& operator<<(const std::ostream& os) = 0;

};

#endif