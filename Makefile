# COMPILER
CC = cc
FLAGS = -Wall -Wextra -Werror -Ofast -Wunreachable-code -g #-fsanitize=address

SRC_DIR = srcs
INC_DIR = inc
OBJ_DIR = obj

NAME = cub3d

# LIBRARY NAME
LIBFT = libft.a
LIBFT_DIR = libft

# MLX LIBRARY
MLX_DIR = mlx42
MLX_FLAGS = ./MLX42/build/libmlx42.a -Iinclude -lglfw -framework Cocoa -framework OpenGL -framework IOKit
MLX_INC = -I$(MLX_DIR)

# LIST OF SOURCE FILES
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/utils.c $(SRC_DIR)/init.c $(SRC_DIR)/parse.c
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# COLORS
GREEN = \033[0;32m
NC = \033[0m

# ALL RULE
# RULES TO MAKE EXECUTABLE AND LIBFT AND MLX
all: mlx $(LIBFT) $(NAME)
	@echo "$(GREEN)cub3d build successful$(NC)"

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -I$(INC_DIR) $(MLX_INC) $(OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME)

# RULES FOR CREATING OBJECT FILES
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -I$(INC_DIR) $(MLX_INC) -c $< -o $@

# LIBFT RULES
$(LIBFT):
	@make -C $(LIBFT_DIR)

# MLX TARGET
mlx:
	@if [ ! -d "$(MLX_DIR)" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git $(MLX_DIR); \
	else \
		echo "Directory $(MLX_DIR) already exists."; \
	fi
	@cd $(MLX_DIR) && cmake -B build && cmake --build build -j4

# CLEAN RULES
clean:
	@rm -rf $(OBJ_DIR) $(MLX_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "$(GREEN)FdF cleaned & MLX42$(NC)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)FdF fcleaned$(NC)"

re: fclean all

ree: 
	@rm -rf $(OBJ_DIR) $(NAME)
	@echo "$(GREEN)FdF ree/ just obj from cub3d wihtou mlf for speeed tests $(NC)"

.PHONY: all clean fclean re