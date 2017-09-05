/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 05:04:53 by hbouchet          #+#    #+#             */
/*   Updated: 2017/09/05 06:28:55 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		drw(t_env *e)
{
	ft_clear_image(e, 0);
	mandelbrot(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac == 2)
		av[1] = "lol";
	e.title = "lol";
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, e.title);
	e.img = mlx_new_image(e.mlx, WIN_WIDTH, WIN_HEIGHT);
	e.data = (int *)mlx_get_data_addr(e.img, &e.bpp, &e.size_line, &e.endian);
	e.a.min = -2;
	e.a.max = 1;
	e.b.min = -2;
	e.b.max = 1;
	mlx_mouse_hook(e.win, zoomlol, &e);
	mlx_hook(e.win, 2, 0, key_hook, &e);
	mlx_loop_hook(e.mlx, drw, &e);
	mlx_loop(e.mlx);
	return (0);
}
