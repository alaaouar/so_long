/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:41:27 by alaaouar          #+#    #+#             */
/*   Updated: 2024/07/06 15:48:37 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_location(t_map *play)
{
	int	i;
	int	j;

	if (!play || !play->map)
		return (-1);

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
				return 0;
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

void	init_data(t_data *img, char **av, int ac)
{
	if (ac != 2)
	{
		ft_putstr_fd("invalid param", 1);
		exit(0);
	}
	map_name_check(av);
	img->map.map = fill_map(av);
	if (img->map.map == NULL)
	{
		ft_putstr_fd("invalid param", 1);
		exit(0);
	}
	img->map.map_test = fill_map(av);
	img->map.x = mapcheck_return_size(img->map.map, img);
	img->map.y = ft_strlen(img->map.map[0]) - 1;
	img->map.resolution_x = img->map.x * 50;
	img->map.resolution_y = img->map.y * 50;
	img->map.collectibles = 0;
	img->i = 0;
	insert_xpm_to_char(img);
}

void	flood_fill_logic(t_data *img)
{
	int	i;

	i = 0;
	i = flood_fill(img->map.map_test, img->map.player_x, img->map.player_y,
			'E');
	if (i == 0)
	{
		ft_putstr_fd("map not valid flood-fill", 1);
		free_split(*img);
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

int	main(int ac, char **av)
{
	t_data	img;

	init_data(&img, av, ac);
	map_walls(&img.map , &img);
	player_location(&img.map);
	flood_fill_logic(&img);
	image_size(img.map.x, img.map.y, img);
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, img.map.resolution_y,
			img.map.resolution_x, "dark_souls");
	collectibles_checker(&img.map, &img);
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
