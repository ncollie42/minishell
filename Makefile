NAME = minishell 
TESTING = a.out
EXTRA = a.out.dSYM ft_ls.dSYM
FILES = main.c run.c parce.c real_function.c get_path.c stream.c built_in.c free.c struct_stuff.c eddit_parce.c built_in_helper.c prompt.c read_line.c parse_two.c
OBJECTS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): lib
	gcc -Wall -Werror -Wextra -I libft/includes -L libft/ $(FILES) -lft -o $(NAME)
g:
	gcc -Wall -Werror -Wextra -I libft/includes -L libft/ $(FILES) -g -lft -o $(NAME)
gg:
	gcc -Wall -Werror -Wextra -I libft/includes -L libft/ $(FILES) -g -fsanitize=address -lft -o $(NAME)
val: g
	valgrind --leak-check=full -v ./minishell
clean:
	rm -f $(NAME)
	rm -f $(TESTING)
	rm -fr $(EXTRA)
fclean: clean
	make -C libft/ fclean
re: fclean all
lib:
	make -C libft/ 
