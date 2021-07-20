/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modgnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:37:52 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/07/20 15:39:11 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int get_next_line(int fd, char **line)
{
    int i;
    int l;
    int	r;
    char c;
    char *tmp;

    r = 0;
    l = 1;
    if(!(*line = malloc(l)))
        return(-1);
    (*line)[0] = 0;
    while((r = read(fd, &c, 1)) && l++ && c != '\n')
    {
        if(!(tmp = malloc(l)))
        {
            free(*line);
            return(-1);
        }
        i = -1;
        while(++i < (l - 2))
            tmp[i] = (*line)[i];
        tmp[i] = c;
        tmp[i + 1] = 0;
        free(*line);
        *line = tmp;
    }
    return(r);
}
