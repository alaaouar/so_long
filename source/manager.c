/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:21:06 by alaaouar          #+#    #+#             */
/*   Updated: 2024/06/27 19:40:41 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	insert_xpm_to_char(t_data *img)
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
}