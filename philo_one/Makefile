compile = gcc -Werror -Wall -Wextra
NAME = philo_one
src = *.c
inc = -Iphilo_one.h

all: $(NAME)

$(NAME):
	@$(compile) $(src) $(inc) -o $(NAME)
clean:
	@rm -rf $(NAME)
fclean: clean

re: fclean all

.PHONY: all clean fclean re