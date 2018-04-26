#ifndef _PARSER_H_
#define _PARSER_H_

#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>

#include "Instruction.h"
#include "RegisterFile.h"

extern bool singleStep;
extern bool debug;
extern bool printMemory;
extern bool writeToFile;
extern std::ofstream o;

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
    std::string outputFile;                   ///< name of file to write to

  public:
    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Constructor
    ///
    /// @param file L-value reference to name of input file (should come from command line)
    Parser(std::string& file);

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
    /// @param mem Reference to map owned by processor
    void parseMIPS(std::unordered_map<std::string, Instruction>& mem);

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Parses the registerfile state
    /// @details Passed a reference to an already existing RegisterFile object owned by processor or main
    /// @param r l-value reference to vector with register contents
    void parseRegisterFile(std::vector<std::string>& r);

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief Parses the memory file
    /// @return reference to unordered map of memory data <address, memory value> -- must be converted from hex to bin
    /// @param mem Reference to the map owned by processor
    void parseMemory(std::unordered_map<std::string,std::string>& mem);

    //////////////////////////////////////////////////////////////////////////////////////
    /// @brief tests the Parser class
    //////////////////////////////////////////////////////////////////////////////////////
    void testParser();
};

#endif