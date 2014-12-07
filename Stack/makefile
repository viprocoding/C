# Compiler: The GNU Compiler Collection
CC = gcc

# Compiler flags
#	Wall	- (Almost) all warnings on
#	Werror	- Don't allow compiling if there are any warnings
#	ansi	- Follow ansi standard
#	std=c11 - Follow c11 standard
#   ggdb    - Add extra information for debugging (GDB)
CFLAGS = -Wall -Werror -ansi -std=c11 -ggdb

# Object files
OBJS = stack.o stackTest.o

# Executable name
EXE = stackTest.exe

# Build program
$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Compile all src files to object files
%.o : %.c %.h
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f *.o *.exe	
