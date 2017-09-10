/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 05:04:53 by hbouchet          #+#    #+#             */
/*   Updated: 2017/09/10 22:02:53 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ehloljulia(int x, int y, t_env *e)
{
	t_point d;

	if (e->he == 1)
	{
		d.x = (e->a.max - e->a.min) / WIN_WIDTH;
		d.y = (e->b.max - e->b.min) / WIN_HEIGHT;
		e->mouse_c.x = (double)x * d.x + e->a.min;
		e->mouse_c.y = (double)y * d.y + e->b.min;
	}
	return (0);
}

void	fractolinit(t_env *e)
{
	if (e->choice == 1)
		init_julia(e);
	if (e->choice == 2)
		init_mandelbrot(e);
	if (e->choice == 3)
		init_burningship(e);
	if (e->choice == 4)
		init_roberte(e);
	e->iter_max = 80;
	e->help = 0;
	e->pow = 2;
}

int		drw(t_env *e)
{
	ft_clear_image(e, 0);
	if (e->choice == 1)
		julia(e);
	else if (e->choice == 2)
		mandelbrot(e);
	else if (e->choice == 3)
		burningship(e);
	else if (e->choice == 4)
		roberte(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	if (e->help == 1)
		print_help(e);
	return (0);
}

int		fractolselect(char *str)
{
	char	*usage;

	usage = "usage : ./fractol {mandelbrot, julia, burningship, roberte}\n";
	if (!ft_strcmp(ft_strtolower(str), "julia"))
		return (1);
	else if (!ft_strcmp(ft_strtolower(str), "mandelbrot"))
		return (2);
	else if (!ft_strcmp(ft_strtolower(str), "burningship"))
		return (3);
	else if (!ft_strcmp(ft_strtolower(str), "roberte"))
		return (4);
	else
	{
		write(2, usage, 60);
		exit(0);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac == 2)
	{
		e.title = ft_strdup(av[1]);
		e.choice = fractolselect(e.title);
		fractolinit(&e);
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
		e.img = mlx_new_image(e.mlx, WIN_WIDTH, WIN_HEIGHT);
		e.data = (int *)mlx_get_data_addr(e.img, &e.bpp,
										&e.size_line, &e.endian);
		mlx_hook(e.win, 6, 3, ehloljulia, &e);
		mlx_hook(e.win, 2, 0, key_hook, &e);
		mlx_hook(e.win, 17, (1L << 17), exit_cross, &e);
		mlx_mouse_hook(e.win, zoomlol, &e);
		mlx_expose_hook(e.win, drw, &e);
		mlx_loop_hook(e.mlx, drw, &e);
		mlx_loop(e.mlx);
	}
	else
		write(2, "usage : ./fractol fractalname\n", 30);
	return (0);
}
