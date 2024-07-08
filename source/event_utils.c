/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:18:47 by alaaouar          #+#    #+#             */
/*   Updated: 2024/07/08 09:50:47 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	checker(t_map *play)
{
	int		i;
	int		j;

	i = 0;
	while (play->map[i] != NULL)
	{
		j = 0;
		while (play->map[i][j] != '\0')
		{
			if (play->map[i][j] == 'C')
				play->collectibles++;
			if (play->map[i][j] == 'P')
				play->valid.player++;
			if (play->map[i][j] == 'E')
				play->valid.exit++;
			j++;
		}
		i++;
	}
}

void	collectibles_checker(t_map *play, t_data *img)
{
	play->valid.player = 0;
	play->valid.exit = 0;
	checker(play);
	if (play->collectibles == 0)
	{
		ft_putstr_fd("Error Map invalid\nno collectibels\n", 1);
		free_map(play);
	}
	if (play->valid.player != 1 || play->valid.exit != 1)
	{
		ft_putstr_fd("Error\nMap is invalid.\n", 2);
		cleanup(img);
	}
}

int	handle_keyboard(int keycode, t_data *img)
{
	static int	i = 0;

	handle_exit(keycode, img);
	handle_up(keycode, img);
	handle_down(keycode, img);
	handle_left(keycode, img);
	handle_right(keycode, img);
	if (keycode == 119 || keycode == 115 || keycode == 97 || keycode == 100)
		i++;
	ft_putstr_fd("\r Moves: ", 1);
	ft_putnbr_fd(i, 1);
	return (0);
}

void	exit_image_according_to_collec(t_data *img)
{
	if (img->map.collectibles == 0)
		img->exit.exit = img->exit.exit_4;
	else if (img->map.collectibles == 1)
		img->exit.exit = img->exit.exit_3;
	else if (img->map.collectibles == 2)
		img->exit.exit = img->exit.exit_2;
	else if (img->map.collectibles == 3)
		img->exit.exit = img->exit.exit_1;
	else
		img->exit.exit = "image/exit_1.xpm";
}

void	mlx_hunter(t_data *data)
{
	mlx_loop_end(data->mlx);
	mlx_loop_hook(data->mlx, NULL, NULL);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}
