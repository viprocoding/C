# Compiler
CC = gcc

# Compiler flags
CFLAGS = -ansi -pedantic -Wall -Werror -std=c99 -ggdb

# Objects
OBJS = Queue.o Main.o

# Executable name
EXE = main.exe

# Compile project
$(EXE): $(OBJS) *.h
	$(CC) $(CFLAGS) $(OBJS) -o $@ 

# Compile Objects
%.o: %.c *.h
	$(CC) -c $(CFLAGS) $< -o $@

# Clean up options
.PHONY: clean
clean:
	rm -rf *.exe *.o
