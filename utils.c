/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:27:27 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/07/14 12:27:27 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	checksign(long int *quotient, int value)
{
	int	sign;

	sign = 0;
	if (value < 0)
	{
		sign = 1;
		*quotient = (long)value;
		*quotient *= -1;
	}
	else
		*quotient = value;
	return (sign);
}

static void	placestr(char *str, int value, int i, int sign)
{
	long int	quotient;
	int			j;

	j = 1;
	while (--i > 0)
		j *= 10;
	i = 0;
	if (sign == 1)
	{
		str[0] = '-';
		i++;
	}
	quotient = 0;
	while (j > 0)
	{
		quotient = value / j;
		quotient %= 10;
		if (sign == 1)
			quotient *= -1;
		str[i++] = quotient + '0';
		j /= 10;
	}
	str[i] = '\0';
}

char	*ft_itoa(int value)
{
	char		*str;
	int			i;
	long int	quotient;
	int			sign;

	i = 0;
	sign = checksign(&quotient, value);
	while (quotient > 0)
	{
		quotient /= 10;
		i++;
	}
	if (value == 0)
		str = malloc(sizeof(char) * (i + 2));
	else
		str = malloc(sizeof(char) * (i + 1 + sign));
	if (!str)
		return (NULL);
	placestr(str, value, i, sign);
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}