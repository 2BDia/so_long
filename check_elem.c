/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 14:44:21 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/07/23 11:57:29 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rock(t_params *para, int x, int y)
{
	int	i;

	i = 0;
	while (i < para->rock_count)
	{
		if (x == para->rocks_pos[i].x)
			if (y == para->rocks_pos[i].y)
				return (1);
		i++;
	}
	return (0);
}

int	check_item(t_params *para, int x, int y)
{
	int	i;

	i = 0;
	while (i < para->item_count)
	{
		if (x == para->items_pos[i].x)
			if (y == para->items_pos[i].y)
			{
				para->items_pos[i].x = 0;
				para->items_pos[i].y = 0;
				return (1);
			}
		i++;
	}
	return (0);
}

int	check_ex(t_params *para, int x, int y)
{
	if (x == para->ex_x)
		if (y == para->ex_y)
			return (1);
	return (0);
}
