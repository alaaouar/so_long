/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:41:27 by alaaouar          #+#    #+#             */
/*   Updated: 2024/05/24 22:21:01 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/so_long.h"


int	main(void)
{
    char	**map;
    t_data    img;
    t_map   smap;

    smap.y = 0;
    map = fill_map();
    smap.x = mapcheck_return_size(map);
    smap.y = ft_strlen(map[0]) - 1;
    smap.x = smap.x * 50;
    smap.y = smap.y * 50;
    if (smap.x > 1440 || smap.y > 2560)
    {
        ft_putstr_fd("Error\nMap is too big\n", 2);
        return (0);
    }
    img.i = 0;
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, smap.y, smap.x, "my so_long");
    map_design(&img, map);
	mlx_loop(img.mlx);
    while (map[img.i] != NULL)
    {
        free(map[img.i]);
        img.i++;
    }
    free(map);
    return (0);
}
