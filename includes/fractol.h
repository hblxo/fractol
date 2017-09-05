/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 05:02:39 by hbouchet          #+#    #+#             */
/*   Updated: 2017/09/05 01:21:47 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <stdio.h>

# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000

typedef unsigned int	t_uint;

typedef struct			s_point
{
	double				min;
	double				max;
}						t_point;				

typedef struct			s_cplx
{
	double				re;
	double				im;
}						t_cplx;

typedef struct			s_env
{
	char				*title;
	void				*mlx;
	void				*win;
	void				*img;
	int					*data;
	int					size_line;
	int					bpp;
	int					endian;
	t_point				a;				
	t_point				b;
	int					iter_max;
}						t_env;

/*
** affichage
*/
void					ft_putpixel(t_env *img, int x, int y, t_uint color);
void					ft_clear_image(t_env *e, int color);

/*
** math
*/
t_cplx					cplx_mult(t_cplx a, t_cplx b);
t_cplx					cplx_add(t_cplx a, t_cplx b);

/*
** fractales
*/
void					mandelbrot(t_env *e);

/*
** controles
*/
int						key_hook(int keycode);
int						zoomlol(int keycode, int x, int y, t_env *e);

#endif
