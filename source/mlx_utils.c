/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:10:20 by alaaouar          #+#    #+#             */
/*   Updated: 2024/05/25 18:11:37 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void draw_image(t_data *data, char *file_path, int x, int y)
{
    void    *img;
    int     img_width;
    int     img_height;

    img = mlx_xpm_file_to_image(data->mlx, file_path, &img_width, &img_height);
    if (!img)
    {
        ft_putstr_fd("Error\nFailed to load image.\n", 2);
        exit(1);
    }
    mlx_put_image_to_window(data->mlx, data->win, img, x, y);
}

int mapcheck_return_size(char **map)
{
    int     count;
    int    i;

    count = 0;
    i = 0;
    while (map[count])
        count++;
    while (map[i])
    {
        if (ft_strlen(map[i]) != ft_strlen(map[i + 1]) && i < count - 2)
        {
            ft_putstr_fd("Error\nMap is not rectangular.\n", 2);
            exit(1);
        }
        i++;

    }
    return (count);
}

void    map_design(t_data img , char **map)
{
    while (map[img.i] != NULL)
    {
        img.j = 0;
        while (map[img.i][img.j] != '\0')
        {
            if (map[img.i][img.j] == '1')
                draw_image(&img, "image/Wall.xpm", img.j * 50, img.i * 50);
            else if (map[img.i][img.j] == '0')
                draw_image(&img, "image/Background.xpm", img.j * 50, img.i * 50);
            else if (map[img.i][img.j] == 'P')
            {
                draw_image(&img, "image/Background.xpm", img.j * 50, img.i * 50);
                draw_image(&img, "image/le3ab.xpm", img.j * 50, img.i * 50);
            }
            else if (map[img.i][img.j] == 'E')
            {
                draw_image(&img, "image/Background.xpm", img.j * 50, img.i * 50);
                draw_image(&img, "image/Exit.xpm", img.j * 50, img.i * 50);
            }
            else if (map[img.i][img.j] == 'C')
            {
                draw_image(&img, "image/Background.xpm", img.j * 50, img.i * 50);
                draw_image(&img, "image/Collect.xpm", img.j * 50, img.i * 50);
            }
            else if (map[img.i][img.j] == 'X')
            {
                draw_image(&img, "image/Background.xpm", img.j * 50, img.i * 50);
                draw_image(&img, "image/Enemie.xpm", img.j * 50, img.i * 50);
            }
            img.j++;
        }
        img.i++;
    }
}

void   player_image(t_data *img)
{
    img->images.player_left = "image/player_left.xpm";
    img->images.player_right = "image/player_right.xpm";
    img->images.player_up = "image/player_up.xpm";
    img->images.player_down = "image/player_down.xpm";
}