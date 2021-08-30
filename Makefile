NAME = philo

SRC =	main.c \
		src/display.c \
		src/parser.c \
		src/routines \
		src/utils \
		src/inits.c

CC = gcc -Wall -fsanitize=thread -Wextra -Werror -I inc

all :  $(NAME) 

$(NAME) : 
		@$(CC) *.c -o $(NAME)

clean :
		@rm $(NAME)

re : clean all
