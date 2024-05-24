/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:55:46 by alaaouar          #+#    #+#             */
/*   Updated: 2024/05/24 22:52:39 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int maplinescount(int fd)
{
    char	*buffer;
    int		i;
    t_map m;

    i = 0;
    while ((buffer = get_next_line(fd)) != NULL)
    {
        free(buffer);
        i++;
    }
    m.y = 0;
    m.y = i;
    return (i);
}

char	**fill_map(void)
{
    t_map m;

    m.fd = open("maps/map.ber", O_RDONLY);
    if (m.fd < 0)
        return (NULL);
    m.maplines = maplinescount(m.fd);
    close(m.fd);
    m.map = (char **)malloc((m.maplines + 1) * sizeof(char *));
    if (!m.map)
        return (NULL);
    m.fd = open("maps/map.ber", O_RDONLY);
    if (m.fd < 0)
        return (NULL);
    m.i = 0;
    while ((m.buffer = get_next_line(m.fd)) != NULL)
    {
        m.map[m.i] = ft_strdup(m.buffer);
        free(m.buffer);
        m.i++;
    }
    m.map[m.i] = NULL;
    close(m.fd);
    return (m.map);
}
