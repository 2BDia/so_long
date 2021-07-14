/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:27:24 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/07/14 14:08:36 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

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

void	set_borders(t_params *para)
{
	set_borders_xy(para, 0, 0, 0);
	set_borders_xy(para, 0, para->win_h - 64, 0);
	set_borders_xy(para, 0, 64, 1);
	set_borders_xy(para, para->win_w - 64, 64, 1);
}

int	ft_close(t_params *para)
{
	mlx_destroy_window(para->mlx, para->win);
	mlx_destroy_image(para->mlx, para->pl_img);
	mlx_destroy_image(para->mlx, para->bg_img);
	mlx_destroy_image(para->mlx, para->rock_img);
	free(para);
	exit (0);
}

int	ft_key(int key, t_params *para)
{
	char	*nbr;
	int		check;

	check = 0;
	if (key == 53)
		ft_close(para);
	else if (key == 123)
		check = move_left(para);
	else if (key == 124)
		check = move_right(para);
	else if (key == 125)
		check = move_down(para);
	else if (key == 126)
		check = move_up(para);
	if (key >= 123 && key <= 126 && check == 0)
	{
		nbr = ft_itoa(++para->count);
		write(1, nbr, ft_strlen(nbr));
		write(1, "\n", 1);
		free(nbr);
	}
	return (0);
}

int	main(void)
{
	t_params	*para;

	para = (t_params *)malloc(sizeof(t_params));
	para->count = 0;
	para->posx = 64;
	para->posy = 64;
	para->mlx = mlx_init();
	para->win_w = 64 * 16;
	para->win_h = 64 * 12;
	para->pl_img = mlx_xpm_file_to_image(para->mlx, "./may.xpm", &para->pl_img_w, &para->pl_img_h);
	para->bg_img = mlx_xpm_file_to_image(para->mlx, "./water.xpm", &para->bg_img_w, &para->bg_img_h);
	para->rock_img = mlx_xpm_file_to_image(para->mlx, "./rock.xpm", &para->rock_img_w, &para->rock_img_h);
	para->win = mlx_new_window(para->mlx, para->win_w, para->win_h, "./so_long");
	set_bg(para);
	set_borders(para);
	mlx_put_image_to_window(para->mlx, para->win, para->pl_img, para->posx, para->posy);
	mlx_key_hook(para->win, ft_key, para);
	mlx_hook(para->win, 17, 0L, ft_close, para);
	mlx_loop(para->mlx);
	return (0);
}
