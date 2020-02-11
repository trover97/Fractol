/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:35:13 by wquirrel          #+#    #+#             */
/*   Updated: 2020/02/10 17:35:15 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void 			choose_f(t_base *fract)
{
	if(ft_strequ("Mandelbrot", fract->name))
		fract->fractal = 1;
	else if(ft_strequ("Julia", fract->name))
		fract->fractal = 2;
	else if(ft_strequ("Burning_Ship", fract->name))
		fract->fractal = 3;
	else
	{
		usage();
		exit(EXIT_FAILURE);
	}
}

void	usage()
{
	ft_putstr("Usage: ./fractol [fractal]\n");
	ft_putstr("1. Mandelbrot:\n2. Julia\n3. Burning_ship\n");
}

void	wtf(int x, int y, t_base *fract)
{
	t_complex factor;

	factor = init_complex((fract->max.re - fract->min.re) / (WIDTH - 1)
			, (fract->max.im - fract->min .im) / (HEIGHT - 1));
	fract->c.im = fract->max.im - y * factor.im + fract->shift_y;
	fract->c.re = fract->min.re + x * factor.re + fract->shift_x;
	if(fract->fractal == 1)
		mandelbrot(x, y, fract);
	else if(fract->fractal == 2)
		julia(x, y, fract);
//	else if(fract->fractal == 3)
//		burning_ship();
}