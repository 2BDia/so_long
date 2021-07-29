/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:46:13 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/07/29 15:39:48 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(char **argv, char **line)
{
	int	fd;
	int	ret;
	int	i;

	i = 0;
	ret = 1;
	fd = open(argv[1], O_RDONLY);
	while (ret > 0)
	{
		ret = get_next_line(fd, line);
		if (ret == -1)
			return (-1);
		free(*line);
		i++;
	}
	close(fd);
	return (i);
}

char	**read_map(char **argv)
{
	char	*line;
	char	**map;
	int		ret;
	int		i;
	int		fd;

	i = count_lines(argv, &line);
	if (i == -1)
		return (NULL);
	map = (char **)malloc(sizeof(char *) * (i + 1));
	if (!map)
		return (NULL);
	ret = 0;
	ret = 1;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (ret > 0)
		ret = get_next_line(fd, &map[i++]);
	map[i] = NULL;
	close(fd);
	return (map);
}
