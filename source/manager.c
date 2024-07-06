/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:21:06 by alaaouar          #+#    #+#             */
/*   Updated: 2024/07/06 16:03:40 by alaaouar         ###   ########.fr       */
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
		cleanup(img);
		exit(0);
	}
}

int	mlx_quit(t_data *data)
{
	mlx_loop_end(data->mlx);
	mlx_loop_hook(data->mlx, NULL, NULL);
	ft_putstr_fd("\n exiting... \n",1);
	cleanup(data);
	return (0);
}

void	free_split(t_data img)
{
	while (img.map.map[img.i] != NULL)
	{
		free(img.map.map[img.i]);
		img.i++;
	}
	free(img.map.map);
}

void cleanup(t_data *data)
{
	if (data != NULL)
	{
        free_split(*data);
        if (data->win != NULL)
            mlx_destroy_window(data->mlx, data->win);
        if (data->mlx != NULL)
		{
            mlx_destroy_display(data->mlx);
            free(data->mlx);
        }
        free(data);
    }
	exit(0);
}
