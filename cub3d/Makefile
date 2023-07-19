NAME = cub3D


LIBFT = ./libft/libft.a
LIBGNL = ./get_next_line/libgnl.a

SRCS =	./src/cub3d.c \
		./src/utils.c \
		./src/parsing_file_to_map.c


HEADER = ./include/cub3d.h

OBJS = $(SRCS:.c=.o)

CFLAGS = -Werror -Wextra -Wall #-fsanitize=address -g
FLAGS_FOR_MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME) $(LIBFT) $(LIBGNL)

CC = cc

%.o : %.c 
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME) : $(OBJS) $(LIBFT) $(LIBGNL)
	$(CC) -I $(HEADER) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBGNL) $(FLAGS_FOR_MLX) -o $(NAME)


$(LIBFT) : 
	@make -C ./libft


$(LIBGNL) : 
	@make -C ./get_next_line

clean:
	@make clean -C ./libft
	@make clean -C ./get_next_line
	rm -rf $(OBJS)

fclean:
	@make fclean -C ./libft
	@make fclean -C ./get_next_line
	rm -rf $(OBJS) $(NAME)

re: fclean all

.PHONY:	all clean fclean re bonus