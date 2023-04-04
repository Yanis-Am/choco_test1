##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for bsq
##

SRC	=	$(addprefix src/,	\
		my_getenv.c	\
		my_cd.c	\
		my_setenv.c	\
		get_path.c	\
		my_unsetenv.c	\
		check_var_name.c	\
		send_commands.c	\
		env_list_to_char_array.c	\
		main.c)

LIB = 	$(addprefix lib/my/,    \
		my_putstr.c	\
		my_strlen.c	\
		my_str_to_word_array.c	\
		my_memcpy.c	\
		my_realloc.c	\
		my_strstrip.c	\
		my_strdup.c	\
		my_strcpy.c	\
		my_strncmp.c	\
		my_strcat.c	\
		my_free_2d.c	\
		my_isspace.c	\
		my_strchr.c	\
		my_isalphanum.c	\
		my_strcmp.c	\
		my_fprintf.c	\
		my_strncpy.c	\
		my_putchar.c)

INCLUDE	=	-I ./include/ -L./lib/ -lmy -g3

CFLAGS	+=	$(INCLUDE)

OBJ	+=	$(SRC:.c=.o)

OBJL	=	$(LIB:.c=.o)

NAME	=	mysh

all:	compile
		make clean

lib.a:	$(OBJL)
		ar rc libmy.a $(OBJL)
		mv libmy.a ./lib/

compile:	$(OBJ) lib.a
			gcc -o $(NAME) $(OBJ) $(CFLAGS)

tests_run:

clean:
	rm -f $(OBJ)
	rm -f $(OBJL)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all lib.a compile clean fclean re
