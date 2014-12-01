# Compiler: The GNU Compiler Collection
CC = gcc

# Compiler flags
#	Wall	- (Almost) all warnings on
#	Werror	- Don't allow compiling if there are any warnings
#	ansi	- Follow ansi standard
#	std=c11 - Follow c11 standard
CFLAGS = -Wall -Werror -ansi -std=c11

# Object files
OBJECTS = stackTest.o stack.o

# Executable name
EXE = stackTest.exe

# Build program
$(EXE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS)

# Compile Object files
stackTest.o: stackTest.o
	$(CC) $(CFLAGS) -c stackTest.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

# Clean up options
.PHONY: cleanObj cleanExe clean

cleanObj:
	rm *.o

cleanExe:
	rm *.exe

clean: cleanObj cleanExe
