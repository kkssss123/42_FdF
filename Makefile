INC_DIR 	:= ./include
SRC_DIR 	:= ./src

CC 			:= cc
CFLAGS 		+= -Wall -Wextra -Werror
CFLAGS		+= -I$(INC_DIR)
CFLAGS		+= $(DBG)	# make DBG="-g -DDEBUG"
FDF_FLAGS	:= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

LIBFT_DIR 	:= ./libft
LIBFT 		:= $(LIBFT_DIR)/libft.a

MLX_DIR		:= ./minilibx
MLX			:= $(MLX_DIR)/libmlx_Linux.a

NAME 		:= fdf
SRC			:= main destroy draw_util draw error event_handler \
	event1 event2 init_map_util init_map init parse_line project \
	rotate scale transform translate
OBJ			:= $(addprefix $(SRC_DIR)/, $(addsuffix .o, $(SRC)))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@$(CC) $(FDF_FLAGS) $^ -o $@

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(MLX):
	@make -s -C $(MLX_DIR) > null
	@rm -f null

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(MLX_DIR)/%.o: $(MLX_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -s -C $(LIBFT_DIR) clean
	@rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	@make -s -C $(LIBFT_DIR) fclean
	@make -s -C $(MLX_DIR) clean > null
	@rm -f null
	@rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re