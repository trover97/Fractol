/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:22:14 by wquirrel          #+#    #+#             */
/*   Updated: 2020/02/25 16:35:06 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		check_mouse(int button, double *zoom, t_base *fract)
{
	if (button == MOUSE_SCROLL_DOWN)
	{
		fract->z--;
		*zoom = 1.15;
		fract->iter.max_i--;
	}
	else if (button == MOUSE_SCROLL_UP && fract->z < 250)
	{
		fract->z++;
		*zoom = 0.87;
		fract->iter.max_i++;
	}
	else if (button == MLB)
	{
		fract->is_pressed = 0;
		return(1);
	}
	else if (button == MRB)
	{
		fract->is_pressed = 1;
		return (1);
	}
	else
		return (1);
	return (0);
}

static double	inter(double s, double f, double zoom)
{
	double d;

	d = f - s;
	return (s + d * zoom);
}

void			zoom(int button, int x, int y, t_base *fract)
{
	t_complex	mouse;
	double		zoom;

	mouse = init_complex(
			(double)x / (WIDTH / (fract->max.re - fract->min.re))
			+ fract->min.re,
			(double)y / (HEIGHT / (fract->max.im - fract->min.im))
			* -1 + fract->max.im);
	if(check_mouse(button, &zoom, fract))
		return ;
	fract->min.re = inter(mouse.re, fract->min.re, zoom);
	fract->min.im = inter(mouse.im, fract->min.im, zoom);
	fract->max.re = inter(mouse.re, fract->max.re, zoom);
	fract->max.im = inter(mouse.im, fract->max.im, zoom);
	multip(fract);
}
