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
	int c[3];

	t = (double) iteration / max_iteration;

	c[0] = (int) (9 * (1 - t) * t * t * t * 255);
	c[1] = (int) (15 * (1 - t) * (1 - t) * t * t * 255);
	c[2] = (int) (8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	if(fract->pallet == 1)
		return ((iteration < max_iteration) ? (c[0] << fract->rgb.r | c[1] << fract->rgb.g | c[2] << fract->rgb.b): 0);
	else if(fract->pallet == 2)
		return ((iteration < max_iteration) ? (c[1] << fract->rgb.r | c[2] << fract->rgb.g | c[0] << fract->rgb.b): 0);
	else if(fract->pallet == 3)
		return ((iteration < max_iteration) ? (c[2] << fract->rgb.r | c[0] << fract->rgb.g | c[1] << fract->rgb.b): 0);
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
