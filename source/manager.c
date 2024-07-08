/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:21:06 by alaaouar          #+#    #+#             */
/*   Updated: 2024/07/08 09:49:34 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	insert_xpm_to_char(t_data *img)
{
	img->images.player_left = "image/player_left.xpm";
	img->images.player_right = "image/player_right.xpm";
	img->images.player_up = "image/player_up.xpm";
	img->images.player_down = "image/player_down.xpm";
	img->images.player = img->images.player_down;
	img->exit.exit_1 = "image/exit_1.xpm";
	img->exit.exit_2 = "image/exit_2.xpm";
	img->exit.exit_3 = "image/exit_3.xpm";
	img->exit.exit_4 = "image/exit_4.xpm";
}

void	handle_exit(int keycode, t_data *img)
{
	if (keycode == 65307)
	{
		ft_putstr_fd("\n exiting... \n", 1);
		mlx_hunter(img);
		cleanup(img);
	}
}

int	mlx_quit(t_data *data)
{
	mlx_hunter(data);
	ft_putstr_fd("\n exiting... \n", 1);
	cleanup(data);
	return (0);
}

void	cleanup(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.map[i] != NULL)
	{
		free(data->map.map[i]);
		i++;
	}
	free(data->map.map);
	exit(0);
}

void	free_map(t_map *play)
{
	int	i;

	i = 0;
	while (play->map[i] != NULL)
	{
		free(play->map[i]);
		i++;
	}
	free(play->map);
	exit(0);
}
