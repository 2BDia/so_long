/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:45:22 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/07/26 15:46:33 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static void	print_back(t_params *para, int mod)
{
	if (mod == 0 || mod == 2)
		set_bg(para, para->bg2_img);
	else
		set_bg(para, para->bg_img);
	set_borders(para);
	if (para->collected < para->item_count)
		set_items(para);
	set_rocks(para);
	mlx_put_image_to_window(para->mlx, para->win, para->ex_img, para->ex_x, para->ex_y);
	if (mod < 2)
	{
		if (para->pl_rot == 0)
			mlx_put_image_to_window(para->mlx, para->win, para->pl_le_img, para->pl_x, para->pl_y);
		else if (para->pl_rot == 1)
			mlx_put_image_to_window(para->mlx, para->win, para->pl_ri_img, para->pl_x, para->pl_y);
		else if (para->pl_rot == 2)
			mlx_put_image_to_window(para->mlx, para->win, para->pl_do_img, para->pl_x, para->pl_y);
		else if (para->pl_rot == 3)
			mlx_put_image_to_window(para->mlx, para->win, para->pl_up_img, para->pl_x, para->pl_y);
	}
}

int	update(t_params *para)
{
	if (para->gg == 3)
		ft_close(para);
	if (para->frames % 10000 == 0 && para->water_frame == 0)
	{
		if (para->gg == 0)
			print_back(para, 0);
		else
			print_back(para, 2);
		para->water_frame = 1;
	}
	else if (para->frames % 10000 == 0 && para->water_frame == 1)
	{
		if (para->gg == 0)
			print_back(para, 1);
		else
			print_back(para, 3);
		para->water_frame = 0;
	}
	if (para->frames % 10000 == 0)
		print_nbr_on_bg(para);
	if (para->frames % 10000 == 0 && para->gg > 0)
	{
		if (para->gg == 1)
			mlx_put_image_to_window(para->mlx, para->win, para->pl_end1_img, para->pl_x, para->pl_y);
		else if (para->gg == 2)
			mlx_put_image_to_window(para->mlx, para->win, para->pl_end2_img, para->pl_x, para->pl_y);
		para->gg++;
	}
    para->frames++;
	return (0);
}
