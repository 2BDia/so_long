/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:27:30 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/07/26 16:46:09 by rvan-aud         ###   ########.fr       */
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

typedef	struct s_enemy
{
	int	x;
	int	y;
}	t_enemy;

typedef struct	s_params
{
	void	*mlx;
	void	*win;
	int 	win_w;
	int		win_h;
	int		pl_count;
	int		pl_x;
	int		pl_y;
	int		pl_rot;
	int		ex_count;
	int		ex_x;
	int		ex_y;
	int		item_count;
	t_items	*items_pos;
	int		rock_count;
	t_rocks	*rocks_pos;
	int		enem_count;
	t_enemy	*enem_pos;
	int		moves;
	int		collected;
	char	**map;
	int		map_w;
	int		map_h;
	void	*pl_up_img;
	void	*pl_do_img;
	void	*pl_ri_img;
	void	*pl_le_img;
	void	*pl_end1_img;
	void	*pl_end2_img;
	void	*bg_img;
	void	*bg2_img;
	void	*rock_img;
	void	*item_img;
	void	*ex_img;
	void	*enem_img;
	int		sprite_w;
	int		sprite_h;
	int		gg;
	int		frames;
	int		water_frame;
}	t_params;

void	print_nbr_on_bg(t_params *para);

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
int		check_ber(char *str);
void	error(t_params *para);

void	set_bg(t_params *para, void *bg_img);
void	set_borders(t_params *para);
void	set_items(t_params *para);
void	set_rocks(t_params *para);
void	set_enemies(t_params *para);

int		check_enemy(t_params *para, int x, int y);
int		check_rock(t_params *para, int x, int y);
int		check_item(t_params *para, int x, int y);
int		check_ex(t_params *para, int x, int y);

int		update(t_params *para);

void	init_sprites(t_params *para);
void	init_params(t_params *para);
void	init_and_start(t_params *para);

#endif