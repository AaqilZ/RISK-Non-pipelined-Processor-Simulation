EXECS = Processor
OBJS = Unit.o ProgramCounter.o Instruction.o  Processor.o

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
