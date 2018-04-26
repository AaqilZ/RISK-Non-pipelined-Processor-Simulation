#include <string>
#include <unordered_map>

#include "Parser.h"
#include "Processor.h"
#include <iostream>
#include "Utilities.h"

using namespace std;

bool singleStep{false};                          ///< whether to print in single steps
bool debug{false};                               ///< whether to print debugging info
bool printMemory{false};                         ///< whether to print memory contents
bool writeToFile{false};                         ///< whether to write output to file
std::ofstream o;                                 ///< the file stream to write to if writeToFile is true


//////////////////////////////////////////////////////////////////////////////////////////
/// @brief Main function to drive the processor
/// @details uses command line arg to construct parser, owns processor, stores input booleans, calls for output, etc
//////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[]) {

  std::string input{argv[1]};
  Parser parser(input);
  
  Processor processor{};

  parser.parseMIPS(processor.getInstructionData());
  parser.parseRegisterFile(processor.getRegisterData());
  parser.parseMemory(processor.getMemoryData());
  
  processor.print();
  processor.process();

  o.close();
   
  return 0;
}
