/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:21:06 by alaaouar          #+#    #+#             */
/*   Updated: 2024/06/27 20:09:57 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

void    insert_xpm_to_char(t_data *img)
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
	img->draw.
}

void	draw_helper(t_data *data, char *file_path)
{
	int		img_width;
	int		img_height;
	
	mlx_xpm_file_to_image(data->mlx, file_path, &img_width, &img_height);
}

void	init_images(t_data *data, t_images *images)
{
	data->img_draw.pl_ptr = draw_helper(data, images->player_left);
	data->img_draw.pr_ptr = draw_helper(data, images->player_right);
	data->img_draw.pu_ptr = draw_helper(data, images->player_up);
	data->img_draw.pd_ptr = draw_helper(data, images->player_down);
	data->img_draw.cl_ptr = draw_helper(data, "image/Collect.xpm");

	// Assuming you have paths for the exit images
	data->img_draw.e1 = draw_helper(data, images->exit_1);
	data->img_draw.e2 = draw_helper(data, images->exit_2);
	data->img_draw.e3 = draw_helper(data, images->exit_3);
	data->img_draw.e4 = draw_helper(data, images->exit_4);

	// Assuming you have paths for the background and wall images
	data->img_draw.back = draw_helper(data, images->background);
	data->img_draw.wall = draw_helper(data, images->wall);
}