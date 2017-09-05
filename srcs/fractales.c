/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 05:04:53 by hbouchet          #+#    #+#             */
/*   Updated: 2017/09/05 06:35:37 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_env *e)
{
	int		i;
	int		x;
	int		y;
	t_cplx	z;
	t_cplx	c;

	y = -1;
	e->iter_max = 255;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			i = -1;
			z = (t_cplx){0, 0};
			c = (t_cplx){(double)x / (double)WIN_WIDTH * (e->a.max - e->a.min)
						+ e->a.min, (double)y / (double)WIN_HEIGHT
						* (e->b.max - e->b.min) + e->b.min};
			while (++i < e->iter_max && (z.re * z.re + z.im * z.im) <= 4)
				z = cplx_add(cplx_mult(z, z), c);
			if (i < e->iter_max)
				ft_putpixel(e, x, y, i);
		}
	}
}

void	julia(t_env *e)
{
	int		i;
	int		x;
	int		y;
	t_cplx	z;
	t_cplx	c;

	y = -1;
	e->iter_max = 255;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			i = -1;
			z = (t_cplx){0, 0};
			c = (t_cplx){(double)x / (double)WIN_WIDTH * (e->a.max - e->a.min)
						+ e->a.min, (double)y / (double)WIN_HEIGHT
						* (e->b.max - e->b.min) + e->b.min};
			while (++i < e->iter_max && (z.re * z.re + z.im * z.im) <= 4)
				z = cplx_add(cplx_mult(z, z), c);
			if (i < e->iter_max)
				ft_putpixel(e, x, y, i);
		}
	}
}
