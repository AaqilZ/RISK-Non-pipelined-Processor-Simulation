#include "Parser.h"

#include <fstream>
#include <iostream>
#include <string>
#include <locale>

using namespace std;

void
Parser::
parseInput(){
  ifstream inputFile;
  inputFile.open(inputFileName);
  // Confirm file was successfully opened
  if(!inputFile){
    // if not, throw error message and exit
    cerr << "Unable to open file '" << inputFileName << "'." << endl;
    exit(0);
  }
  // set up variables for splitting input strings
  string input;
  string var, result;
  size_t splitInd;
  int numCharInVar;
  while(inputFile >> input){  
    splitInd = input.find("=");
    numCharInVar = input.length() - splitInd;
    var = input.substr(0, input.length() - numCharInVar);
    result = input.substr(input.length() - numCharInVar + 1);
    if (var == "program_input"){
      mipsFileName = result;
    }
    else if (var == "memory_contents_input")
      memoryFileName = result;
    else if (var == "register_file_input")
      registerFileName = result;
    else if (var == "output_mode")
      outputMode = result;
    else if (var == "debug_mode"){
      if(result == "true")
        debug = true;
      else 
        debug = false;
    }
    else if (var == "print_memory_contents"){
      if(result == "true")
        printMemory = true;
      else 
        printMemory = false;
    }
    else if (var == "write_to_file"){
      if(result == "true")
        writeToFile = true;
      else 
        writeToFile = false;
    }
    else if (var == "output_file")
      outputFile = result;
    // if line is a comment
    else if (input.at(0) == '#'){
      // ignore the entire line
      getline(inputFile,input);
    }
    else
    // output an error that identifies what parameter is invalid, and tells the options for parameters.
      cerr << "Input file has invalid parameter '" << var << "'. Options are: 'program_input', 'memory_contents_input', 'register_file_input', 'output_mode', 'debug_mode', 'print_memory_contents', 'write_to_file', and 'output_file'." << endl;
  }
}

void
Parser::
testParser(){
  cout << "Testing parseInput(): " << endl;
  cout << "\tinputFileName: " << inputFileName << endl;
  cout << "\tmipsFileName: " << mipsFileName << endl;
  cout << "\tregisterFileName: " << registerFileName << endl;
  cout << "\tmemoryFileName: " << memoryFileName << endl;
  cout << "\toutputMode: " << outputMode << endl;
  cout << "\tdebug: " << debug << endl;
  cout << "\tprintMemory: " << printMemory << endl;
  cout << "\twriteToFile: " << writeToFile << endl;
  cout << "\toutputFile: " << outputFile << endl;
}