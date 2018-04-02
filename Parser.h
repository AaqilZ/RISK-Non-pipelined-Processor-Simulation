#ifndef _PARSER_H_
#define _PARSER_H_

#include <string>
#include <unordered_map>

#include "Instruction.h"
#include "RegisterFile.h"

//////////////////////////////////////////////////////////////////////////////////////////
/// @brief Class to parse inputs
/// @note TODO Decide if methods should be private
//////////////////////////////////////////////////////////////////////////////////////////
class Parser {
  private:
    std::string inputFileName;                ///< name of input file
    std::string mipsFileName;                 ///< name of mips file (from input file)
    std::string registerFileName;             ///< name of register data file (from input file)
    std::string memoryFileName;               ///< name of memory data file (from input file)
    std::string outputMode;                   ///< either single-step or batch
    bool debug;                               ///< whether to print debugging info
    bool printMemory;                         ///< whether to print memory contents
    bool writeToFile;                         ///< whether to write output to file
    std::string outputFile;                   ///< name of file to write to

  public:
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Constructor
    ///
    /// @param file Name of input file (should come from command line)
    Parser(std::string file) { inputFileName = file; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Deleted copy constructor
    /// @param other Reference to object to be copied
    Parser(const Parser& other) = delete;

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Default destructor
    ~Parser() = default;

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Parses the input file using inputFileName to set names of other files
    void parseInput();


    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Parses the MIPS assembly code
    /// @details Calls the Instruction constructor
    /// @return unordered map of instructions
    /// @param mem Reference to map owned by processor
    const std::unordered_map<std::string, Instruction>& 
    parseMIPS(const std::unordered_map<std::string, Instruction>& mem) { return mem; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Parses the registerfile state
    /// @details Passed a reference to an already existing RegisterFile object owned by processor or main
    /// @param r Const reference to RegisterFile object
    /// @return Reference to the RegisterFile object
    const RegisterFile& parseRegisterFile(const RegisterFile& r) { return r; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Parses the memory file
    /// @return reference to unordered map of memory data <address, memory value> -- must be converted from hex to bin
    /// @param mem Reference to the map owned by processor
    const std::unordered_map<std::string, std::string>& 
    parseMemory(const std::unordered_map<std::string,std::string>& mem) { return mem; }

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief tests the Parser class
    //////////////////////////////////////////////////////////////////////////////////////
    void testParser();
};

#endif