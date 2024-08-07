/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 22:26:39 by alaaouar          #+#    #+#             */
/*   Updated: 2024/07/08 09:47:27 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_up(int keycode, t_data *img)
{
	if (keycode == 119)
	{
		img->images.player = img->images.player_up;
		if (img->map.map[img->map.player_y - 1][img->map.player_x] == '1')
			return ;
		if (img->map.map[img->map.player_y - 1][img->map.player_x] == 'E'
			&& img->map.collectibles == 0)
		{
			ft_putstr_fd("\nYou won\n", 1);
			mlx_hunter(img);
			cleanup(img);
		}
		else if (img->map.map[img->map.player_y - 1][img->map.player_x] == 'E'
			&& img->map.collectibles != 0)
		{
			ft_putstr_fd("\r You need to collect all the collectibles\n", 1);
			return ;
		}
		if (img->map.map[img->map.player_y - 1][img->map.player_x] == 'C')
			img->map.collectibles--;
		img->map.map[img->map.player_y][img->map.player_x] = '0';
		img->map.player_y--;
		img->map.map[img->map.player_y][img->map.player_x] = 'P';
		map_design(*img, img->map.map);
	}
}

void	handle_down(int keycode, t_data *img)
{
	if (keycode == 115)
	{
		img->images.player = img->images.player_down;
		if (img->map.map[img->map.player_y + 1][img->map.player_x] == '1')
			return ;
		if (img->map.map[img->map.player_y + 1][img->map.player_x] == 'E'
			&& img->map.collectibles == 0)
		{
			ft_putstr_fd("\nYou won\n", 1);
			mlx_hunter(img);
			cleanup(img);
		}
		else if (img->map.map[img->map.player_y + 1][img->map.player_x] == 'E'
			&& img->map.collectibles != 0)
		{
			ft_putstr_fd("\r You need to collect all the collectibles\n", 1);
			return ;
		}
		if (img->map.map[img->map.player_y + 1][img->map.player_x] == 'C')
			img->map.collectibles--;
		img->map.map[img->map.player_y][img->map.player_x] = '0';
		img->map.player_y++;
		img->map.map[img->map.player_y][img->map.player_x] = 'P';
		map_design(*img, img->map.map);
	}
}

void	handle_left(int keycode, t_data *img)
{
	if (keycode == 97)
	{
		img->images.player = img->images.player_left;
		if (img->map.map[img->map.player_y][img->map.player_x - 1] == '1')
			return ;
		if (img->map.map[img->map.player_y][img->map.player_x - 1] == 'E'
			&& img->map.collectibles == 0)
		{
			ft_putstr_fd("\nYou won\n", 1);
			mlx_hunter(img);
			cleanup(img);
		}
		else if (img->map.map[img->map.player_y][img->map.player_x - 1] == 'E'
			&& img->map.collectibles != 0)
		{
			ft_putstr_fd("\r You need to collect all the collectibles\n", 1);
			return ;
		}
		if (img->map.map[img->map.player_y][img->map.player_x - 1] == 'C')
			img->map.collectibles--;
		img->map.map[img->map.player_y][img->map.player_x] = '0';
		img->map.player_x--;
		img->map.map[img->map.player_y][img->map.player_x] = 'P';
		map_design(*img, img->map.map);
	}
}

void	handle_right(int keycode, t_data *img)
{
	if (keycode == 100)
	{
		img->images.player = img->images.player_right;
		if (img->map.map[img->map.player_y][img->map.player_x + 1] == '1')
			return ;
		if (img->map.map[img->map.player_y][img->map.player_x + 1] == 'E'
			&& img->map.collectibles == 0)
		{
			ft_putstr_fd("\nYou won\n", 1);
			mlx_hunter(img);
			cleanup(img);
		}
		else if (img->map.map[img->map.player_y][img->map.player_x + 1] == 'E'
			&& img->map.collectibles != 0)
		{
			ft_putstr_fd("\r You need to collect all the collectibles", 1);
			return ;
		}
		if (img->map.map[img->map.player_y][img->map.player_x + 1] == 'C')
			img->map.collectibles--;
		img->map.map[img->map.player_y][img->map.player_x] = '0';
		img->map.player_x++;
		img->map.map[img->map.player_y][img->map.player_x] = 'P';
		map_design(*img, img->map.map);
	}
}

int	flood_fill(char **map, int x, int y, char target)
{
	if (x < 0 || x >= ft_line_count(map) || y < 0 || y >= (int)strlen(map[0])
		|| map[x][y] == '1' || map[x][y] == '*')
		return (0);
	if (map[x][y] == target)
		return (1);
	map[x][y] = '*';
	return (flood_fill(map, x + 1, y, target) || flood_fill(map, x - 1, y,
			target) || flood_fill(map, x, y + 1, target) || flood_fill(map, x, y
			- 1, target));
}
