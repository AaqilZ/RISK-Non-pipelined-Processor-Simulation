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
* program_input
   About: string for name of input file containing MIPS assembly code
   Ex:    program_input=Input.asm
* memory_contents_input
   About: string for name of input file containing contents of main memory at beginning of execution.
* register_file_input
   About: string for name of input file containing contents of register file at beginning of execution.
* output_mode
   Options: single_step <- if the user wishes to step through one instruction at a time
            batch       <- if the user wishes to execute the simulation of the full program at once
* debug_mode
   About: whether to print debugging information
   Options: true
            false
* print_memory_contents
   About: whether to print current register file and memory
   Options: true
            false
* write_to_file
   About: whether to prtin all output for run to file specified by output_file
   Options: true
            false
* output_file
   About: output filename


## Input Files

### In General
* Ignore:
   * blank lines
   * lines that start with "#"
* Hex:
   * values with a leading "0x" and without
   * Uppercase or Lowercase

#### Program Input File
Valid Commands: ADD, SUB, ADDI, SLT, LW, SW, BEQ, J

One instruction per line.
May assume this file is formatted correctly; no more than 100 lines

##### Branch and Jump Instructions
* will not havle labels
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