#include "Parser.h"
#include "Instruction.h"

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <cstdlib>

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
  string input, var, result;
  size_t splitInd;
  int numCharInVar;
  // while more input to be had
  while(inputFile >> input){  
    // figure out indices to split at
    splitInd = input.find("=");
    numCharInVar = input.length() - splitInd;
    // get appropriate substrings
    var = input.substr(0, input.length() - numCharInVar);
    result = input.substr(input.length() - numCharInVar + 1);
    // set correct variable to read value
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
  // close input stream
  inputFile.close();
}

void
Parser::
parseMIPS(unordered_map<string, Instruction>& mem){
  ifstream inputFile;
  inputFile.open(mipsFileName);
  // Confirm file was successfully opened
  if(!inputFile){
    // if not, throw error message and exit
    cerr << "Unable to open file '" << inputFileName << "'." << endl;
    exit(0);
  }

  // set variables to start
  string input;
  long address = 67108864;
  // while inputFile is good
  // while(inputFile.good()){
  // getline(inputFile, input);    
  //   // if the line is not blank or a comment
  //   if(input != "" && input.at(0) != '#' && input != eof()){
  //     // construct Instruction object
  //     Instruction i;
  //     i.parseInstruction(input);
  //     // add it to map with address as key TODO this should add at hex address
  //     mem[to_string(address)] = i;
  //     // increment address
  //     address += 4;
  //   }
  // }
  // cout << endl << endl;

  for( std::string input; getline(inputFile, input); ){
    // cout << input.length() << "  " << input << endl;
    if(input.length() > 0 && input.at(0) != '#' && input != "\t" && input != " "){
      //construct instruction object
      Instruction i;
      i.parseInstruction(input);
      // add it to map with address as key TODO this should add at hex address
      mem[to_string(address)] = i;
      // increment address
      address += 4;
    }
  }


  // for(auto iter = mem.begin(); iter != mem.end(); ++iter){
  //   cout << iter->first << " : " << iter->second.getOpcode() << endl;
  // }

  inputFile.close();
}

void
Parser::
parseRegisterFile(string (&r)[32]){
  ifstream inputFile;
  inputFile.open(registerFileName);
  // Confirm file was successfully opened
  if(!inputFile){
    // if not, throw error message and exit
    cerr << "Unable to open file '" << inputFileName << "'." << endl;
    exit(0);
  }
  string in;
  int splitInd;
  for(int i = 0; i < 32; ++i){
    inputFile >> in;
    splitInd = in.find(':');
    r[i] = in.substr(splitInd + 1);
    // cout << r[i] << endl;
  }
  // close the input stream
  inputFile.close();
}


void
Parser::
parseMemory(unordered_map<string, string>& mem){
  ifstream inputFile;
  inputFile.open(memoryFileName);
  // Confirm file was successfully opened
  if(!inputFile){
    // if not, throw error message and exit
    cerr << "Unable to open file '" << inputFileName << "'." << endl;
    exit(0);
  }
  // int count = 0;
  // set up local variables for parsing
  string input, address, memory;
  // while there's more in the file
  while (inputFile >> input){
    // if input is not a comment
    if(input.at(0) != '#'){
      // split the string into address and memory content
      address = input.substr(0, 8);
      memory = input.substr(9);
      // cout << "Input: " << input << endl;
      // cout << "Var: " << address << endl;
      // cout << "Result: " << memory << endl;
      // ++count;
      // cout << "Number of things in memory: " << count << endl;
      // add it to the unordered_map containing memory
      mem.emplace(address, memory);
    }
  }

  // for(auto iter = mem.begin(); iter != mem.end(); ++iter){
  //   cout << iter->first << " : " << iter->second << endl;
  // }

  // close the input stream
  inputFile.close();
}

void
Parser::
testParser(){
  cout << "Testing parseInput(): " << endl;
  cout << "\tinputFileName: " << inputFileName << " [Expected: sample_inputs/input.config]" << endl;
  cout << "\tmipsFileName: " << mipsFileName << " [Expected: prog1.asm]" << endl;
  cout << "\tregisterFileName: " << registerFileName << " [Expected: register1.memory]" << endl;
  cout << "\tmemoryFileName: " << memoryFileName << " [Expected: data1.memory]" << endl;
  cout << "\toutputMode: " << outputMode << " [Expected: single_step]" << endl;
  cout << "\tdebug: " << debug << " [Expected: 0]" << endl;
  cout << "\tprintMemory: " << printMemory << " [Expected: 1]" << endl;
  cout << "\twriteToFile: " << writeToFile << " [Expected: 0]" << endl;
  cout << "\toutputFile: " << outputFile << " [Expected: file1.output]" << endl;

  std::unordered_map<std::string,std::string> mem;

  cout << endl << "Results of parseMemory(mem): " << endl;
  parseMemory(mem);
  cout << "\tNumber of elements in memory: " << mem.size() << " [Expected: 100]" << endl;
  cout << "\tElements in memory after input: " << endl;
  for(auto iter = mem.begin(); iter != mem.end(); ++iter){
    cout << "\t\t" << iter->first << " : " << iter->second << endl;
  }

  std::unordered_map<std::string, Instruction> inst;
  cout << endl << "Results of parseMIPS(inst);" << endl;
  parseMIPS(inst);
  cout << "\tNumber of instructions: " << inst.size() << " [Expected: 10]" << endl;
  cout << "\tInstructions in memory after input: " << endl;
  for(auto iter = inst.begin(); iter != inst.end(); ++iter){
    cout << "\t\t" << iter->first << " : " << iter->second.getOpcode() << endl;
  }
}