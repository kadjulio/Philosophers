##
## EPITECH PROJECT, 2018
## makefile
## File description:
## malloc
##

CC	=	gcc

CFLAGS	=	-W -Wextra -Wall  -I./include -g3 -L./ -lriceferee -lpthread

RM	=	rm -f

NAME	=	philo

SRC	=	src/philo.c		\
		src/arg.c		\
		src/philo_states.c	\
		src/init_philo.c

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY : all clean fclean re
