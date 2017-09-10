/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 00:32:20 by hbouchet          #+#    #+#             */
/*   Updated: 2017/09/10 22:08:33 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_help(t_env *e)
{
	if (e->choice == 1)
		mlx_string_put(e->mlx, e->win, 10, 10, 0x00FFFFFF, "Julia");
	else if (e->choice == 2)
		mlx_string_put(e->mlx, e->win, 10, 10, 0x00FFFFFF, "Mandelbrot");
	else if (e->choice == 3)
		mlx_string_put(e->mlx, e->win, 10, 10, 0x00FFFFFF, "Burning Ship");
	else if (e->choice == 4)
		mlx_string_put(e->mlx, e->win, 10, 10, 0x00FFFFFF, "Roberte");
	mlx_string_put(e->mlx, e->win, 10, WIN_HEIGHT - 20, 0x00FFFFFF,
				"Quit : (esc)");
	mlx_string_put(e->mlx, e->win, 10, WIN_HEIGHT - 140, 0x00FFFFFF,
				"All these commands are available");
	mlx_string_put(e->mlx, e->win, 10, WIN_HEIGHT - 120, 0x00FFFFFF,
				"Choose color : (c)");
	mlx_string_put(e->mlx, e->win, 10, WIN_HEIGHT - 100, 0x00FFFFFF,
				"Change fractal : (tab)");
	mlx_string_put(e->mlx, e->win, 10, WIN_HEIGHT - 80, 0x00FFFFFF,
				"Add iterations : (space up)");
	if (e->choice == 1 || e->choice == 2)
		mlx_string_put(e->mlx, e->win, 10, WIN_HEIGHT - 60, 0x00FFFFFF,
				"Puissance : (a)");
	if (e->choice == 1 || e->choice == 4)
		mlx_string_put(e->mlx, e->win, 10, WIN_HEIGHT - 40, 0x00FFFFFF,
				"(un)lock lol & zoom : (space)");
}
