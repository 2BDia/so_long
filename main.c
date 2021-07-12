#include "so_long.h"
#include <stdio.h>

int	ft_close(int key, t_params *para)
{
	if (key == 53)
	{
		mlx_destroy_window(para->mlx, para->win);
		mlx_destroy_image(para->mlx, para->img);
	}
	exit (0);
}

int	ft_key(int key, t_params *para)
{
	char	*nbr;

	if (key == 53)
		ft_close(key, para);
	else if (key == 123)
		mlx_pixel_put(para->mlx, para->win, --para->x, para->y, 0xFFFFFF);
	else if (key == 124)
		mlx_pixel_put(para->mlx, para->win, ++para->x, para->y, 0xFFFFFF);
	else if (key == 125)
		mlx_pixel_put(para->mlx, para->win, para->x, ++para->y, 0xFFFFFF);
	else if (key == 126)
		mlx_pixel_put(para->mlx, para->win, para->x, --para->y, 0xFFFFFF);
	if (key >= 123 && key <= 126)
	{
		nbr = ft_itoa(++para->count);
		write(1, nbr, ft_strlen(nbr));
		write(1, "\n", 1);
	}
	return (0);
}

int	main(void)
{
	t_params	*para;

	para = (t_params *)malloc(sizeof(t_params));
	para->count = 0;
	para->x = 250;
	para->y = 250;
	para->mlx = mlx_init();
	if (!para->mlx)
		return (-1);
	para->img = mlx_new_image(para->mlx, 1920, 1080);
	para->win = mlx_new_window(para->mlx, 500, 500, "./so_long");
	if (!para->win)
		return (-1);
	mlx_pixel_put(para->mlx, para->win, para->x, para->y, 0xFFFFFF);
	mlx_key_hook(para->win, ft_key, para);
	mlx_hook(para->win, 17, 0L, ft_close, para);
	mlx_loop(para->mlx);
	return (0);
}
