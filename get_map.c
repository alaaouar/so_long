/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:55:46 by alaaouar          #+#    #+#             */
/*   Updated: 2024/07/01 19:30:31 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	maplinescount(int fd)
{
	char	*buffer;
	int		i;

	i = 0;
	buffer = get_next_line(fd);
	while (buffer != NULL)
	{
		if (i == 0)
			free(buffer);
		buffer = get_next_line(fd);
		free(buffer);
		i++;
	}
	close(fd);
	return (i);
}

void	map_name_check(char **av)
{
	int		i;
	char	*line;

	i = 0;
	line = &av[1][0];
	i = ft_strlen(line);
	if (av[1][i - 1] != 'r' || av[1][i - 2] != 'e' || av[1][i - 3] != 'b'
		|| av[1][i - 4] != '.')
	{
		ft_putstr_fd("invalid type of files only [.ber] files allowed", 1);
		exit(1);
	}
}

char	**fill_map(char **av)
{
	t_map	m;

	m.fd = open(&av[1][0], O_RDONLY);
	if (m.fd < 0)
		return (NULL);
	m.maplines = maplinescount(m.fd);
	m.map = (char **)malloc((m.maplines + 1) * sizeof(char *));
	if (!m.map)
		return (NULL);
	m.fd = open(&av[1][0], O_RDONLY);
	if (m.fd < 0)
		return (NULL);
	m.i = 0;
	while (1)
	{
		m.buffer = get_next_line(m.fd);
		if (m.buffer == NULL)
			break ;
		m.map[m.i] = ft_strdup(m.buffer);
		free(m.buffer);
		m.i++;
	}
	m.map[m.i] = NULL;
	close(m.fd);
	return (m.map);
}

int	ft_line_count(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		i++;
	}
	return (i);
}
