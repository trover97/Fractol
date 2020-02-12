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

int		color(int iteration, int max_iteration, t_base *fract)
{
	double t;
	int red;
	int green;
	int blue;

	t = (double) iteration / max_iteration;

	red = (int) (9 * (1 - t) * pow(t, 3) * 255) + fract->rgb.r;
	green = (int) (15 * pow((1 - t), 2) * pow(t, 2) * 255) + fract->rgb.g;
	blue = (int) (8.5 * pow((1 - t), 3) * t * 255) + fract->rgb.b;
	return (iteration < max_iteration) ? (red << 16 | green << 8 | blue) : 0;
}


void		put_dot(int x, int y, t_iter iter, t_base *fract)
{
	int i;
	int c;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	i = y * WIDTH + x;
	c = color(iter.i, iter.max_i, fract);
	fract->img.data[i] = c;
	fract->img.data[++i] = c >> 8;
	fract->img.data[++i] = c >> 16;
}

/*
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
//			julia(x, y, fract);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx.mlx, fract->mlx.win, fract->img.img_ptr, 0, 0);
}*/
