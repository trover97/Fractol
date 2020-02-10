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

#include "fractol.h";

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
	ft_putstr("Usage:");
	ft_putstr("1. Mandelbrot:\n2. Julia\n3. Burning_ship");
}

void	wtf(int x, int y, t_base *fract)
{
	if(fract->fractal == 1)
		mandelbrot(x, y, fract);
//	else if(fract->fractal == 2)
//		julia(x, y, fract);
//	else if(fract->fractal == 3)
//		burning_ship();
}