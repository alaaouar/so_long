/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:41:27 by alaaouar          #+#    #+#             */
/*   Updated: 2024/05/25 18:03:52 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/so_long.h"

int player_location(t_map *play)
{    
    int i;
    int j;

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
            }
            j++;
        }
        i++;
    }
    return (0);
}

int handle_keyboard(int keycode, t_data *img)
{   
    if (keycode == 53)
    {
        mlx_destroy_window(img->mlx, img->win);
        exit(0);
    }
    if (keycode == 13)
    {
        if(img->map.map[img->map.player_y - 1][img->map.player_x] == '1')
            return (0);
        
        img->map.map[img->map.player_y][img->map.player_x] = '0';
        img->map.player_y--;
        img->map.map[img->map.player_y][img->map.player_x] = 'P';
        map_design(*img, img->map.map);
    }
    if (keycode == 1)
    {
        if(img->map.map[img->map.player_y + 1][img->map.player_x] == '1')
            return (0);
        img->map.map[img->map.player_y][img->map.player_x] = '0';
        img->map.player_y++;
        img->map.map[img->map.player_y][img->map.player_x] = 'P';
        map_design(*img, img->map.map);
    }
    if (keycode == 0)
    {
        if(img->map.map[img->map.player_y][img->map.player_x - 1] == '1')
            return (0);
        img->map.map[img->map.player_y][img->map.player_x] = '0';
        img->map.player_x--;
        img->map.map[img->map.player_y][img->map.player_x] = 'P';
        map_design(*img, img->map.map);
    }
    if (keycode == 2)
    {
        if(img->map.map[img->map.player_y][img->map.player_x + 1] == '1')
            return (0);
        img->map.map[img->map.player_y][img->map.player_x] = '0';
        img->map.player_x++;
        img->map.map[img->map.player_y][img->map.player_x] = 'P';
        map_design(*img, img->map.map);
    }
    return (0);
}

int	main(void)
{
    t_data    img;

    img.map.y = 0;
    img.map.map = fill_map();
    img.map.x = mapcheck_return_size(img.map.map);
    img.map.y = ft_strlen(img.map.map[0]) - 1;
    img.map.x = img.map.x * 50;
    img.map.y = img.map.y * 50;
    if (img.map.x > 1440 || img.map.y > 2560)
    {
        ft_putstr_fd("Error\nMap is too big\n", 2);
        return (0);
    }
    img.i = 0;
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, img.map.y, img.map.x, "my so_long");
    player_location(&img.map);
    map_design(img, img.map.map);
    mlx_key_hook(img.win, handle_keyboard, &img);
	mlx_loop(img.mlx);
    while (img.map.map[img.i] != NULL)
    {
        free(img.map.map[img.i]);
        img.i++;
    }
    free(img.map.map);
    return (0);
}
