#ifndef _INSTRUCTION_H_
#define _INSTRUCTION_H_

#include <string>
#include <iostream>

enum type{RTYPE, ITYPE, JTYPE};
//////////////////////////////////////////////////////////////////////////////////////////
/// @brief Instruction class
//////////////////////////////////////////////////////////////////////////////////////////
class Instruction {
  private:
    std::string binStr{""};                 ///< binary string of instruction
    std::string opcode{""};                 ///< stores the opcode of the instruction
    int rs = -1;                        ///< stores the rs register
    int rt = -1;                        ///< stores the rt register
    int rd = -1;                        ///< stores the rd register
    int imm = -1;                       ///< stores the immediate field
    std::string func{""};               ///< stores the function code of r-type instructions
    int type = -1;                      ///< stores enum for the type of instruction

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief parses the register number from a string starting with $
    /// @param r string of format $xx or $x
    int parseRegisterNumber(std::string r);

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief get offset value from string
    /// @param o string to get offset from
    int parseOffset(std::string o);

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief get immediate value from hex or decimal string
    /// @param hex or decimal string
    int parseImmediate(std::string i);

  public:
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Instruction constructor
    /// @details This function should take a string of MIPS assembly, parse it into relevant
    /// parts and create the instruction object to be added to the InstructionData hashmap 
    //////////////////////////////////////////////////////////////////////////////////////
    Instruction() {}

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief constructor parses an input string
    //////////////////////////////////////////////////////////////////////////////////////
    Instruction(std::string inst) { parseInstruction(inst); computeBinaryEncoding(); }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Deleted Copy Constructor
    //////////////////////////////////////////////////////////////////////////////////////
    Instruction(const Instruction& other) = delete;

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Destructor
    //////////////////////////////////////////////////////////////////////////////////////
    ~Instruction() {}

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief parses instruction string from input file
    /// @param inst input string to be parsed
    //////////////////////////////////////////////////////////////////////////////////////
    void parseInstruction(std::string inst);

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief sets the binString for the instruction object
    void computeBinaryEncoding();

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief gets a bit range
    /// @param first the index of the first bit
    /// @param last the index of the last bit
    std::string getBits(int first, int second);

    int getImmediate() { return imm; }

    int getRd() { return rd; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief gets the opcode of the function
    std::string getOpcode() const { return opcode; }


    ////@TODO

    std::string getBinStr(){return binStr;}


    void print();

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief gets the opcode of the function
    std::string getFuncField() const { return func; }
    
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief tests the Instruction class
    //////////////////////////////////////////////////////////////////////////////////////
    void testInstruction();

};

#endif
