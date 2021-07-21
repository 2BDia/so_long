/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 14:08:59 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/07/21 14:08:59 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_strs(char **strs, int h)
{
	while (h >= 0)
		free(strs[--h]);
	free(strs);
}

static void	free_lst(t_params *para)
{
	if (para->item_count > 0)
	{
		free(para->items_pos);
		if (para->rock_count > 0)
			free(para->rocks_pos);
	}
}

int	ft_close(t_params *para)
{
	if (para->mlx)
	{
		mlx_destroy_window(para->mlx, para->win);
		mlx_destroy_image(para->mlx, para->pl_img);
		mlx_destroy_image(para->mlx, para->bg_img);
		mlx_destroy_image(para->mlx, para->rock_img);
		mlx_destroy_image(para->mlx, para->item_img);
		mlx_destroy_image(para->mlx, para->ex_img);
	}
	if (para->map)
		free_strs(para->map, para->map_h);
	free_lst(para);
	free(para);
	system("leaks so_long");
	exit (0);
}