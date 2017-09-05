/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 05:18:06 by hbouchet          #+#    #+#             */
/*   Updated: 2017/09/05 03:31:17 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putpixel(t_env *img, int x, int y, t_uint color)
{
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
		img->data[x + y * WIN_WIDTH] = color;
}

void	ft_clear_image(t_env *e, int color)
{
	int i;

	i = 0;
	while (i < e->size_line / 4 * WIN_HEIGHT)
	{
		e->data[i] = color;
		i++;
	}
}
