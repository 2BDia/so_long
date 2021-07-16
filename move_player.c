/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:27:20 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/07/16 16:10:23 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_left(t_params *para)
{
	if (para->posx == 64)
		return (1);
	mlx_put_image_to_window(para->mlx, para->win, para->bg_img, para->posx, para->posy);
	para->posx -= 64;
	mlx_put_image_to_window(para->mlx, para->win, para->pl_img, para->posx, para->posy);
	return (0);
}

int	move_right(t_params *para)
{
	if (para->posx == para->win_w - 128)
		return (1);
	mlx_put_image_to_window(para->mlx, para->win, para->bg_img, para->posx, para->posy);
	para->posx += 64;
	mlx_put_image_to_window(para->mlx, para->win, para->pl_img, para->posx, para->posy);
	return (0);
}

int	move_down(t_params *para)
{
	if (para->posy == para->win_h - 128)
		return (1);
	mlx_put_image_to_window(para->mlx, para->win, para->bg_img, para->posx, para->posy);
	para->posy += 64;
	mlx_put_image_to_window(para->mlx, para->win, para->pl_img, para->posx, para->posy);
	return (0);
}

int	move_up(t_params *para)
{
	if (para->posy == 64)
		return (1);
	mlx_put_image_to_window(para->mlx, para->win, para->bg_img, para->posx, para->posy);
	para->posy -= 64;
	mlx_put_image_to_window(para->mlx, para->win, para->pl_img, para->posx, para->posy);
	return (0);
}
