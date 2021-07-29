/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:45:06 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/07/29 15:40:28 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_borders(t_params *para, int *i, int *j, int *k)
{
	while (para->map[0][*j])
	{
		if (para->map[0][*j] != '1')
			return (0);
		(*j)++;
	}
	while (para->map[*i])
		(*i)++;
	*j = 0;
	(*i)--;
	while (para->map[*i][*j])
	{
		if (para->map[*i][*j] != '1')
			return (0);
		(*j)++;
	}
	*j = ft_strlen(para->map[0]) - 1;
	while (*k < *i)
	{
		if (para->map[*k][0] != '1' || para->map[*k][*j] != '1')
			return (0);
		(*k)++;
	}
	return (1);
}

static int	check_legal(t_params *para, int i, int j)
{
	if (para->map[i][j] != '1' && para->map[i][j] != '0'
		&& para->map[i][j] != 'P' && para->map[i][j] != 'C'
		&& para->map[i][j] != 'E' && para->map[i][j] != 'M')
		return (0);
	return (1);
}

static int	alloc_elems(t_params *p)
{
	p->items_pos = (t_items *)malloc(sizeof(t_items) * (p->item_count));
	if (!p->items_pos)
		return (0);
	if (p->rock_count > 0)
	{
		p->rocks_pos = (t_rocks *)malloc(sizeof(t_rocks) * (p->rock_count));
		if (!p->rocks_pos)
			return (0);
	}
	if (p->enem_count > 0)
	{
		p->enem_pos = (t_enemy *)malloc(sizeof(t_enemy) * (p->enem_count));
		if (!p->enem_pos)
			return (0);
	}
	return (1);
}

static int	check_inside(t_params *para)
{
	int	i;
	int	j;

	i = 0;
	while (para->map[i])
	{
		j = 0;
		while (para->map[i][j])
		{
			if (!check_legal(para, i, j))
				return (0);
			if (para->map[i][j] == 'C')
				para->item_count++;
			if (para->map[i][j] == 'M')
				para->enem_count++;
			if (para->map[i][j] == '1' && i != 0 && i != para->map_h - 1
				&& j != 0 && j != para->map_w - 1)
				para->rock_count++;
			j++;
		}
		i++;
	}
	if (para->item_count == 0 || !alloc_elems(para))
		return (0);
	return (1);
}

int	check_map(t_params *para, char **argv)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 1;
	para->map = read_map(argv);
	if (!para->map)
		return (0);
	k = check_borders(para, &i, &j, &k);
	para->map_w = j + 1;
	para->map_h = i + 1;
	if (!k)
		return (0);
	k = 0;
	while (k < i)
	{
		if (ft_strlen(para->map[k]) != j + 1)
			return (0);
		k++;
	}
	if (!check_inside(para))
		return (0);
	return (1);
}
