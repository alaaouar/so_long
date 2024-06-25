CC = cc
SRC = source/get_next_line.c source/utils.c main.c get_map.c source/mlx_utils.c event.c source/event_utils.c source/map_utils.c 
NAME = so_long
CFLAGS = -Wall -Wextra -Werror -g3 
OBJ = $(SRC:.c=.o)


all:$(NAME)


%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@


$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)



clean:
	rm -rf $(NAME)
	rm -rf $(OBJ)

fclean: clean

re: fclean all
