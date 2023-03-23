##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## compiles program
##

CC		=	gcc

SRC		=	main.c					\
			src/error_handling.c	\
			src/transfer.c			\
			src/calc_sequence.c

OBJ		=	$(SRC:.c=.o)

NAME		= 	107transfer

CFLAGS		=	-W -Wall -Wextra -Iinclude -g3

LIB			=	-lm

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
