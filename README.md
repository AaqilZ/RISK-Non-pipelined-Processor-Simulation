# final-project-cmsc301
Simulation of a non-pipelined processor

### Documentation
``` bash
$ doxygen Doxyfile
```

### Create executable
``` bash
$ make [configurationFileName]
```


### Input file format
Configuration file must include:
* __program_input__
  - About: string for name of input file containing MIPS assembly code
  - Ex:    program_input=Input.asm
* __memory_contents_input__
  - About: string for name of input file containing contents of main memory at beginning of execution.
* __register_file_input__
  - About: string for name of input file containing contents of register file at beginning of execution.
* __output_mode__
  - Options: single_step <- if the user wishes to step through one instruction at a time
  - batch       <- if the user wishes to execute the simulation of the full program at once
* __debug_mode__
  - About: whether to print debugging information
  - Options: [true, false]
* __print_memory_contents__
  - About: whether to print current register file and memory
  - Options: [true, false]
* __write_to_file__
  - About: whether to prtin all output for run to file specified by output_file
  - Options: [true, false]
* __output_file__
  - About: output filename


## Input Files

### In General
* Ignore:
   * blank lines
   * lines that start with "#"
* Hex:
   * values with a leading "0x" and without
   * Uppercase or Lowercase

#### Program Input File
Valid Commands: 
* ADD
* SUB
* ADDI
* SLT
* LW
* SW
* BEQ
* J

One instruction per line.
May assume this file is formatted correctly; no more than 100 lines

##### Branch and Jump Instructions
* will not have labels
* will have hexadecimal strings (preceeded by 0x)
   * can be either positive or negative (twos comp)

##### Addi
* immediate value can be either hexadecimal or decimal

##### Load and Store
* immediate value will be decimal
   * may be positive or negative

##### Registers
* encoded by their number preceeded by "$"

#### Memory Input File
ASCII text file with contents of memory before code execution; may assume correct format; no more than 100 words of data

Each line of the file has a single 4 byte word; big endian; consecutive order

<address:data value>

Ex: <44578220:a7c31002>

#### Register Input File
ASCII test file with contents of register file before code execution; may assume correct format

Each line represents a single 4 byte word stored in a register.

<register number:data value>

Ex <21:a7c3be21>

Must list contents of __every__ register in order (always 32 lines)

## Output
Program must output:

_assembly instruction being executed_

* all control signals on all lines
* input for all components
* output for all components
* control signals on all components

__If print_memory contents is true__
* entire contents of data memory
* instruction memory
* register file

Expected Control Signals:
* RegDst
* Jump
* Branch
* MemRead
* MemToReg
* ALUOp0
* ALUOp1
* MemWrite
* ALUSrc
* RegWrite
* ALUControl -> main ALU (4 digits)

__ALL OUTPUT MUST BE IN HEX__ (with leading 0x)

## Objects to Include

* Program Counter
* Instruction Memory
  * Hashmap of <address:Instruction>
* Register File
  * Read and Write Registers and data

* Data Memory
* 3 ALUs (numbered 1 through 3)
* 5 Multiplexors (numbered 1 through 5)
* 2 "shift left 2" units (numbered 1 and 2)
* a main control unit
* an ALU control unit
* a sign extend unit

### Objects in Design

* __Instruction Object__
  * op rs rt rd immediate
  * 
* __Instruction Memory__
  * Hashmap of <address:Instruction> owned by something else; not an actual object
* __Data Memory__
  * Hashmap of <address:word> owned by something else; not an actual object
* __Register Data__
  * array that stores the current state of the registers; owned by something else; not an object
* __Program Counter__
  * store currentAddress
  * has a getter and a setter
  * increment PC + 4 no matter what
  * jump instructions
    * bit shift immediate left 2
    * send PC + 4 to multiplexor, then concatonate left 4 bits of PC with bit shifted immediate value (28 bits)
* Processor
  * Owns above hashmaps; program counter; other objects
* 

### Steps:
1. Parse Input Files
   1. Read MIPS assembly file
      * Each line should be converted into an Instruction object and added to the Instruction Memory hashmap
   2. Read Memory Input file
      * Each line should be read and parsed
        * [ ] split into address and word value
        * [ ] added to Data Memory hashmap
2. Run instructions in order according to value in the PC
   1. Jump Instructions:
      * 
