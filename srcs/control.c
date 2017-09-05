/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 22:39:27 by hbouchet          #+#    #+#             */
/*   Updated: 2017/09/05 05:16:28 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int		zoomlol(int keycode, int x, int y, t_env *e)
{
	t_point d;

	d.min = (e->a.max - e->a.min) / WIN_WIDTH;
	d.max = (e->b.max - e->b.min) / WIN_HEIGHT;
	x = x * d.min + e->a.min;
	y = y * d.max + e->b.min;
	if (keycode == 1)
	{
/*		e->a.min = x - ((x - e->a.min) * 0.9);
		e->a.max = x + ((e->a.max - x) * 0.9);
		e->b.min = y - ((y - e->b.min) * 0.9);
		e->b.max = y + ((e->b.max - y) * 0.9);*/
		e->a.min = x + ((e->a.min - x) * 0.9);
		e->a.max = x + ((e->a.max - x) * 0.9);
		e->b.min = y + ((e->b.min - y) * 0.9);
		e->b.max = y + ((e->b.max - y) * 0.9);
/*		e->a.min = e->a.min * 0.9;
		e->a.max = e->a.max * 0.9;
		e->b.min = e->b.min * 0.9;
		e->b.max = e->b.max * 0.9; */
	}
	if (keycode == 2)
	{
		e->a.min = x + ((e->a.min - x) / 0.9);
		e->a.max = x + ((e->a.max - x) / 0.9);
		e->b.min = y + ((e->b.min - y) / 0.9);
		e->b.max = y + ((e->b.max - y) / 0.9);
/*		e->a.min = x - ((x - e->a.min) / 0.9);
		e->a.max = x + ((e->a.max - x) / 0.9);
		e->b.min = y - ((y - e->b.min) / 0.9);
		e->b.max = y + ((e->b.max - y) / 0.9);
		e->a.min = e->a.min / 0.9;
		e->a.max = e->a.max / 0.9;
		e->b.min = e->b.min / 0.9;
		e->b.max = e->b.max / 0.9;*/
	}
	return (0);
}
