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
	fract->k = init_complex(
			4 * ((double)x / WIDTH - 0.5),
			4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
	draw(fract);
	return (0);
}

void 	mandelbrot(int x, int y, t_base *fract)
{
	t_complex z;
	t_complex factor;
	t_complex c;

	fract->min = init_complex(fract->min.re + fract->shift_x, fract->min.im + fract->shift_y);
	fract->max.re += fract->shift_x;
	fract->max.im += fract->shift_y;
	factor = init_complex((fract->max.re - fract->min.re) / (WIDTH - 1)
			, (fract->max.im - fract->min .im) / (HEIGHT - 1));
	fract->iter.max_i = 50;
	c.im = fract->max.im - y * factor.im;
	c.re = fract->min.re + x * factor.re;
	z = init_complex(c.re, c.im);
	fract->iter.i = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		   && fract->iter.i < fract->iter.max_i)
	{
		z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + c.re
				, 2.0 * z.re * z.im + c.im);
		fract->iter.i++;
	}
	put_pixel(x, y, fract->iter, fract);
}

void julia(int x, int y, t_base *fract)
{
	t_complex z;
	t_complex factor;
	t_complex c;

	fract->min = init_complex(fract->min.re + fract->shift_x, fract->min.im + fract->shift_y);
	fract->max.re += fract->shift_x;
	fract->max.im += fract->shift_y;
	factor = init_complex((fract->max.re - fract->min.re) / (WIDTH - 1)
			, (fract->max.im - fract->min .im) / (HEIGHT - 1));
	fract->iter.max_i = 50;
	c.im = fract->max.im - y * factor.im;
	c.re = fract->min.re + x * factor.re;
	z = init_complex(c.re, c.im);
	fract->iter.i = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		   && fract->iter.i < fract->iter.max_i)
	{
		z = init_complex(
				pow(z.re, 2.0) - pow(z.im, 2.0) + fract->k.re,
				2.0 * z.re * z.im + fract->k.im);
		fract->iter.i++;
	}
	put_pixel(x, y, fract->iter, fract);
}

/*
void julia(int x, int y, t_base *fract)
{
	t_complex factor;
	t_complex c;
	t_complex z;
//	t_complex k;
	int i;

	fract->min = init_complex(fract->min.re + fract->shift_x, fract->min.im + fract->shift_y);
	fract->max.re += fract->shift_x;
	fract->max.im += fract->shift_y;
	factor = init_complex((fract->max.re - fract->min.re) / (WIDTH - 1)
			, (fract->max.im - fract->min .im) / (HEIGHT - 1));
	fract->iter.max_i = 50;
	c.im = fract->max.im - y * factor.im;
	c.re = fract->min.re + x * factor.re;
//	k = init_complex(-0.4, 0.6);
//	k = init_complex(4 * ((double) x / WIDTH - 0.5)
//			, 4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
	z = init_complex(c.re, c.im);
	i = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4	&& i < fract->iter.max_i)
	{
		z = init_complex(
				pow(z.re, 2.0) - pow(z.im, 2.0) + fract->k.re,
				2.0 * z.re * z.im + fract->k.im);
		i++;
	}
	put_pixel(x, y, fract->iter, fract);
}*/
