/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:27:30 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/07/21 17:00:40 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef	struct	s_items
{
	int	x;
	int	y;
}	t_items;

typedef	struct s_rocks
{
	int	x;
	int	y;
}	t_rocks;

typedef struct	s_params
{
	void	*mlx;
	void	*win;
	int 	win_w;
	int		win_h;
	int		pl_count;
	int		pl_x;
	int		pl_y;
	int		ex_count;
	int		ex_x;
	int		ex_y;
	int		item_count;
	t_items	*items_pos;
	int		rock_count;
	t_rocks	*rocks_pos;
	int		moves;
	int		collected;
	char	**map;
	int		map_w;
	int		map_h;
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
	int		gg;
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

int		check_map(t_params *para, char **argv);
int		parse_map(t_params *para);

int		ft_close(t_params *para);

void	set_bg(t_params *para);
void	set_borders(t_params *para);
void	set_items(t_params *para);
void	set_rocks(t_params *para);

int		check_rock(t_params *para, int x, int y);
int		check_item(t_params *para, int x, int y);
int		check_ex(t_params *para, int x, int y);

void	loop(t_params *para);

#endif