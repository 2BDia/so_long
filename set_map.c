/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 14:08:39 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/07/21 14:09:41 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_bg(t_params *para)
{
	int	x;
	int	y;

	x = 0;
	while (x < para->win_w)
	{
		y = 0;
		while (y < para->win_h)
		{
			mlx_put_image_to_window(para->mlx, para->win, para->bg_img, x, y);
			y += 64;
		}
		x += 64;
	}
}

static void	set_borders_xy(t_params *para, int x, int y, int mod)
{
	if (mod == 0)
	{
		while (x < para->win_w)
		{
			mlx_put_image_to_window(para->mlx, para->win, para->rock_img, x, y);
			x += 64;
		}
	}
	else if (mod == 1)
	{
		while (y < para->win_h - 64)
		{
			mlx_put_image_to_window(para->mlx, para->win, para->rock_img, x, y);
			y += 64;
		}
	}
}

void	set_borders(t_params *para)
{
	set_borders_xy(para, 0, 0, 0);
	set_borders_xy(para, 0, para->win_h - 64, 0);
	set_borders_xy(para, 0, 64, 1);
	set_borders_xy(para, para->win_w - 64, 64, 1);
}

void	set_items(t_params *para)
{
	int	i;

	i = 0;
	while (i < para->item_count)
	{
		mlx_put_image_to_window(para->mlx, para->win, para->item_img, para->items_pos[i].x, para->items_pos[i].y);
		i++;
	}
}

void	set_rocks(t_params *para)
{
	int	i;

	i = 0;
	while (i < para->rock_count)
	{
		mlx_put_image_to_window(para->mlx, para->win, para->rock_img, para->rocks_pos[i].x, para->rocks_pos[i].y);
		i++;
	}
}
