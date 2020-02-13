/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:59:50 by wquirrel          #+#    #+#             */
/*   Updated: 2020/02/13 16:59:58 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burning_ship(int x, int y, t_base *fract)
{
	t_complex z;

	z = init_complex(fract->c.re,fract->c.im);
	fract->iter.i = 0;
	while (z.re * z.re + z.im * z.im <= 4
		   && fract->iter.i < fract->iter.max_i)
	{
		z = init_complex(
				z.re * z.re - z.im * z.im + fract->c.re,
				-2.0 * fabs(z.re * z.im) + fract->c.im);
		fract->iter.i++;
	}
	put_dot(x, y, fract->iter, fract);
}

void	kochCurve(int x, int y, t_base *fract)
{

}