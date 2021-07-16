/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:27:30 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/07/16 11:51:10 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct	s_params
{
	void	*mlx;
	void	*win;
	int 	win_w;
	int		win_h;
	void	*pl_img;
	int		pl_img_w;
	int		pl_img_h;
	void	*bg_img;
	int		bg_img_w;
	int		bg_img_h;
	void	*rock_img;
	int		rock_img_w;
	int		rock_img_h;
	void	*item_img;
	int		item_img_w;
	int		item_img_h;
	void	*ex_img;
	int		ex_img_w;
	int		ex_img_h;
	int		posx;
	int		posy;
	int		count;
}	t_params;

char	*ft_itoa(int value);
int		ft_strlen(char *str);

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strchr(const char *s, int c);
int		ft_modstrlen(const char *s, int mod);

int		move_left(t_params *para);
int		move_right(t_params *para);
int		move_down(t_params *para);
int		move_up(t_params *para);

#endif