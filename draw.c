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

/*int		choose_pallet(int r, int g, int b, t_base *fract)
{
	int	pallet[3];

	if(fract->pallet == 1)
		return (r << 16 | g << 8 | b);
	else if(fract->pallet == 2)
		return (g << 16 | b << 8 | r);
	else if(fract->pallet == 3)
		return (b << 16 | r << 8 | g);
	else if(fract->pallet >= 4)
	{
		fract->pallet = 1;
		return (r << 16 | g << 8 | b);
	}
}*/

int		color(int iteration, int max_iteration, t_base *fract)
{
	double t;
	int red;
	int green;
	int blue;

	t = (double) iteration / max_iteration;

	red = (int) (9 * (1 - t) * t * t * t * 255) + fract->rgb.r;
	green = (int) (15 * (1 - t) * (1 - t) * t * t * 255) + fract->rgb.g;
	blue = (int) (8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255) + fract->rgb.b;
//	return (iteration < max_iteration) ? (red << 16 | green << 8 | blue) : 0;
	if(fract->pallet == 1)
		return (red << 16 | green << 8 | blue);
	else if(fract->pallet == 2)
		return (green << 16 | blue << 8 | red);
	else if(fract->pallet == 3)
		return (blue << 16 | red << 8 | green);
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
