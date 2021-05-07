compile = gcc -Werror -Wall -Wextra
NAME = philo_three
src = *.c
inc = -Iphilo_three.h

all: $(NAME)

$(NAME):
	@$(compile) $(src) $(inc) -o $(NAME)
clean:
	@rm -rf $(NAME)
fclean: clean

re: fclean all

.PHONY: all clean fclean re