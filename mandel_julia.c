/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:41:08 by wquirrel          #+#    #+#             */
/*   Updated: 2020/01/27 16:41:10 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julia_motion(int x, int y, t_base *fract)
{
	if(fract->is_pressed)
	{
		fract->k = init_complex(
				4 * ((double) x / WIDTH - 0.5),
				4 * ((double) (HEIGHT - y) / HEIGHT - 0.5));
		multip(fract);
	}
	return (0);
}

void 	mandelbrot(int x, int y, t_base *fract)
{
	t_complex z;

	z = init_complex(fract->c.re, fract->c.im);
	fract->iter.i = 0;
	while (z.re * z.re + z.im * z.im <= 4
		   && fract->iter.i < fract->iter.max_i)
	{
		z = init_complex(z.re * z.re - z.im * z.im + fract->c.re
				, 2.0 * z.re * z.im + fract->c.im);
		fract->iter.i++;
	}
	put_dot(x, y, fract->iter, fract);
}

void julia(int x, int y, t_base *fract)
{
	t_complex z;

	z = init_complex(fract->c.re,fract->c.im);
	fract->iter.i = 0;
	while (z.re * z.re + z.im * z.im <= 4
		   && fract->iter.i < fract->iter.max_i)
	{
		z = init_complex(
				z.re * z.re - z.im * z.im + fract->k.re,
				2.0 * z.re * z.im + fract->k.im);
		fract->iter.i++;
	}
	put_dot(x, y, fract->iter, fract);
}

void	perpendicular_mandelbrot(int x, int y, t_base *fract)
{
	t_complex z;

	z = init_complex(fract->c.re, fract->c.im);
	fract->iter.i = 0;
	while (z.re * z.re + z.im * z.im <= 4
		   && fract->iter.i < fract->iter.max_i)
	{
		z = init_complex(z.re * z.re - z.im * z.im + fract->c.re
				, -2.0 * fabs(z.re) * z.im + fract->c.im);
		fract->iter.i++;
	}
	put_dot(x, y, fract->iter, fract);
}
