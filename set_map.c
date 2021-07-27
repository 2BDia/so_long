/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 14:08:39 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/07/27 15:13:05 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_bg(t_params *para, void *bg_img)
{
	int	x;
	int	y;

	x = 0;
	while (x < para->win_w)
	{
		y = 0;
		while (y < para->win_h)
		{
			mlx_put_image_to_window(para->mlx, para->win, bg_img, x, y);
			y += 64;
		}
		x += 64;
	}
}

void	set_borders_xy(t_params *para, int x, int y, int mod)
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

void	set_items(t_params *para)
{
	int	i;

	i = 0;
	while (i < para->item_count)
	{
		if (para->items_pos[i].x != 0 && para->items_pos[i].y != 0)
			mlx_put_image_to_window(para->mlx, para->win, para->item_img,
				para->items_pos[i].x, para->items_pos[i].y);
		i++;
	}
}

void	set_rocks(t_params *para)
{
	int	i;

	i = 0;
	while (i < para->rock_count)
	{
		mlx_put_image_to_window(para->mlx, para->win, para->rock_img,
			para->rocks_pos[i].x, para->rocks_pos[i].y);
		i++;
	}
}

void	set_enemies(t_params *para)
{
	int	i;

	i = 0;
	while (i < para->enem_count)
	{
		mlx_put_image_to_window(para->mlx, para->win, para->enem_img,
			para->enem_pos[i].x, para->enem_pos[i].y);
		i++;
	}
}
