#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_params
{
	void	*mlx;
	void	*win;
	void	*img;
	int		img_w;
	int		img_h;
	void	*bg_img;
	int		bg_img_w;
	int		bg_img_h;
	int		x;
	int		y;
	int		count;
}	t_params;

char	*ft_itoa(int value);
int		ft_strlen(char *str);

#endif