NAME = push_swap

FILEPUS = push_swap.c ft_*.c libft/libftprintf.a

FILECHE = checker.c ft_*.c libft/libftprintf.a

LIB = push_swap.h

FLAG = -Wall -Wextra -Werror

all: compillib $(NAME)

$(NAME): $(FILEPUS)
	gcc $(FLAG) $(FILEPUS) -o $(NAME)

compillib:
	make -C libft

checker: compillib
	gcc  $(FILECHE) -o checker

clean:
	rm -rf
	make clean -C libft

fclean: clean
	rm -rf $(NAME) checker
	make fclean -C libft

re: fclean all 
