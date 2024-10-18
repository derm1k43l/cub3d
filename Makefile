# COMPILER
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast -g
NAME = cub3D

# LIBRARY NAME
LIBFT_DIR = libft
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)
PARSE_DIR = parsing
EXEC_DIR = execution

# MLX LIBRARY
MLX_HEADER = MLX42/include/MLX42
MLX_LIB = MLX42/build


# LIST OF SOURCE FILES
EXEC_DIR = execution
EXEC_SRCS = $(EXEC_DIR)/execution.c  $(EXEC_DIR)/moves.c  $(EXEC_DIR)/raycasting.c  $(EXEC_DIR)/rendering.c \
	 $(EXEC_DIR)/free.c  $(EXEC_DIR)/utils.c $(EXEC_DIR)/main.c

PARSE_DIR = parsing
PARSE_SRCS =  $(PARSE_DIR)/check_map.c  $(PARSE_DIR)/debug.c  $(PARSE_DIR)/parse_txt_col.c  $(PARSE_DIR)/init.c \
	 $(PARSE_DIR)/parse_map.c  $(PARSE_DIR)/parse_utils.c  $(PARSE_DIR)/utils.c \


EXEC_OBJS = $(EXEC_SRCS:.c=.o)
PARSE_OBJS = $(PARSE_SRCS:.c=.o)

# COLORS
GREEN = \033[0;32m
NC = \033[0m

# ALL RULE
# RULES TO MAKE EXECUTABLE AND LIBFT AND MLX
all: $(NAME) $(LIBFT) $(EXEC_OBJS) $(PARSE_OBJS)
	@echo "$(GREEN)cub3D build successful$(NC)"

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(EXEC_DIR)/%.o: $(EXEC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PARSE_DIR)/%.o: $(PARSE_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(EXEC_OBJS) $(PARSE_OBJS)
	$(CC) $(CFLAGS)  $(EXEC_OBJS) $(PARSE_OBJS) $(LIBFT) -I $(MLX_HEADER) -L $(MLX_LIB) -lmlx42 -lglfw -pthread -lm -o $(NAME)

# RULES FOR CREATING OBJECT FILES
%.o: %.c
	@$(CC) $(FLAGS) -I. $(MLX_INC) -c $< -o $@

# LIBFT RULES

mlx:
	git clone https://github.com/ashirzad313/MLX42.git MLX42

clean_mlx :
	rm -rf MLX42
# CLEAN RULES
clean:
	@make -C $(LIBFT_DIR)
	rm -f $(EXEC_OBJS)
	rm -f $(PARSE_OBJS)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(GREEN)cub3D fcleaned$(NC)"

re: fclean all

.PHONY: all clean mlx fclean re
