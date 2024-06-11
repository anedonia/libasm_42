NAME = libasm

NAME_LIB = libasm.a

SRCS = 	ft_write.s \
		ft_read.s \
		ft_strcmp.s \
		ft_strcpy.s \
		ft_strdup.s \
		ft_strlen.s \

CC = gcc 

CFLAGS = -Wall -Wextra -Werror 

NASM = nasm

NASMFLAGS = -f elf64 

OBJ = $(SRCS:.s=.o)

%.o : %.s
	$(NASM) $(NASMFLAGS) $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME_LIB) $(OBJ)

test : $(NAME)
	gcc $(CFLAGS) -L. -lasm -o test main.c $(NAME_LIB)
	./test
	
clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME_LIB)
	rm -f ./a.out
	rm -f test

re : fclean all
