CC = gcc
SRC = source/get_next_line.c source/utils.c main.c get_map.c source/mlx_utils.c event.c source/event_utils.c source/map_utils.c 
NAME = so_long
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
MLX = -lmlx -framework OpenGL -framework AppKit

all:
	$(CC) $(CFLAGS) $(SRC) $(MLX) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all