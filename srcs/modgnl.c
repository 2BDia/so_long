/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modgnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:37:52 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/07/29 15:38:15 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*save(char *str)
{
	char	*temp;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	i = ft_modstrlen(str, 1);
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	temp = malloc(sizeof(char) * (ft_modstrlen(str, 0) - i + 1));
	if (!temp)
		return (NULL);
	j = 0;
	i++;
	while (str[i])
		temp[j++] = str[i++];
	temp[j] = '\0';
	free(str);
	return (temp);
}

static int	out(char **str, char **line, int count)
{
	int		i;
	char	*temp;

	if (!(*str))
		return (-1);
	temp = malloc(sizeof(char) * (ft_modstrlen(*str, 1) + 1));
	if (!temp)
		return (-1);
	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
	{
		temp[i] = (*str)[i];
		i++;
	}
	temp[i] = '\0';
	*line = temp;
	*str = save(*str);
	if (count == 0)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*str[1];
	int				count;

	count = 1;
	if (fd < 0 || !line)
		return (-1);
	buff = malloc(sizeof(char) * 2);
	if (!buff)
		return (-1);
	while (!ft_strchr(*str, '\n') && count != 0)
	{
		count = read(fd, buff, 1);
		buff[count] = '\0';
		if (count == -1)
		{
			free(buff);
			return (-1);
		}
		*str = ft_strjoin(*str, buff);
	}
	free(buff);
	return (out(str, line, count));
}
