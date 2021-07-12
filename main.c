#include "so_long.h"
#include <stdio.h>

int	ft_close(int key, t_params *para)
{
	if (key == 53)
	{
		mlx_destroy_window(para->mlx, para->win);
		// mlx_destroy_image(para->mlx, para->img);
	}
	exit (0);
}

int	ft_key(int key, t_params *para)
{
	char	*nbr;

	if (key == 53)
		ft_close(key, para);
	// else if (key == 123)
	// 	mlx_pixel_put(para->mlx, para->win, --para->x, para->y, 0xFFFFFF);
	// else if (key == 124)
	// 	mlx_pixel_put(para->mlx, para->win, ++para->x, para->y, 0xFFFFFF);
	// else if (key == 125)
	// 	mlx_pixel_put(para->mlx, para->win, para->x, ++para->y, 0xFFFFFF);
	// else if (key == 126)
	// 	mlx_pixel_put(para->mlx, para->win, para->x, --para->y, 0xFFFFFF);
	if (key >= 123 && key <= 126)
	{
		nbr = ft_itoa(++para->count);
		write(1, nbr, ft_strlen(nbr));
		write(1, "\n", 1);
	}
	return (0);
}

void	set_bg(t_params *para, int win_w, int win_h)
{
	int	x;
	int	y;

	x = 0;
	while (x < win_w)
	{
		y = 0;
		while (y < win_h)
		{
			mlx_put_image_to_window(para->mlx, para->win, para->bg_img, x, y);
			y += 64;
		}
		x += 64;
	}
}

int	main(void)
{
	t_params	*para;
	int 		win_w;
	int			win_h;

	para = (t_params *)malloc(sizeof(t_params));
	para->count = 0;
	para->x = 0;
	para->y = 0;
	para->mlx = mlx_init();
	win_w = 64 * 16;
	win_h = 64 * 12;
	// if (!para->mlx) necessaire??
	// 	return (-1);
	para->img = mlx_xpm_file_to_image(para->mlx, "./may.xpm", &para->img_w, &para->img_h);
	para->bg_img = mlx_xpm_file_to_image(para->mlx, "./water.xpm", &para->bg_img_w, &para->bg_img_h);
	para->win = mlx_new_window(para->mlx, win_w, win_h, "./so_long");
	// if (!para->win) necessaire??
	// 	return (-1);
	set_bg(para, win_w, win_h);
	// mlx_put_image_to_window(para->mlx, para->win, para->img, 500, 500);
	mlx_key_hook(para->win, ft_key, para);
	mlx_hook(para->win, 17, 0L, ft_close, para);
	mlx_loop(para->mlx);
	free(para);
	return (0);
}
