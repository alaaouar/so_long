/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:41:27 by alaaouar          #+#    #+#             */
/*   Updated: 2024/06/27 19:43:12 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	img->map.map_test = fill_map();
	img->map.x = mapcheck_return_size(img->map.map);
	img->map.y = ft_strlen(img->map.map[0]) - 1;
	img->map.resolution_x = img->map.x * 50;
	img->map.resolution_y = img->map.y * 50;
	img->map.collectibles = 0;
	img->i = 0;
	insert_xpm_to_char(img);
}

void	flood_fill_logic(t_data *img)
{
	int i;

	i = 0;	
	i = flood_fill(img->map.map_test, img->map.player_x, img->map.player_y, 'E');
	if (i == 0)
	{
		ft_putstr_fd("map not valid flood-fill", 1);
		exit(0);
	}
	i = 0;
	while (img->map.map_test[i] != NULL)
		{
			free(img->map.map_test[i]);
			i++;
		}
	free(img->map.map_test);
}

void	mlx_mem_free(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}


void	mlx_everything(t_data *img)
{
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, img->map.resolution_y, img->map.resolution_x, "dark_souls");
	
}


int	main(void)
{
	t_data	img;

	init_data(&img);
	map_walls(&img.map);
	player_location(&img.map);
	flood_fill_logic(&img);
	image_size(img.map.x, img.map.y, img);
	mlx_everything(&img);
	collectibles_checker(&img.map);	
	
	
	exit_image_according_to_collec(&img);


	
	map_design(img, img.map.map);



	
	mlx_key_hook(img.win, handle_keyboard, &img);
	mlx_hook(img.win, DestroyNotify, 0, mlx_quit, &img);
	mlx_loop(img.mlx);
	while (img.map.map[img.i] != NULL)
	{
		free(img.map.map[img.i]);
		img.i++;
	}
	free(img.map.map);
	return (0);
}
