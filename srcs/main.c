/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:27:24 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/07/29 15:42:14 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	black_bg(t_params *para, int width)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < 25)
	{
		x = 0;
		while (x < width)
		{
			mlx_pixel_put(para->mlx, para->win, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void	print_nbr_on_bg(t_params *para)
{
	char	*nbr;

	nbr = ft_itoa(para->moves);
	black_bg(para, ft_strlen(nbr) * 10);
	mlx_string_put(para->mlx, para->win, 0, 0, 0xFFFFFF, nbr);
	free(nbr);
}

static void	process_keys(int key, t_params *para)
{
	int		check;

	check = 0;
	if (key == 53)
		ft_close(para);
	else if (key == 123)
		check = move_left(para);
	else if (key == 124)
		check = move_right(para);
	else if (key == 125)
		check = move_down(para);
	else if (key == 126)
		check = move_up(para);
	if (key >= 123 && key <= 126 && check == 0)
	{
		para->moves++;
		print_nbr_on_bg(para);
	}
}

static int	ft_key(int key, t_params *para)
{
	if (para->gg == 0)
	{
		process_keys(key, para);
		if (check_item(para, para->pl_x, para->pl_y))
			para->collected++;
		if (check_ex(para, para->pl_x, para->pl_y)
			&& para->collected == para->item_count)
			para->gg = 1;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_params	*para;

	if (argc != 2 || !check_ber(argv[1]))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	para = (t_params *)malloc(sizeof(t_params));
	if (!para)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	init_params(para);
	if (!check_map(para, argv) || !parse_map(para))
		error(para);
	init_and_start(para);
	print_nbr_on_bg(para);
	mlx_key_hook(para->win, ft_key, para);
	mlx_loop_hook(para->mlx, update, para);
	mlx_hook(para->win, 17, 0L, ft_close, para);
	mlx_loop(para->mlx);
	return (0);
}
