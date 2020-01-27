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

void 	mandelbrot(t_base base)
{
	int x;
	int y;
	t_iter iter;
	t_complex z;
	t_complex min;
	t_complex max;
	t_complex factor;
	t_complex c;

	min = init_complex(-2.0, -2.0);
	max.re = 2.0;
	max.im = min.im + (max.re - min.re) * HEIGHT / WIDTH;
	factor = init_complex((max.re - min.re) / (WIDTH - 1)
			, (max.im - min .im) / (HEIGHT - 1));

	iter.max_i = 50;

	y = 0;
	while (y < HEIGHT)
	{
		c.im = max.im - y * factor.im;
		x = 0;
		while (x < WIDTH)
		{
			c.re = min.re + x * factor.re;
			z = init_complex(c.re, c.im);
			iter.i = 0;
			while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
				   && iter.i < iter.max_i)
			{
				z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + c.re, 2.0 * z.re * z.im + c.im);
				iter.i++;
			}
			put_pixel(x, y, iter, &base);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(base.mlx.mlx, base.mlx.win, base.img.img_ptr, 0, 0);
}