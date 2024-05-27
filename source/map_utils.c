/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:10:59 by alaaouar          #+#    #+#             */
/*   Updated: 2024/05/27 03:56:37 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_walls(t_map *play)
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
				&& play->map[i][j] != 'C')
			{
				ft_putstr_fd("Error\nMap is invalid.\n", 2);
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

// int map_check_if_walls_arround(t_map *play)
// {

// }