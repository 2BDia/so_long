/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:44:37 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/07/16 16:21:15 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

char	**read_map(char **argv)
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

int	check_map(t_params *para, char **argv)
{
	int		i;
	int 	j;
	int		k;

	i = 0;
	j = 0;
	k = 1;
	para->map = read_map(argv);
	while (para->map[0][j])
	{
		if (para->map[0][j] != '1')
			return (0);
		j++;
	}
	while (para->map[i])
		i++;
	j = 0;
	i--;
	while (para->map[i][j])
	{
		if (para->map[i][j] != '1')
			return (0);
		j++;
	}
	j = ft_strlen(para->map[0]) - 1;
	while (k < i)
	{
		if (para->map[k][0] != '1' || para->map[k][j] != '1')
			return (0);
		k++;
	}
	para->map_w = j + 1;
	para->map_h = i + 1;
	return (1);
}

// while (map[i])
// 	{
// 		j == 0;
// 		while (map[i][j])
// 		{
			
// 		}
// 		i++;
// 	}