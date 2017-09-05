/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 05:04:53 by hbouchet          #+#    #+#             */
/*   Updated: 2017/09/05 04:04:19 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>//rrr

void	mandelbrot(t_env *e)
{
	int		i = 0;
	int		x = 0;
	int		y = 0;
	t_cplx	z = {0, 0};
	t_cplx	c;

	e->iter_max = 255;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			i = 0;
			z = (t_cplx){0, 0};
			c = (t_cplx){(double)x / (double)WIN_WIDTH * (e->a.max - e->a.min) + e->a.min,
						 (double)y / (double)WIN_HEIGHT * (e->b.max - e->b.min) + e->b.min};
			while (i < e->iter_max && (z.re * z.re + z.im * z.im) <= 4)
			{
				z = cplx_add(cplx_mult(z, z), c); 
				i++;
			}
			if (i < e->iter_max)
				ft_putpixel(e, x, y, i);
			x++;
		}
		y++;
	}
}

int		drw(t_env *e)
{
//	mlx_destroy_image(e->mlx, e->img);
//	e->img = mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGHT);
//	mlx_clear_window(e->mlx, e->win);
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
//	mandelbrot(&e, e.min, e.max);
	mlx_mouse_hook(e.win, zoomlol, &e);
	mlx_hook(e.win, 2, 0, key_hook, &e);
	mlx_loop_hook(e.mlx, drw, &e);
//	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	mlx_loop(e.mlx);
	return (0);
}
