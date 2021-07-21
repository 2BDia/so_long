/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:27:24 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/07/21 17:42:04 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <time.h>

static void	process_keys(int key, t_params *para)
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
		nbr = ft_itoa(++para->moves);
		write(1, nbr, ft_strlen(nbr));
		write(1, "\n", 1);
		free(nbr);
	}
}

int	ft_key(int key, t_params *para)
{
	if (para->gg)
		ft_close(para);
	process_keys(key, para);
	if (check_item(para, para->pl_x, para->pl_y))
		para->collected++;
	if (check_ex(para, para->pl_x, para->pl_y) && para->collected == para->item_count)
	{
		para->gg = 1;
		// write(1, "ok\n", 3);
	}
	// printf("itemcount=%d\n", para->item_count);
	// printf("collected=%d\n", para->collected);
	return (0);
}

void	init_sprites(t_params *para)
{
	para->pl_img = mlx_xpm_file_to_image(para->mlx, "sprites/may.xpm", &para->pl_img_w, &para->pl_img_h);
	para->bg_img = mlx_xpm_file_to_image(para->mlx, "sprites/water.xpm", &para->bg_img_w, &para->bg_img_h);
	para->rock_img = mlx_xpm_file_to_image(para->mlx, "sprites/rock.xpm", &para->rock_img_w, &para->rock_img_h);
	para->item_img = mlx_xpm_file_to_image(para->mlx, "sprites/item.xpm", &para->item_img_w, &para->item_img_h);
	para->ex_img = mlx_xpm_file_to_image(para->mlx, "sprites/ex.xpm", &para->ex_img_w, &para->ex_img_h);
}

void	init_params(t_params *para)
{
	para->mlx = NULL;
	para->win = NULL;
	para->win_w = 0;
	para->win_h = 0;
	para->pl_count = 0;
	para->pl_x = 0;
	para->pl_y = 0;
	para->ex_count = 0;
	para->ex_x = 0;
	para->ex_y = 0;
	para->item_count = 0;
	para->items_pos = NULL;
	para->rock_count = 0;
	para->rocks_pos = NULL;
	para->moves = 0;
	para->collected = 0;
	para->map = NULL;
	para->pl_img = NULL;
	para->pl_img_w = 0;
	para->pl_img_h = 0;
	para->bg_img = NULL;
	para->bg_img_w = 0;
	para->bg_img_h = 0;
	para->rock_img = NULL;
	para->rock_img_w = 0;
	para->rock_img_h = 0;
	para->item_img = NULL;
	para->item_img_w = 0;
	para->item_img_h = 0;
	para->ex_img = NULL;
	para->ex_img_w = 0;
	para->ex_img_h = 0;
	para->gg = 0;
}

int	main(int argc, char **argv)
{
	t_params	*para;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	para = (t_params *)malloc(sizeof(t_params));
	init_params(para);
	if (!check_map(para, argv))
	{
		write(1, "Error\n", 6);
		ft_close(para);
	}
	if (!parse_map(para))
	{
		write(1, "Error\n", 6);
		ft_close(para);
	}
	para->mlx = mlx_init();
	init_sprites(para);
	para->win_w = 64 * para->map_w;
	para->win_h = 64 * para->map_h;
	para->win = mlx_new_window(para->mlx, para->win_w, para->win_h, "./so_long");
	set_bg(para);
	set_borders(para);
	set_items(para);
	set_rocks(para);
	mlx_put_image_to_window(para->mlx, para->win, para->pl_img, para->pl_x, para->pl_y);
	mlx_put_image_to_window(para->mlx, para->win, para->ex_img, para->ex_x, para->ex_y);
	mlx_key_hook(para->win, ft_key, para);
	mlx_hook(para->win, 17, 0L, ft_close, para);
	mlx_loop(para->mlx);
	return (0);
}
