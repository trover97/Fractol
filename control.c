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
		if(fract->iter.max_i > 500)
			fract->iter.max_i = 500;
	}
	else if(keycode == R)
		fract->rgb.r += 5;
	else if(keycode == G)
		fract->rgb.g += 5;
	else if(keycode == B)
		fract->rgb.b += 5;
	multip(fract);
}
