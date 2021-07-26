/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:24:54 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/07/26 15:26:24 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprites(t_params *para)
{
	para->pl_up_img = mlx_xpm_file_to_image(para->mlx, "sprites/mayup.xpm", &para->pl_img_w, &para->pl_img_h);
	para->pl_do_img = mlx_xpm_file_to_image(para->mlx, "sprites/maydown.xpm", &para->pl_img_w, &para->pl_img_h);
	para->pl_ri_img = mlx_xpm_file_to_image(para->mlx, "sprites/mayright.xpm", &para->pl_img_w, &para->pl_img_h);
	para->pl_le_img = mlx_xpm_file_to_image(para->mlx, "sprites/mayleft.xpm", &para->pl_img_w, &para->pl_img_h);
	para->pl_end1_img = mlx_xpm_file_to_image(para->mlx, "sprites/mayend1.xpm", &para->pl_img_w, &para->pl_img_h);
	para->pl_end2_img = mlx_xpm_file_to_image(para->mlx, "sprites/mayend2.xpm", &para->pl_img_w, &para->pl_img_h);
	para->bg_img = mlx_xpm_file_to_image(para->mlx, "sprites/water.xpm", &para->bg_img_w, &para->bg_img_h);
	para->bg2_img = mlx_xpm_file_to_image(para->mlx, "sprites/water2.xpm", &para->bg2_img_w, &para->bg2_img_h);
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
	para->pl_rot = 2;
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
	para->pl_up_img = NULL;
	para->pl_do_img = NULL;
	para->pl_ri_img = NULL;
	para->pl_le_img = NULL;
	para->pl_end1_img = NULL;
	para->pl_end2_img = NULL;
	para->pl_img_w = 0;
	para->pl_img_h = 0;
	para->bg_img = NULL;
	para->bg_img_w = 0;
	para->bg_img_h = 0;
	para->bg2_img = NULL;
	para->bg2_img_w = 0;
	para->bg2_img_h = 0;
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
	para->frames = 0;
	para->water_frame = 0;
}

void	init_and_start(t_params *para)
{
	para->mlx = mlx_init();
	init_sprites(para);
	para->win_w = 64 * para->map_w;
	para->win_h = 64 * para->map_h;
	para->win = mlx_new_window(para->mlx, para->win_w, para->win_h, "./so_long");
	set_bg(para, para->bg_img);
	set_borders(para);
	set_items(para);
	set_rocks(para);
	mlx_put_image_to_window(para->mlx, para->win, para->pl_do_img, para->pl_x, para->pl_y);
	mlx_put_image_to_window(para->mlx, para->win, para->ex_img, para->ex_x, para->ex_y);
}
