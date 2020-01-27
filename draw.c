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
	return (red + green + blue);
}


void		put_pixel(int x, int y, t_iter iter, t_base *base)
{
	if(x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
		base->img.data[y * WIDTH + x] = color(iter.i, iter.max_i);
}