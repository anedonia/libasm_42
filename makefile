# Makefile for a basic assembly project

# Define the assembler and linker
ASM = nasm
LD = ld

# Define the assembler and linker flags
ASM_FLAGS = -f elf64
LD_FLAGS = -m elf_x86_64

# Define the source and target files
SRC = test.asm
OBJ = test.o
TARGET = main

# Default target to build the executable
all: $(TARGET)

# Rule to assemble the source file
$(OBJ): $(SRC)
	$(ASM) $(ASM_FLAGS) -o $(OBJ) $(SRC)

# Rule to link the object file and create the executable
$(TARGET): $(OBJ)
	$(LD) $(LD_FLAGS) -o $(TARGET) $(OBJ)

# Rule to clean the build artifacts
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets
.PHONY: all clean
