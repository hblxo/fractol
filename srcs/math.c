/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 04:19:44 by hbouchet          #+#    #+#             */
/*   Updated: 2017/09/07 07:38:55 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cplx	cplx_mult(t_cplx a, t_cplx b)
{
	t_cplx	result;

	result.re = a.re * b.re - a.im * b.im;
	result.im = a.im * b.re + a.re * b.im;
	return (result);
}

t_cplx	cplx_mult_abs(t_cplx a, t_cplx b)
{
	t_cplx	result;

	result.re = fabs(a.re) * fabs(b.re) - fabs(a.im) * fabs(b.im);
	result.im = fabs(a.im) * fabs(b.re) + fabs(a.re) * fabs(b.im);
	return (result);
}

t_cplx	cplx_add(t_cplx a, t_cplx b)
{
	t_cplx	result;

	result.re = a.re + b.re;
	result.im = a.im + b.im;
	return (result);
}
