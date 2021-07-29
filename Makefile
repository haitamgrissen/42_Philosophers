NAME = philo

SRC =	main.c \
		src/display.c \
		src/parser.c \
		src/routines \
		src/utils

CC = gcc -Wall -Wextra -Werror -I inc

all :  $(NAME) 

$(NAME) : 
		@$(CC) main.c display.c parser.c routines.c utils.c -o $(NAME)

clean :
		@rm $(NAME)

re : clean all
