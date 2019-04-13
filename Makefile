##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## my_popup
##

SRC	=	sokoban.c	\
		my_putchar.c	\
		my_putstr.c	\
		tools_sokoban.c	\
		position_sokoban.c	\
		movment_sokoban.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC) -lncurses

test:
	make -C	tests/
	make fclean -C tests/

clean:
		rm  -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
