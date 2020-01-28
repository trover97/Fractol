/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:46:52 by wquirrel          #+#    #+#             */
/*   Updated: 2020/01/27 16:46:54 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		color(int iteration, int max_iteration)
{
	double t;
	int red;
	int green;
	int blue;

	t = (double) iteration / (double) max_iteration;

	red = (int) (9 * (1 - t) * pow(t, 3) * 255);
	green = (int) (15 * pow((1 - t), 2) * pow(t, 2) * 255);
	blue = (int) (8.5 * pow((1 - t), 3) * t * 255);
	return (red << 16 | green << 8 | blue);
}


void		put_pixel(int x, int y, t_iter iter, t_base *base)
{
	int i;

	if(x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	i = y * WIDTH + x;
	base->img.data[i] = color(iter.i, iter.max_i);
	base->img.data[++i] = color(iter.i, iter.max_i) >> 8;
	base->img.data[++i] = color(iter.i, iter.max_i) >> 16;
}

void		draw(t_base *fract)
{
	int y;
	int x;
	t_iter iter;

	mlx_destroy_image(fract->mlx.mlx, fract->img.img_ptr);
	img_new(fract);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mandelbrot(x, y, fract);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx.mlx, fract->mlx.win, fract->img.img_ptr, 0, 0);
}