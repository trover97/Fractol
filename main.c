/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:43:37 by wquirrel          #+#    #+#             */
/*   Updated: 2020/02/18 17:50:18 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_new(t_base *fract)
{
	fract->img.img_ptr = mlx_new_image(fract->mlx.mlx, WIDTH, HEIGHT);
	fract->img.data = (int *)mlx_get_data_addr(fract->img.img_ptr
			, &fract->img.bpp, &fract->img.size_l, &fract->img.endian);
}

int		hook_exit(void *param)
{
	(void)param;
	exit(0);
}

void		init_f(t_base *fract)
{
	fract->shift_y = 0;
	fract->shift_x = 0;
	fract->z = 1;
	fract->min = init_complex(-2.0, -2.0);
	fract->max.re = 2.0;
	fract->max.im = fract->min.im + (fract->max.re - fract->min.re) * HEIGHT / WIDTH;
	fract->iter.i = 0;
	fract->iter.max_i = 50;
	fract->k = init_complex(-0.4, 0.6);
	fract->is_pressed = 1;
	fract->f1_pressed = -1;
	fract->rgb.r = 16;
	fract->rgb.g = 8;
	fract->rgb.b = 0;
	fract->pallet = 1;
	fract->m_color = WHITE;
}

int main(int ac, char **av)
{
	t_base fract;

	if(ac != 2)
	{
		usage(ac);
		exit(EXIT_FAILURE);
	}
	fract.name = av[1];
	choose_f(&fract);
	fract.mlx.mlx = mlx_init();
	fract.mlx.win = mlx_new_window(fract.mlx.mlx, WIDTH, HEIGHT, "Fractol");
	init_f(&fract);
	img_new(&fract);
//	mandelbrot(&fract);
//	draw(&fract);
	multip(&fract);

	mlx_hook(fract.mlx.win, 2, 0, key_press, &fract);
	mlx_mouse_hook(fract.mlx.win, zoom, &fract);
	mlx_hook(fract.mlx.win, 6, 0, julia_motion, &fract);
//	mlx_mouse_hook(fract.mlx.win, julia_motion, &fract);
//	mlx_hook(fract.mlx.win, 5, 0, mouse_release, &fract);
//	mlx_hook(fract.mlx.win, 6, 0, mouse_move, &fract);
	mlx_hook(fract.mlx.win, 17, 0, hook_exit, fract.mlx.mlx);
	mlx_loop(fract.mlx.mlx);
	return 0;
}
