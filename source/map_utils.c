/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:10:59 by alaaouar          #+#    #+#             */
/*   Updated: 2024/07/06 16:07:57 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_last(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 1)
		return (1);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i - 1] == '1')
		return (1);
	return (0);
}

void	map_check_if_walls_arround(t_map *play ,t_data *img)
{
	int	i;

	i = 0;
	while (play->map[i] != NULL)
	{
		if (play->map[i][0] != '1' || !check_last(play->map[i]))
		{
			ft_putstr_fd("Error\nMap is invalid right or left.\n", 2);
			cleanup(img);
		}
		i++;
	}
	i = 0;
	while (play->map[i])
		i++;
	while (play->map[0][i])
	{
		if ((play->map[0][i] != '1' || play->map[play->x - 1][i] != '1')
			&& i < play->y)
		{
			ft_putstr_fd("Error\nMap is invalid top or down.\n", 2);
			cleanup(img);
		}
		i++;
	}
}

int	map_walls(t_map *play, t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (play->map[i] != NULL)
	{
		j = 0;
		while (play->map[i][j] != '\0')
		{
			if (play->map[i][j] != '1' && play->map[i][j] != '0'
				&& play->map[i][j] != 'P' && play->map[i][j] != 'E'
				&& play->map[i][j] != 'C' && play->map[i][j] != '\n')
			{
				ft_putstr_fd("Error\nMap is invalid.\n", 2);
				cleanup(img);
			}
			j++;
		}
		i++;
	}
	map_check_if_walls_arround(play , img);
	return (0);
}
