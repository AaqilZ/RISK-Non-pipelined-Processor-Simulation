#include <string>
#include <unordered_map>

#include "Parser.h"
#include "Processor.h"
#include <iostream>

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////
/// @brief Main function to drive the processor
/// @details uses command line arg to construct parser, owns processor, stores input booleans, calls for output, etc
//////////////////////////////////////////////////////////////////////////////////////////
int main() {
  std::string temp{"input.config"};
  Parser parser(temp);
  
  Processor processor{};

  parser.parseMIPS(processor.getInstructionData());
  parser.parseRegisterFile(processor.getRegisterData());
  parser.parseMemory(processor.getMemoryData());
  
////  processor.print();
  processor.process();
   
  return 0;
}
