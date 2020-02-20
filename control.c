/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:58:40 by wquirrel          #+#    #+#             */
/*   Updated: 2020/01/28 14:58:41 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double 	inter(double s, double f, double zoom)
{
	double d;
	d = f - s;
	return (s + d * zoom);
}

void	zoom(int button ,int x, int y, t_base *fract)
{
	t_complex mouse;

	double zoom;
	mouse = init_complex(
			(double)x / (WIDTH / (fract->max.re - fract->min.re))
			+ fract->min.re,
			(double)y / (HEIGHT / (fract->max.im - fract->min.im))
			* -1 + fract->max.im);
	if (button == MOUSE_SCROLL_DOWN)
	{
		fract->z--;
		zoom = 1.15;
		fract->iter.max_i--;
	}
	else if(button == MOUSE_SCROLL_UP && fract->z < 250)
	{
		fract->z++;
		zoom = 0.87;
		fract->iter.max_i++;
	}
	else if(button == MLB)
	{
		fract->is_pressed = 0;
		return ;
	}
	else if(button == MRB)
	{
		fract->is_pressed = 1;
		return ;
	}
	else
		return;
	fract->min.re = inter(mouse.re, fract->min.re, zoom);
	fract->min.im = inter(mouse.im, fract->min.im, zoom);
	fract->max.re = inter(mouse.re, fract->max.re, zoom);
	fract->max.im = inter(mouse.im, fract->max.im, zoom);
	multip(fract);
}

int key_press(int keycode, t_base *fract)
{
	if(keycode == ESC)
		exit(0);
	else if(keycode == ARROW_UP)
		fract->shift_y -= fabs((fract->max.re - fract->min.re) / 100);
	else if(keycode == ARROW_DOWN)
		fract->shift_y += fabs((fract->max.re - fract->min.re) / 100);
	else if(keycode == ARROW_LEFT)
		fract->shift_x += fabs((fract->max.re - fract->min.re) / 100);
	else if(keycode == ARROW_RIGHT)
		fract->shift_x -= fabs((fract->max.re - fract->min.re) / 100);
	else if(keycode == NUM_PAD_MINUS)
	{
		fract->iter.max_i--;
		if(fract->iter.max_i < 1)
			fract->iter.max_i = 1;
	}
	else if(keycode == NUM_PAD_PLUS)
	{
		fract->iter.max_i++;
		if(fract->iter.max_i > 400)
			fract->iter.max_i = 400;
	}
	else if(keycode == R)
		fract->rgb.r += 1;
	else if(keycode == G)
		fract->rgb.g += 1;
	else if(keycode == B)
		fract->rgb.b += 1;
	else if(keycode == MAIN_PAD_PLUS)
	{
		fract->pallet += 1;
		if(fract->pallet >= 4)
			fract->pallet = 1;
	}
	else if(keycode == MAIN_PAD_MINUS)
	{
		fract->pallet -= 1;
		if(fract->pallet <= 0)
			fract->pallet = 1;
	}
	else if(keycode == NUM_PAD_0)
		init_f(fract);
	else if(keycode == F1)
	{
		fract->f1_pressed *= -1;
	}
	multip(fract);
	return(0);
}
