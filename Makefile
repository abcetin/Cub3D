NAME = cub3D
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = $(shell find ./checker_map ./utils ./events ./ray ./mini_map ./main ./get_next_line -name "*.c")
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C mlx
	@make -C libft
	@$(CC) $(FLAGS) $(OBJ) libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@rm -rf $(OBJ)
	@make clean -C libft
	@make clean -C mlx

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean all

norminette : 
	@norminette $(SRC) libft/*.c

.PHONY: all clean fclean re linux