CC		= cc
SRC		= source/get_next_line.c source/lib_utils.c main.c get_map.c source/mlx_utils.c event.c source/event_utils.c source/map_utils.c source/manager.c
NAME	= so_long
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address -g3
CLIBS	= -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz
OBJ		= $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(CLIBS) -o $(NAME) 

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.SECONDARY: $(OBJ)
.PHONY: all clean fclean re