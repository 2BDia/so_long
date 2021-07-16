/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:44:37 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/07/16 17:23:24 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		i++;
	}
	close(fd);
	map = (char **)malloc(sizeof(char *) * (i + 1));
	ret = 0;
	while (ret < i)
		map[ret++] = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
	ret = 1;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		map[i++] = line;
	}
	map[i] = NULL;
	if (line)
		free(line);
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
			j++;
		}
		i++;
	}
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

void	parse_map(t_params *para)
{
	
}