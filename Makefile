# Define the C++ compiler
CC=g++

# Define compiler flags
# -std=c++17: For modern C++ features
# -pthread: For future thread use
# -Wall: Enable all warnings
# -g: Add debug symbols
CFLAGS=-std=c++17 -pthread -Wall -g

# This is the default target
all: shell

# Rule to build the shell executable
shell: shell.cpp
	$(CC) $(CFLAGS) -o shell shell.cpp

# Rule to clean up build files
clean:
	rm -f shell *.o
