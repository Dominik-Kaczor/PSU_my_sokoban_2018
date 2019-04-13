##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## gcc unit tests
##

SRC	=	unit_tests.c	\
		test_main.c	\
		../movment_sokoban.c	\
		../position_sokoban.c	\
		../tools_sokoban.c	\
		../my_putstr.c	\
		../my_putchar.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	test

all:   $(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC) -lncurses -lcriterion --coverage
		./test
clean:
	rm -f $(OBJ)
	rm *.gcda
	rm *.gcno

fclean: clean
	rm -f $(NAME)

re:	fclean all
