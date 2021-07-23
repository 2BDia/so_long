/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:27:20 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/07/23 12:00:56 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_left(t_params *para)
{
	if (para->pl_x == 64 || check_rock(para, para->pl_x - 64, para->pl_y))
	{
		mlx_put_image_to_window(para->mlx, para->win, para->bg_img, para->pl_x, para->pl_y);
		mlx_put_image_to_window(para->mlx, para->win, para->pl_le_img, para->pl_x, para->pl_y);
		return (1);
	}
	if (check_ex(para, para->pl_x, para->pl_y))
		mlx_put_image_to_window(para->mlx, para->win, para->ex_img, para->pl_x, para->pl_y);
	mlx_put_image_to_window(para->mlx, para->win, para->bg_img, para->pl_x, para->pl_y);
	para->pl_x -= 64;
	mlx_put_image_to_window(para->mlx, para->win, para->pl_le_img, para->pl_x, para->pl_y);
	return (0);
}

int	move_right(t_params *para)
{
	if (para->pl_x == para->win_w - 128 || check_rock(para, para->pl_x + 64, para->pl_y))
	{
		mlx_put_image_to_window(para->mlx, para->win, para->bg_img, para->pl_x, para->pl_y);
		mlx_put_image_to_window(para->mlx, para->win, para->pl_ri_img, para->pl_x, para->pl_y);
		return (1);
	}
	mlx_put_image_to_window(para->mlx, para->win, para->bg_img, para->pl_x, para->pl_y);
	if (check_ex(para, para->pl_x, para->pl_y))
		mlx_put_image_to_window(para->mlx, para->win, para->ex_img, para->pl_x, para->pl_y);
	para->pl_x += 64;
	mlx_put_image_to_window(para->mlx, para->win, para->pl_ri_img, para->pl_x, para->pl_y);
	return (0);
}

int	move_down(t_params *para)
{
	if (para->pl_y == para->win_h - 128 || check_rock(para, para->pl_x, para->pl_y + 64))
	{
		mlx_put_image_to_window(para->mlx, para->win, para->bg_img, para->pl_x, para->pl_y);
		mlx_put_image_to_window(para->mlx, para->win, para->pl_do_img, para->pl_x, para->pl_y);
		return (1);
	}
	if (check_ex(para, para->pl_x, para->pl_y))
		mlx_put_image_to_window(para->mlx, para->win, para->ex_img, para->pl_x, para->pl_y);
	mlx_put_image_to_window(para->mlx, para->win, para->bg_img, para->pl_x, para->pl_y);
	para->pl_y += 64;
	mlx_put_image_to_window(para->mlx, para->win, para->pl_do_img, para->pl_x, para->pl_y);
	return (0);
}

int	move_up(t_params *para)
{
	if (para->pl_y == 64 || check_rock(para, para->pl_x, para->pl_y - 64))
	{
		mlx_put_image_to_window(para->mlx, para->win, para->bg_img, para->pl_x, para->pl_y);
		mlx_put_image_to_window(para->mlx, para->win, para->pl_up_img, para->pl_x, para->pl_y);
		return (1);
	}
	if (check_ex(para, para->pl_x, para->pl_y))
		mlx_put_image_to_window(para->mlx, para->win, para->ex_img, para->pl_x, para->pl_y);
	mlx_put_image_to_window(para->mlx, para->win, para->bg_img, para->pl_x, para->pl_y);
	para->pl_y -= 64;
	mlx_put_image_to_window(para->mlx, para->win, para->pl_up_img, para->pl_x, para->pl_y);
	return (0);
}
