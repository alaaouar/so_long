/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:41:27 by alaaouar          #+#    #+#             */
/*   Updated: 2024/05/27 07:02:12 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	player_location(t_map *play)
{
	int	i;
	int	j;

	i = 0;
	while (play->map[i] != NULL)
	{
		j = 0;
		while (play->map[i][j] != '\0')
		{
			if (play->map[i][j] == 'P')
			{
				play->player_x = j;
				play->player_y = i;
			}
			j++;
		}
		i++;
	}
	return (0);
}
void	image_size(int i, int j, t_data img)
{
	if (i > 1440 || j > 2560)
	{
		ft_putstr_fd("Error\nMap is too big\n", 2);
		while (img.map.map[img.i] != NULL)
		{
			free(img.map.map[img.i]);
			img.i++;
		}
		free(img.map.map);
		exit(0);
	}
}

void	init_data(t_data *img)
{
	img->map.map = fill_map();
	img->map.x = mapcheck_return_size(img->map.map);
	img->map.y = ft_strlen(img->map.map[0]) - 1;
	img->map.resolution_x = img->map.x * 50;
	img->map.resolution_y = img->map.y * 50;
	img->map.collectibles = 0;
	img->i = 0;
}

int	main(void)
{
	t_data	img;

	init_data(&img);
	map_walls(&img.map);
	image_size(img.map.x, img.map.y, img);
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, img.map.resolution_y, img.map.resolution_x, "dark_souls");
	player_location(&img.map);
	player_image(&img);
	img.images.player = img.images.player_down;
	img.map.collectibles = collectibles_checker(&img.map);
	exit_declaration(&img);
	exit_image_according_to_collec(&img);
	map_design(img, img.map.map);
	mlx_key_hook(img.win, handle_keyboard, &img);
	mlx_loop(img.mlx);
	while (img.map.map[img.i] != NULL)
	{
		free(img.map.map[img.i]);
		img.i++;
	}
	free(img.map.map);
	return (0);
}
