/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:44:37 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/07/21 14:06:29 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static char	**read_map(char **argv)
{
	char	*line;
	char	**map;
	int		ret;
	int		i;
	int 	fd;

	ret = 1;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		free(line);
		i++;
	}
	close(fd);
	map = (char **)malloc(sizeof(char *) * (i + 1));
	if (!map)
		return (NULL);
	ret = 0;
	ret = 1;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (ret > 0)
	{
		ret = get_next_line(fd, &map[i]);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

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
			if (para->map[i][j] != '1' && para->map[i][j] != '0'
				&& para->map[i][j] != 'P' && para->map[i][j] != 'C'
				&& para->map[i][j] != 'E')
				return (0);
			if (para->map[i][j] == 'C')
				para->item_count++;
			if (para->map[i][j] == '1' && i != 0 && i != para->map_h - 1
				&& j != 0 && j != para->map_w - 1)
				para->rock_count++;
			j++;
		}
		i++;
	}
	if (para->item_count == 0)
		return (0);
	para->items_pos = (t_items *)malloc(sizeof(t_params) * (para->item_count));
	if (para->rock_count > 0)
		para->rocks_pos = (t_rocks *)malloc(sizeof(t_params) * (para->rock_count));
	return (1);
}

int	check_map(t_params *para, char **argv)
{
	int		i;
	int 	j;
	int		k;

	i = 0;
	j = 0;
	k = 1;
	para->map = read_map(argv);
	if (!check_borders(para, &i, &j, &k))
		return (0);
	if (j == i)
		return (0);
	k = 0;
	while (k < i)
	{
		if (ft_strlen(para->map[k]) != j + 1)
			return (0);
		k++;
	}
	para->map_w = j + 1;
	para->map_h = i + 1;
	if (!check_inside(para))
		return (0);
	return (1);
}

int	parse_map(t_params *para)
{
	int	i;
	int	j;
	int	checkpl;
	int	checkex;
	int	item;
	int	rock;

	i = 1;
	checkpl = 0;
	checkex = 0;
	item = 0;
	rock = 0;
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
			j++;
		}
		i++;
	}
	if (checkpl == 0 || checkex == 0)
		return (0);
	return (1);
}