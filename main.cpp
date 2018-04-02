#include <string>
#include <unordered_map>

#include "Parser.h"
#include "Processor.h"


//////////////////////////////////////////////////////////////////////////////////////////
/// @brief Main function to drive the processor
/// @details uses command line arg to construct parser, owns processor, stores input booleans, calls for output, etc
//////////////////////////////////////////////////////////////////////////////////////////
int main() {

  Parser parser("sample_inputs/input.config");

  return 0;
}
