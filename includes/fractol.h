/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 05:02:39 by hbouchet          #+#    #+#             */
/*   Updated: 2017/09/07 07:01:13 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <stdio.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 800

typedef unsigned int	t_uint;

typedef struct			s_point
{
	double				x;
	double				y;
}						t_point;				

typedef struct			s_range
{
	double				min;
	double				max;
}						t_range;				

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
	t_range				a;				
	t_range				b;
	t_point				mouse_c;
	int					iter_max;
	int					palette;
	int					he;
	int					choice;
}						t_env;

void					fractolinit(t_env *e);

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
int						fractolselect(char *str);
void					mandelbrot(t_env *e);
void					julia(t_env *e);

/*
** controles
*/
int						key_hook(int keycode, t_env *e);
int						zoomlol(int keycode, int x, int y, t_env *e);
int						ehloljulia(int x, int y, t_env *e);

/*
** couleurs
*/
int						get_color(t_env *e, int i);
int						set_color(int r, int g, int b);

#endif
