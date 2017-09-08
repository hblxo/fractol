/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 22:02:17 by hbouchet          #+#    #+#             */
/*   Updated: 2017/09/08 04:28:16 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			init_mandelbrot(t_env *e)
{
	e->a.min = -1.5;
	e->a.max = 1;
	e->b.min = -1.5;
	e->b.max = 1;
	e->palette = 2;
	e->he = 0;
	e->mouse_c.x = 0.285;
	e->mouse_c.y = 0.01;
	return (0);
}

int			init_julia(t_env *e)
{
	e->a.min = -1;
	e->a.max = 1;
	e->b.min = -1;
	e->b.max = 1;
	e->mouse_c.x = 0.285;
	e->mouse_c.y = 0.01;
	e->palette = 3;
	e->he = 1;
	return (0);
}

int			init_burningship(t_env *e)
{
	e->a.min = -2;
	e->a.max = 1;
	e->b.min = -2;
	e->b.max = 1;
	e->palette = 1;
	e->he = 0;
	e->mouse_c.x = 0.285;
	e->mouse_c.y = 0.01;
	return (0);
}

int			init_roberte(t_env *e)
{
	e->a.min = -1.75;
	e->a.max = 1.75;
	e->b.min = -1.75;
	e->b.max = 1.75;
	e->mouse_c.x = -0.8;
	e->mouse_c.y = 0.018;
	e->palette = 4;
	e->he = 1;
	return (0);
}
