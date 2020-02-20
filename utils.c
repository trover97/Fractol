/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:35:13 by wquirrel          #+#    #+#             */
/*   Updated: 2020/02/18 14:10:46 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void 			choose_f(t_base *fract)
{
	if(ft_strequ("Mandelbrot", fract->name))
		fract->fractal = 1;
	else if(ft_strequ("Julia", fract->name))
		fract->fractal = 2;
	else if(ft_strequ("Burning_ship", fract->name))
		fract->fractal = 3;
	else if(ft_strequ("Mandelbar", fract->name))
		fract->fractal = 4;
	else if(ft_strequ("Douady_rabbit", fract->name))
		fract->fractal = 5;
	else if(ft_strequ("Biomorph", fract->name))
		fract->fractal = 6;
	else if(ft_strequ("P_mandelbrot", fract->name))
		fract->fractal = 7;
	else if(ft_strequ("B_julia", fract->name))
		fract->fractal = 8;
	else
	{
		usage();
		exit(EXIT_FAILURE);
	}
}

void	usage()
{
	ft_putstr("Usage: ./fractol [fractal]\n");
	ft_putstr("1. Mandelbrot\n2. Julia\n3. Burning_ship\n4. Mandelbar\n5. Douady_rabbit\n6. Biomorph 7.P_mandelbrot\n 8.B_julia");
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
	else if(fract->fractal == 3)
		burning_ship(x, y, fract);
	else if(fract->fractal == 4)
		mandelbar(x, y, fract);
	else if(fract->fractal == 5)
		douady_rabbit(x, y, fract);
	else if(fract->fractal == 6)
		biomorph(x, y, fract);
	else if(fract->fractal == 7)
		perpendicular_mandelbrot(x, y, fract);
	else if(fract->fractal == 8)
		burning_julia(x, y, fract);
}