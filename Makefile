NAME = cub3D

LIBFT = ./libft/libft.a
LIBGNL = ./get_next_line/libgnl.a
MLX_DIR = ./mlx


SRCS =	./src/cub3d.c \
		./src/utils.c \
		./src/parse_and_valid_map/parsing_file_to_map.c \
		./src/parse_and_valid_map/copy_from_file_attributes.c \
		./src/parse_and_valid_map/copy_from_file_map.c \
		./src/parse_and_valid_map/check_map.c \
		./src/parse_and_valid_map/check_wall_map.c \
		./src/parse_and_valid_map/save_direction_player.c \
		./src/create_scene/init_window_with_map.c \
		./src/create_scene/draw_scene.c \
		./src/raycasting/ray_casting.c \
		./src/raycasting/utils_for_raycasting.c \
		./src/hook/hook_param.c \
		./src/hook/move_player.c \
		./src/hook/rotation_player.c

HEADER = ./include/cub3d.h

OBJS = $(SRCS:.c=.o)

CFLAGS = -Werror -Wextra -Wall #-fsanitize=address -g
FLAGS_FOR_MLX = -lmlx -framework OpenGL -framework AppKit -L$(MLX_DIR)

MLX		=	$(MLX_DIR)libmlx.a
MLX_DIR =	./mlx/
MLX_HEADERS = $(MLX_DIR)

all: $(NAME) $(LIBFT) $(LIBGNL)

CC = cc

%.o : %.c 
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME) : $(OBJS) $(LIBFT) $(LIBGNL) $(MLX)
	$(CC) -I $(HEADER) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBGNL) $(FLAGS_FOR_MLX) -o $(NAME)

$(MLX):
	$(MAKE) -sC $(MLX_DIR)

$(LIBFT) : 
	@make -C ./libft


$(LIBGNL) : 
	@make -C ./get_next_line

clean:
	@make clean -C ./libft
	@make clean -C ./get_next_line
	$(MAKE) -sC $(MLX_DIR) clean
	rm -rf $(OBJS)

fclean:
	rm -f $(MLX)
	@make fclean -C ./libft
	@make fclean -C ./get_next_line
	rm -rf $(OBJS) $(NAME)

re: fclean all

.PHONY:	all clean fclean re bonus
