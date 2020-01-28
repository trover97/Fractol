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

void 	mandelbrot(int x, int y, t_base *fract)
{
//	int x;
//	int y;
//	t_iter iter;
	t_complex z;
//	t_complex min;
//	t_complex max;
	t_complex factor;
	t_complex c;

	fract->min = init_complex(-2.0 + fract->shift_x, -2.0 + fract->shift_y);
	fract->max.re = 2.0 + fract->shift_x;
	fract->max.im = fract->min.im + (fract->max.re - fract->min.re) * HEIGHT / WIDTH + fract->shift_y;
	factor = init_complex((fract->max.re - fract->min.re) / (WIDTH - 1)
			, (fract->max.im - fract->min .im) / (HEIGHT - 1));

	fract->iter.max_i = 50;

//	y = 0;
//	while (y < HEIGHT)
//	{
		c.im = fract->max.im - y * factor.im;
//		x = 0;
//		while (x < WIDTH)
//		{
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
//			x++;
//		}
//		y++;
//	}
}