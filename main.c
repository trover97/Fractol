/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:43:37 by wquirrel          #+#    #+#             */
/*   Updated: 2020/01/24 15:43:39 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init(t_base *base)
{
	base->mlx.mlx = mlx_init();
	base->mlx.win = mlx_new_window(base->mlx.mlx, WIDTH, HEIGHT, "Fractol");
	base->img.img_ptr = mlx_new_image(base->mlx.mlx, WIDTH, HEIGHT);
	base->img.data = (int *)mlx_get_data_addr(base->img.img_ptr
			, &base->img.bpp, &base->img.size_l, &base->img.endian);
}

int main()
{
	t_base fract;


	init(&fract);
	mandelbrot(fract);

	mlx_loop(fract.mlx.mlx);
	return 0;
}
