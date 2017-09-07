/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 05:04:53 by hbouchet          #+#    #+#             */
/*   Updated: 2017/09/07 06:44:07 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractolinit(t_env *e)
{
	e->a.min = -1;
	e->a.max = 1;
	e->b.min = -1;
	e->b.max = 1;
	e->mouse_c.x = 0.285;
	e->mouse_c.y = 0.01;
	e->palette = 0;
	e->he = 0;	
	e->iter_max = 80;
}

int		drw(t_env *e)
{
	ft_clear_image(e, 0);
	if (fractolselect(e->title) == 1)
		julia(e);
	else if (fractolselect(e->title) == 2)
		mandelbrot(e);
	else
	{
		write(2, "lol\n", 4);
		exit (0);
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		fractolselect(char *str)
{
	if (!ft_strcmp(ft_strtolower(str), "julia"))
		return (1);
	else if (!ft_strcmp(ft_strtolower(str), "mandelbrot"))
		return (2);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac == 2)
	{
		e.title = ft_strdup(av[1]);
		fractolinit(&e);
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, e.title);
		e.img = mlx_new_image(e.mlx, WIN_WIDTH, WIN_HEIGHT);
		e.data = (int *)mlx_get_data_addr(e.img, &e.bpp, &e.size_line, &e.endian);
		mlx_hook(e.win, 6, 3, ehloljulia, &e);
		mlx_hook(e.win, 2, 0, key_hook, &e);
		mlx_mouse_hook(e.win, zoomlol, &e);
		mlx_loop_hook(e.mlx, drw, &e);
		mlx_loop(e.mlx);
	}
	else 
	{
		write(2, "usage : ./fractol fractalname\n", 30);
		return (0);
	}
	return (0);
}
