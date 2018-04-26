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
  // cout << "########################## 1 #############################" << endl;
  std::string input{argv[1]};
  // cout << "########################## 2 #############################" << endl;
  Parser parser(input);
  // cout << "########################## 3 #############################" << endl;
  Processor processor{};
  // cout << "########################## 4 #############################" << endl;
  processor.getInstructionData();
  // cout << "########################## 4 and a half #############################" << endl;
  parser.parseMIPS(processor.getInstructionData());
  // cout << "########################## 5 #############################" << endl;
  parser.parseRegisterFile(processor.getRegisterData());
  // cout << "########################## 6 #############################" << endl;
  parser.parseMemory(processor.getMemoryData());
  // cout << "########################## 7 #############################" << endl;
  
  processor.print();
  processor.process();

  o.close();
   
  return 0;
}
