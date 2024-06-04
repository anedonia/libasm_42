# Name of the library
NAME = libasm.a

# Compiler and assembler
CC = gcc
NASM = nasm

# Compilation flags
CFLAGS = -Wall -Wextra -Werror
NASMFLAGS = -f elf64

# Source files
ASM_SRCS = ft_strlen.asm ft_strcpy.asm ft_strcmp.asm ft_write.asm ft_read.asm ft_strdup.asm
C_SRCS = main.c

# Object files
ASM_OBJS = $(ASM_SRCS:.asm=.o)
C_OBJS = $(C_SRCS:.c=.o)

# Rule to build the library
$(NAME): $(ASM_OBJS)
	ar rcs $(NAME) $(ASM_OBJS)

# Rule to assemble .asm files to .o files
%.o: %.asm
	$(NASM) $(NASMFLAGS) $< -o $@

# Rule to compile C files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to build the executable using the library
my_program: $(C_OBJS) $(NAME)
	$(CC) $(CFLAGS) $(C_OBJS) -L. -lasm -o my_program

# Rule to clean object files
clean:
	rm -f $(ASM_OBJS) $(C_OBJS)

# Rule to clean everything
fclean: clean
	rm -f $(NAME) my_program

# Rule to rebuild everything
re: fclean all

# Rule to build everything
all: $(NAME) my_program

# Rule to add bonuses
bonus:
	@echo "Add bonus compilation rules here if necessary"

.PHONY: all clean fclean re bonus
