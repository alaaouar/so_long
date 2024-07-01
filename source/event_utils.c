/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:18:47 by alaaouar          #+#    #+#             */
/*   Updated: 2024/06/27 19:43:22 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	checker(int x, int y)
{
	if (x != 1 || y != 1)
	{
		ft_putstr_fd("Error\nMap is invalid.\n", 2);
		exit(1);
	}
}

void	collectibles_checker(t_map *play)
{
	int	i;
	int	j;

	i = 0;
	play->valid.player = 0;
	play->valid.exit = 0;
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
	checker(play->valid.player, play->valid.exit);
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
