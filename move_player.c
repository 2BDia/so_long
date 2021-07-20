/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:27:20 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/07/20 18:01:18 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_left(t_params *para)
{
	int	i;

	i = 0;
	if (para->pl_x == 64)
		return (1);
	while (i < para->rock_count)
	{
		if (para->pl_x - 64 == para->rocks_pos[i].x)
			if (para->pl_y == para->rocks_pos[i].y)
				return (1);
		i++;
	}
	mlx_put_image_to_window(para->mlx, para->win, para->bg_img, para->pl_x, para->pl_y);
	para->pl_x -= 64;
	mlx_put_image_to_window(para->mlx, para->win, para->pl_img, para->pl_x, para->pl_y);
	return (0);
}

int	move_right(t_params *para)
{
	int	i;

	i = 0;
	if (para->pl_x == para->win_w - 128)
		return (1);
	while (i < para->rock_count)
	{
		if (para->pl_x + 64 == para->rocks_pos[i].x)
			if (para->pl_y == para->rocks_pos[i].y)
				return (1);
		i++;
	}
	mlx_put_image_to_window(para->mlx, para->win, para->bg_img, para->pl_x, para->pl_y);
	para->pl_x += 64;
	mlx_put_image_to_window(para->mlx, para->win, para->pl_img, para->pl_x, para->pl_y);
	return (0);
}

int	move_down(t_params *para)
{
	int	i;

	i = 0;
	if (para->pl_y == para->win_h - 128)
		return (1);
	while (i < para->rock_count)
	{
		if (para->pl_x == para->rocks_pos[i].x)
			if (para->pl_y + 64 == para->rocks_pos[i].y)
				return (1);
		i++;
	}
	mlx_put_image_to_window(para->mlx, para->win, para->bg_img, para->pl_x, para->pl_y);
	para->pl_y += 64;
	mlx_put_image_to_window(para->mlx, para->win, para->pl_img, para->pl_x, para->pl_y);
	return (0);
}

int	move_up(t_params *para)
{
	int	i;

	i = 0;
	if (para->pl_y == 64)
		return (1);
	while (i < para->rock_count)
	{
		if (para->pl_x == para->rocks_pos[i].x)
			if (para->pl_y - 64 == para->rocks_pos[i].y)
				return (1);
		i++;
	}
	mlx_put_image_to_window(para->mlx, para->win, para->bg_img, para->pl_x, para->pl_y);
	para->pl_y -= 64;
	mlx_put_image_to_window(para->mlx, para->win, para->pl_img, para->pl_x, para->pl_y);
	return (0);
}
