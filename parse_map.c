/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:44:37 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/07/27 14:44:55 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int	parse_map(t_params *para)
{
	int	i;
	int	j;
	int	checkpl;
	int	checkex;
	int	item;
	int	rock;
	int	enemy;

	i = 1;
	checkpl = 0;
	checkex = 0;
	item = 0;
	rock = 0;
	enemy = 0;
	while (i < para->map_h - 1)
	{
		j = 1;
		while (j < para->map_w - 1)
		{
			if (para->map[i][j] == 'P')
			{
				if (checkpl == 1)
					return (0);
				para->pl_x = j * 64;
				para->pl_y = i * 64;
				checkpl = 1;
			}
			else if (para->map[i][j] == 'E')
			{
				if (checkex == 1)
					return (0);
				para->ex_x = j * 64;
				para->ex_y = i * 64;
				checkex = 1;
			}
			else if (para->map[i][j] == 'C')
			{
				para->items_pos[item].x = j * 64;
				para->items_pos[item++].y = i * 64;
			}
			else if (para->map[i][j] == '1')
			{
				para->rocks_pos[rock].x = j * 64;
				para->rocks_pos[rock++].y = i * 64;
			}
			else if (para->map[i][j] == 'M')
			{
				para->enem_pos[enemy].x = j * 64;
				para->enem_pos[enemy++].y = i * 64;
			}
			j++;
		}
		i++;
	}
	if (checkpl == 0 || checkex == 0)
		return (0);
	return (1);
}
