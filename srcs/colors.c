/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 04:46:56 by hbouchet          #+#    #+#             */
/*   Updated: 2017/09/07 04:46:58 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			get_color(t_env *e, int i)
{
	if (e->palette == 5)
		e->palette = 0;
	if (e->palette == 0)
		return (set_color(i * 80 / e->iter_max, i * 200 / e->iter_max, 50));
	if (e->palette == 1)
		return (set_color(i * 100 / e->iter_max + 150, i * 200 / e->iter_max + 20, i * 160 / e->iter_max + 5));
	if (e->palette == 2)
		return (set_color(50, i * 200 / e->iter_max, 70));
	if (e->palette == 3)
		return (set_color(i * 2, i * 5, i * 7));
	if (e->palette == 4)
		return (set_color(i * 240 / e->iter_max + 50, i * i, 75));
	else
		return (set_color(i, i, i));
}

int			set_color(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}
