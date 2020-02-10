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
//	mlx_destroy_image(fract->mlx.mlx, fract->img.img_ptr);
//	img_new(fract);
//
	if(keycode == ESC)
		exit(0);
/*	else if(keycode == ARROW_UP)
		fract->c.im -= SHIFT;
	else if(keycode == ARROW_DOWN)
		fract->c.im += SHIFT;
	else if(keycode == ARROW_LEFT)
		fract->c.re += SHIFT;
	else if(keycode == ARROW_RIGHT)
		fract->c.re -= SHIFT;*/
	else if(keycode == ARROW_UP)
		fract->shift_y -= (fract->max.re - fract->min.re) / 100;
	else if(keycode == ARROW_DOWN)
		fract->shift_y += (fract->max.re - fract->min.re) / 100;
	else if(keycode == ARROW_LEFT)
		fract->shift_x += (fract->max.re - fract->min.re) / 100;
	else if(keycode == ARROW_RIGHT)
		fract->shift_x -= (fract->max.re - fract->min.re) / 100;
	multip(fract);
//	draw(fract);
}