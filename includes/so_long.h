/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:08:21 by alaaouar          #+#    #+#             */
/*   Updated: 2024/05/24 23:10:16 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>
#include <fcntl.h>
# define BUFFER_SIZE 50

typedef struct s_map
{
    char	*buffer;
    char	**map;
    int		fd;
    int		maplines;
    int		i;
	int		x;
	int		y;
	int		player_x;
	int		player_y;
}              t_map;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		i;
	void	*mlx;
	void	*win;
	int		j;
	t_map	map;
}				t_data;

int		ft_strlen(char *str);
char	*get_next_line(int fd);
void	*ft_free(char *line);
char	*ft_strdup(char *s1);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
int		maplinescount(int fd);
char	**fill_map(void);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_image(t_data *data, char *file_path, int x, int y);
void	ft_putstr_fd(char *s, int fd);
int		mapcheck_return_size(char **map);
void	map_design(t_data img, char **map);



# endif