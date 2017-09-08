/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 13:06:24 by hbouchet          #+#    #+#             */
/*   Updated: 2017/09/07 23:55:33 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_env *e)
{
	int		i;
	t_point	w;
	t_cplx	z;
	t_cplx	c;

	w.y = -1;
	while (++w.y < WIN_HEIGHT)
	{
		w.x = -1;
		while (++w.x - e->offset.x < WIN_WIDTH + e->offset.x)
		{
			i = -1;
			z = (t_cplx){0, 0};
			c = (t_cplx){w.x / (double)WIN_WIDTH * (e->a.max - e->a.min)
						+ e->a.min, w.y / (double)WIN_HEIGHT
						* (e->b.max - e->b.min) + e->b.min};
			while (++i < e->iter_max && (z.re * z.re + z.im * z.im) <= 4)
				z = cplx_add(cplx_mult_p(z, e->pow), c);
			if (i < e->iter_max)
				ft_putpixel(e, w.x - e->offset.x, w.y, get_color(e, i));
		}
	}
}

void	burningship(t_env *e)
{
	int		i;
	t_point	w;
	t_cplx	z;
	t_cplx	c;

	w.y = -1;
	while (++w.y < WIN_HEIGHT)
	{
		w.x = -1;
		while (++w.x < WIN_WIDTH)
		{
			i = -1;
			z = (t_cplx){0, 0};
			c = (t_cplx){w.x / (double)WIN_WIDTH * (e->a.max - e->a.min)
						+ e->a.min, w.y / (double)WIN_HEIGHT
						* (e->b.max - e->b.min) + e->b.min};
			while (++i < e->iter_max && (z.re * z.re + z.im * z.im) <= 4)
				z = cplx_add(cplx_mult_abs(z, z), c);
			if (i < e->iter_max)
				ft_putpixel(e, w.x, w.y, get_color(e, i));
		}
	}
}

void	julia(t_env *e)
{
	int		i;
	t_point	w;
	t_cplx	z;
	t_cplx	c;

	w.y = -1;
	while (++w.y < WIN_HEIGHT)
	{
		w.x = -1;
		while (++w.x < WIN_WIDTH)
		{
			i = -1;
			c = (t_cplx){e->mouse_c.x, e->mouse_c.y};
			z = (t_cplx){w.x / (double)WIN_WIDTH * (e->a.max - e->a.min)
						+ e->a.min, w.y / (double)WIN_HEIGHT
						* (e->b.max - e->b.min) + e->b.min};
			while (++i < e->iter_max && (z.re * z.re + z.im * z.im) <= 4)
				z = cplx_add(cplx_mult_p(z, e->pow), c);
			if (i == e->iter_max)
				ft_putpixel(e, w.x, w.y, 0x000000);
			if (i < e->iter_max)
				ft_putpixel(e, w.x, w.y, get_color(e, i));
		}
	}
}

void	roberte(t_env *e)
{
	int		i;
	t_point	w;
	t_cplx	z;
	t_cplx	c;

	w.y = -1;
	while (++w.y < WIN_HEIGHT)
	{
		w.x = -1;
		while (++w.x < WIN_WIDTH)
		{
			i = -1;
			c = (t_cplx){e->mouse_c.x, e->mouse_c.y};
			z = (t_cplx){w.x / (double)WIN_WIDTH * (e->a.max - e->a.min)
						+ e->a.min, w.y / (double)WIN_HEIGHT
						* (e->b.max - e->b.min) + e->b.min};
			while (++i < e->iter_max && (z.re * z.re + z.im * z.im) <= 4)
				z = cplx_add(cplx_mult_abs(z, z), c);
			if (i == e->iter_max)
				ft_putpixel(e, w.x, w.y, 0x000000);
			if (i < e->iter_max)
				ft_putpixel(e, w.x, w.y, get_color(e, i));
		}
	}
}
