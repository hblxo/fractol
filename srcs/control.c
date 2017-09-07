/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 22:39:27 by hbouchet          #+#    #+#             */
/*   Updated: 2017/09/07 07:00:43 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // 
#include "fractol.h"

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 8)
		e->palette++;
	if (keycode == 53)
		exit(0);
	if (keycode == 116)
		e->iter_max++;
	if (keycode == 49)
	{
		if (e->he == 0)
			e->he = 1;
		else
			e->he = 0;
	}
	if (keycode == 15)
		fractolinit(e);
	return (0);
}

int		zoomlol(int keycode, int x, int y, t_env *e)
{
	t_point d;
	t_point p;

	d.x = (e->a.max - e->a.min) / WIN_WIDTH;
	d.y = (e->b.max - e->b.min) / WIN_HEIGHT;
	p.x = (double)x * d.x + e->a.min;
	p.y = (double)y * d.y + e->b.min;
	if (e->he == 0 && keycode == 5)
	{
		e->a.min = p.x + ((e->a.min - p.x) * 0.9);
		e->a.max = p.x + ((e->a.max - p.x) * 0.9);
		e->b.min = p.y + ((e->b.min - p.y) * 0.9);
		e->b.max = p.y + ((e->b.max - p.y) * 0.9);
	}
	if (e->he == 0 && keycode == 4)
	{
		e->a.min = p.x + ((e->a.min - p.x) / 0.9);
		e->a.max = p.x + ((e->a.max - p.x) / 0.9);
		e->b.min = p.y + ((e->b.min - p.y) / 0.9);
		e->b.max = p.y + ((e->b.max - p.y) / 0.9);
	}
	return (0);
}

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
