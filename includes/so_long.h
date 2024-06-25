/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:08:21 by alaaouar          #+#    #+#             */
/*   Updated: 2024/06/25 17:26:48 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <X11/X.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 50

typedef struct s_exit
{
	char		*exit_1;
	char		*exit_2;
	char		*exit_3;
	char		*exit_4;
	char		*exit;
}			t_exit;

typedef struct s_images
{
	char		*player_left;
	char		*player_right;
	char		*player_up;
	char		*player_down;
	char		*player;
	char		*win_game;
	char		*door;
}				t_images;
typedef struct t_valid
{
	int			player;
	int			exit;
	int			collectibles;
	int			wall;
}				t_valid;

typedef struct s_map
{
	char		*buffer;
	char		**map;
	char		**map_test;
	int			fd;
	int			maplines;
	int			i;
	int			x;
	int			y;
	int			player_x;
	int			player_y;
	int			collectibles;
	int			resolution_x;
	int			resolution_y;
	t_valid		valid;
}				t_map;

typedef struct s_data
{
	void		*img;
	void		*mlx;
	void		*win;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			i;
	int			j;
	t_map		map;
	t_images	images;
	t_valid		valid;
	t_exit		exit;
}				t_data;

int				ft_strlen(char *str);
char			*get_next_line(int fd);
void			*ft_free(char *line);
char			*ft_strdup(char *s1);
int				maplinescount(int fd);
char			**fill_map(void);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			draw_image(t_data *data, char *file_path, int x, int y);
void			ft_putstr_fd(char *s, int fd);
int				mapcheck_return_size(char **map);
void			map_design(t_data img, char **map);
void			player_image(t_data *img);
int				handle_keyboard(int keycode, t_data *img);
int				collectibles_checker(t_map *map);
void			ft_putnbr_fd(int n, int fd);
void			checker(int x, int y);
void			handle_exit(int keycode, t_data *img);
void			handle_up(int keycode, t_data *img);
void			handle_down(int keycode, t_data *img);
void			handle_left(int keycode, t_data *img);
void			handle_right(int keycode, t_data *img);
void			image_size(int i, int j, t_data img);
void			init_data(t_data *img);
void   			exit_image_according_to_collec(t_data *img);
void			exit_declaration(t_data *play);
int				map_walls(t_map *play);
int 			flood_fill(char **map, int x, int y, char target);
int				ft_line_count(char **map);
int				mlx_quit(t_data *data);

#endif