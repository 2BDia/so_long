/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:27:20 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/07/27 14:11:14 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	place_bg_ex(t_params *para)
{
	if (para->water_frame == 0)
		mlx_put_image_to_window(para->mlx, para->win,
			para->bg_img, para->pl_x, para->pl_y);
	else
		mlx_put_image_to_window(para->mlx, para->win,
			para->bg2_img, para->pl_x, para->pl_y);
	if (check_ex(para, para->pl_x, para->pl_y))
		mlx_put_image_to_window(para->mlx, para->win,
			para->ex_img, para->pl_x, para->pl_y);
}

int	move_left(t_params *para)
{
	if (para->pl_x == 64 || check_rock(para, para->pl_x - 64, para->pl_y))
	{
		place_bg_ex(para);
		mlx_put_image_to_window(para->mlx, para->win,
			para->pl_le_img, para->pl_x, para->pl_y);
		para->pl_rot = 0;
		return (1);
	}
	if (check_enemy(para, para->pl_x - 64, para->pl_y))
	{
		place_bg_ex(para);
		mlx_put_image_to_window(para->mlx, para->win,
			para->pl_le_img, para->pl_x, para->pl_y);
		para->gg = -1;
		return (1);
	}
	place_bg_ex(para);
	para->pl_x -= 64;
	mlx_put_image_to_window(para->mlx, para->win,
		para->pl_le_img, para->pl_x, para->pl_y);
	para->pl_rot = 0;
	return (0);
}

int	move_right(t_params *para)
{
	if (para->pl_x == para->win_w - 128
		|| check_rock(para, para->pl_x + 64, para->pl_y))
	{
		place_bg_ex(para);
		mlx_put_image_to_window(para->mlx, para->win,
			para->pl_ri_img, para->pl_x, para->pl_y);
		para->pl_rot = 1;
		return (1);
	}
	if (check_enemy(para, para->pl_x + 64, para->pl_y))
	{
		place_bg_ex(para);
		mlx_put_image_to_window(para->mlx, para->win,
			para->pl_ri_img, para->pl_x, para->pl_y);
		para->gg = -1;
		return (1);
	}
	place_bg_ex(para);
	para->pl_x += 64;
	mlx_put_image_to_window(para->mlx, para->win,
		para->pl_ri_img, para->pl_x, para->pl_y);
	para->pl_rot = 1;
	return (0);
}

int	move_down(t_params *para)
{
	if (para->pl_y == para->win_h - 128
		|| check_rock(para, para->pl_x, para->pl_y + 64))
	{
		place_bg_ex(para);
		mlx_put_image_to_window(para->mlx, para->win,
			para->pl_do_img, para->pl_x, para->pl_y);
		para->pl_rot = 2;
		return (1);
	}
	if (check_enemy(para, para->pl_x, para->pl_y + 64))
	{
		place_bg_ex(para);
		mlx_put_image_to_window(para->mlx, para->win,
			para->pl_do_img, para->pl_x, para->pl_y);
		para->gg = -1;
		return (1);
	}
	place_bg_ex(para);
	para->pl_y += 64;
	mlx_put_image_to_window(para->mlx, para->win,
		para->pl_do_img, para->pl_x, para->pl_y);
	para->pl_rot = 2;
	return (0);
}

int	move_up(t_params *para)
{
	if (para->pl_y == 64 || check_rock(para, para->pl_x, para->pl_y - 64))
	{
		place_bg_ex(para);
		mlx_put_image_to_window(para->mlx, para->win,
			para->pl_up_img, para->pl_x, para->pl_y);
		para->pl_rot = 3;
		return (1);
	}
	if (check_enemy(para, para->pl_x, para->pl_y - 64))
	{
		place_bg_ex(para);
		mlx_put_image_to_window(para->mlx, para->win,
			para->pl_up_img, para->pl_x, para->pl_y);
		para->gg = -1;
		return (1);
	}
	place_bg_ex(para);
	para->pl_y -= 64;
	mlx_put_image_to_window(para->mlx, para->win,
		para->pl_up_img, para->pl_x, para->pl_y);
	para->pl_rot = 3;
	return (0);
}
