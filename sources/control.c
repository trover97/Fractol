/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:58:40 by wquirrel          #+#    #+#             */
/*   Updated: 2020/02/25 15:26:19 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	key_press3(int keycode, t_base *fract)
{
	if (keycode == F1)
		fract->f1_pressed *= -1;
	else if (keycode == M)
		fract->m_color = fract->m_color == BLACK ? WHITE : BLACK;
	else if (keycode == MAIN_PAD_PLUS)
	{
		fract->pallet += 1;
		if (fract->pallet >= 4)
			fract->pallet = 1;
	}
	else if (keycode == MAIN_PAD_MINUS)
	{
		fract->pallet -= 1;
		if (fract->pallet <= 0)
			fract->pallet = 1;
	}
}

static void	key_press2(int keycode, t_base *fract)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == R)
	{
		fract->rgb.r += 1;
		if (fract->rgb.r > 16)
			fract->rgb.r = 0;
	}
	else if (keycode == G)
	{
		fract->rgb.g += 1;
		if (fract->rgb.g > 16)
			fract->rgb.g = 0;
	}
	else if (keycode == B)
	{
		fract->rgb.b += 1;
		if (fract->rgb.b > 16)
			fract->rgb.b = 0;
	}
}

static void	key_press1(int keycode, t_base *fract)
{
	if (keycode == MAIN_PAD_1 || keycode == MAIN_PAD_2 || keycode == MAIN_PAD_3
	|| keycode == MAIN_PAD_4 || keycode == MAIN_PAD_5 || keycode == MAIN_PAD_6
	|| keycode == MAIN_PAD_7 || keycode == MAIN_PAD_8)
	{
		if (keycode == MAIN_PAD_1)
			fract->fractal = 1;
		else if (keycode == MAIN_PAD_2)
			fract->fractal = 2;
		else if (keycode == MAIN_PAD_3)
			fract->fractal = 3;
		else if (keycode == MAIN_PAD_4)
			fract->fractal = 4;
		else if (keycode == MAIN_PAD_5)
			fract->fractal = 5;
		else if (keycode == MAIN_PAD_6)
			fract->fractal = 6;
		else if (keycode == MAIN_PAD_7)
			fract->fractal = 7;
		else
			fract->fractal = 8;
		init_f(fract);
	}
	else if (keycode == NUM_PAD_0)
		init_f(fract);
}

int			key_press(int keycode, t_base *fract)
{
	if (keycode == ARROW_UP)
		fract->shift_y -= fabs((fract->max.re - fract->min.re) / 100);
	else if (keycode == ARROW_DOWN)
		fract->shift_y += fabs((fract->max.re - fract->min.re) / 100);
	else if (keycode == ARROW_LEFT)
		fract->shift_x += fabs((fract->max.re - fract->min.re) / 100);
	else if (keycode == ARROW_RIGHT)
		fract->shift_x -= fabs((fract->max.re - fract->min.re) / 100);
	else if (keycode == NUM_PAD_MINUS)
	{
		fract->iter.max_i--;
		if (fract->iter.max_i < 1)
			fract->iter.max_i = 1;
	}
	else if (keycode == NUM_PAD_PLUS)
	{
		fract->iter.max_i++;
		if (fract->iter.max_i > 400)
			fract->iter.max_i = 400;
	}
	key_press1(keycode, fract);
	key_press2(keycode, fract);
	key_press3(keycode, fract);
	multip(fract);
	return (0);
}
