# COMPILER
CC = cc
FLAGS = -fsanitize=address -g
NAME = cub3D

# LIBRARY NAME
LIBFT = libft.a
LIBFT_DIR = libft

# MLX LIBRARY
MLX_DIR = mlx42
MLX_FLAGS = ./MLX42/build/libmlx42.a -Iinclude -lglfw -framework Cocoa -framework OpenGL -framework IOKit
MLX_INC = -I$(MLX_DIR)

# LIST OF SOURCE FILES
SRCS = main.c utils.c init.c parse_txt_col.c parse_utils.c parse_map.c \
	execution.c check_map.c moves.c raycasting.c rendering.c draw.c

OBJS = $(SRCS:.c=.o)

# COLORS
GREEN = \033[0;32m
NC = \033[0m

# ALL RULE
# RULES TO MAKE EXECUTABLE AND LIBFT AND MLX
all: $(LIBFT) $(MLX_DIR)/build/libmlx42.a $(NAME)
	@echo "$(GREEN)cub3D build successful$(NC)"

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -I. $(MLX_INC) $(OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME)

# RULES FOR CREATING OBJECT FILES
%.o: %.c
	@$(CC) $(FLAGS) -I. $(MLX_INC) -c $< -o $@

# LIBFT RULES
$(LIBFT):
	@make -C $(LIBFT_DIR)

# MLX TARGET
mlx:
		git clone https://github.com/ashirzad313/MLX42.git mlx42

# CLEAN RULES
clean:
	@rm -rf *.o
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	# @rm -rf $(MLX_DIR)
	@echo "$(GREEN)FdF fcleaned$(NC)"

re: fclean all

ree:
	@rm -rf $(OBJ_DIR) $(NAME)
	@echo "$(GREEN)withoutmake mlx $(NC)"

.PHONY: all clean fclean re
