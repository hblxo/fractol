/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 22:39:27 by hbouchet          #+#    #+#             */
/*   Updated: 2017/09/08 04:31:39 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		exit_cross(t_env *e)
{
	(void)e;
	exit(0);
	return (0);
}

int		key_hook2(int keycode, t_env *e)
{
	if (keycode == KEY_RIGHT)
	{
		e->offset.x = -OFFSET;
		set_offset(e, 'x');
	}
	if (keycode == KEY_LEFT)
	{
		e->offset.x = OFFSET;
		set_offset(e, 'x');
	}
	if (keycode == KEY_UP)
	{
		e->offset.y = OFFSET;
		set_offset(e, 'y');
	}
	if (keycode == KEY_DOWN)
	{
		e->offset.y = -OFFSET;
		set_offset(e, 'y');
	}
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_C)
		e->palette++;
	if (keycode == KEY_ESCAPE)
		exit(0);
	if (keycode == KEY_PAGE_UP)
		e->iter_max++;
	if (keycode == KEY_SPACEBAR && (!ft_strcmp(ft_strtolower(e->title), "julia")
						|| (!ft_strcmp(ft_strtolower(e->title), "roberte"))))
		e->he = (e->he == 0 ? 1 : 0);
	if (keycode == KEY_TAB)
	{
		e->choice = (e->choice < 4 ? e->choice + 1 : 1);
		fractolinit(e);
	}
	if (keycode == KEY_A)
		e->pow = (e->pow < 6 ? e->pow + 1 : 2);
	if (keycode == KEY_R)
		fractolinit(e);
	if (keycode == KEY_H)
		e->help = (e->help == 0 ? 1 : 0);
	key_hook2(keycode, e);
	return (0);
}

int		set_offset(t_env *e, int dir)
{
	t_point d;

	d.x = (e->a.max - e->a.min) / WIN_WIDTH;
	d.y = (e->b.max - e->b.min) / WIN_HEIGHT;
	if (dir == 'x')
	{
		e->a.min = e->a.min - d.x * e->offset.x;
		e->a.max = e->a.max - d.x * e->offset.x;
	}
	else
	{
		e->b.min = e->b.min - d.x * e->offset.y;
		e->b.max = e->b.max - d.x * e->offset.y;
	}
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
