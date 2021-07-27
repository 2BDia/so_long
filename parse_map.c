/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:44:37 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/07/27 15:08:37 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ope(int *x, int *y, int i, int j)
{
	*x = j * 64;
	*y = i * 64;
}

static int	parse_map_helper(t_params *para, int i, int j, int *elem)
{
	if (para->map[i][j] == 'P')
	{
		if (para->pl_x != 0 || para->pl_y != 0)
			return (0);
		ope(&para->pl_x, &para->pl_y, i, j);
	}
	else if (para->map[i][j] == 'E')
	{
		if (para->ex_x != 0 || para->ex_y != 0)
			return (0);
		ope(&para->ex_x, &para->ex_y, i, j);
	}
	else if (para->map[i][j] == 'C')
		ope(&para->items_pos[elem[0]].x, &para->items_pos[elem[0]++].y, i, j);
	else if (para->map[i][j] == '1')
		ope(&para->rocks_pos[elem[1]].x, &para->rocks_pos[elem[1]++].y, i, j);
	else if (para->map[i][j] == 'M')
		ope(&para->enem_pos[elem[2]].x, &para->enem_pos[elem[2]++].y, i, j);
	return (1);
}

int	parse_map(t_params *para)
{
	int	i;
	int	j;
	int	elems[3];

	i = 1;
	elems[0] = 0;
	elems[1] = 0;
	elems[2] = 0;
	while (i < para->map_h - 1)
	{
		j = 1;
		while (j < para->map_w - 1)
		{
			if (!parse_map_helper(para, i, j, elems))
				return (0);
			j++;
		}
		i++;
	}
	if ((para->pl_x == 0 || para->pl_y == 0)
		|| (para->ex_x == 0 || para->ex_y == 0))
		return (0);
	return (1);
}

/*
** elems[0] = item, elem[1] = rock, elem[2] = enemy
*/
