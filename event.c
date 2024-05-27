/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 22:26:39 by alaaouar          #+#    #+#             */
/*   Updated: 2024/05/26 19:53:44 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	handle_exit(int keycode, t_data *img)
{
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->win);
		exit(0);
	}
}

void	handle_up(int keycode, t_data *img)
{
	if (keycode == 13)
	{
		img->images.player = img->images.player_up;
		if (img->map.map[img->map.player_y - 1][img->map.player_x] == '1')
			return ;
		if (img->map.map[img->map.player_y - 1][img->map.player_x] == 'E'
			&& img->map.collectibles == 0)
		{
			ft_putstr_fd("You won\n", 1);
			mlx_destroy_window(img->mlx, img->win);
			exit(0);
		}
		else if (img->map.map[img->map.player_y - 1][img->map.player_x] == 'E'
				&& img->map.collectibles != 0)
		{
			ft_putstr_fd("You need to collect all the collectibles\n", 1);
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
	if (keycode == 1)
	{
		img->images.player = img->images.player_down;
		if (img->map.map[img->map.player_y + 1][img->map.player_x] == '1')
			return ;
		if (img->map.map[img->map.player_y + 1][img->map.player_x] == 'E'
			&& img->map.collectibles == 0)
		{
			ft_putstr_fd("You won\n", 1);
			mlx_destroy_window(img->mlx, img->win);
			exit(0);
		}
		else if (img->map.map[img->map.player_y + 1][img->map.player_x] == 'E'
				&& img->map.collectibles != 0)
		{
			ft_putstr_fd("You need to collect all the collectibles\n", 1);
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
	if (keycode == 0)
	{
		img->images.player = img->images.player_left;
		if (img->map.map[img->map.player_y][img->map.player_x - 1] == '1')
			return ;
		if (img->map.map[img->map.player_y][img->map.player_x - 1] == 'E'
			&& img->map.collectibles == 0)
		{
			ft_putstr_fd("You won\n", 1);
			mlx_destroy_window(img->mlx, img->win);
			exit(0);
		}
		else if (img->map.map[img->map.player_y][img->map.player_x - 1] == 'E'
				&& img->map.collectibles != 0)
		{
			ft_putstr_fd("You need to collect all the collectibles\n", 1);
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
	if (keycode == 2)
	{
		img->images.player = img->images.player_right;
		if (img->map.map[img->map.player_y][img->map.player_x + 1] == '1')
			return ;
		if (img->map.map[img->map.player_y][img->map.player_x + 1] == 'E'
			&& img->map.collectibles == 0)
		{
			ft_putstr_fd("You won\n", 1);
			mlx_destroy_window(img->mlx, img->win);
			exit(0);
		}
		else if (img->map.map[img->map.player_y][img->map.player_x + 1] == 'E'
				&& img->map.collectibles != 0)
		{
			ft_putstr_fd("You need to collect all the collectibles\n", 1);
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

void	flood_fill_map(int x, int y, char **map, int size)
{
	if (x < 0 || y < 0 || x >= size || y >= size || map[y][x] != '0')
		return ;
	
	map[y][x] = '1';
	flood_fill_map(x + 1, y, map, size);
	flood_fill_map(x - 1, y, map, size);
	flood_fill_map(x, y + 1, map, size);
	flood_fill_map(x, y - 1, map, size);
}
