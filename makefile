EXECS = Processor
OBJS = Unit.o OperationUnit.o ProgramCounter.o Instruction.o RegisterFile.o Control.o Parser.o Utilities.o Multiplexor.o ALU.o Processor.o main.o

CC = g++
CCFLAGS = -std=c++11 -Wall -Wno-deprecated -Werror=return-type -g

all: $(EXECS)

Processor: $(OBJS)
	$(CC) $(CCFLAGS) $^ -o $@

%.o: %.cpp *.h
	$(CC) $(CCFLAGS) -c $<

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $<

clean:
	/bin/rm -f a.out $(OBJS) $(EXECS)
