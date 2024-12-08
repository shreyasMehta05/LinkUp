# Makefile for a C project with multiple source files on Windows

# Compiler and flags
CC = gcc
CFLAGS = -Wall -std=c11

# Source files and object files
SRCDIR = code
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))

# Target executable
TARGET = myprogram.exe

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to build object files from source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove object files and the executable
clean:
	del /Q $(OBJS) $(TARGET)
