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
	zoom = 0;
		mouse = init_complex(
				(double)x / (WIDTH / (fract->max.re - fract->min.re))
				+ fract->min.re,
				(double)y / (HEIGHT / (fract->max.im - fract->min.im))
				* -1 + fract->max.im);
		if (button == MOUSE_SCROLL_DOWN)
			zoom = 1.2;
		else if(button == MOUSE_SCROLL_UP)
			zoom = 0.8;
		else
			return ;
		fract->min.re = inter(mouse.re, fract->min.re, zoom);
		fract->min.im = inter(mouse.im, fract->min.im, zoom);
		fract->max.re = inter(mouse.re, fract->max.re, zoom);
		fract->max.im = inter(mouse.im, fract->max.im, zoom);
		multip(fract);
}

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

void		init(t_base *fract)
{
	fract->mlx.mlx = mlx_init();
	fract->mlx.win = mlx_new_window(fract->mlx.mlx, WIDTH, HEIGHT, "Fractol");
	fract->img.img_ptr = mlx_new_image(fract->mlx.mlx, WIDTH, HEIGHT);
	fract->img.data = (int *)mlx_get_data_addr(fract->img.img_ptr
			, &fract->img.bpp, &fract->img.size_l, &fract->img.endian);
	fract->shift_y = 0;
	fract->shift_x = 0;
//	fract->zoom_re = 0;
//	fract->zoom_im = 0;
	fract->min = init_complex(-2.0, -2.0);
	fract->max.re = 2.0;
	fract->max.im = fract->min.im + (fract->max.re - fract->min.re) * HEIGHT / WIDTH;
	fract->iter.i = 0;
	fract->k = init_complex(-0.4, 0.6);
}

int main()
{
	t_base fract;


	init(&fract);
//	mandelbrot(&fract);
//	draw(&fract);
	multip(&fract);

	mlx_hook(fract.mlx.win, 2, 0, key_press, &fract);
	mlx_mouse_hook(fract.mlx.win, julia_motion, &fract);
	mlx_mouse_hook(fract.mlx.win, zoom, &fract);
//	mlx_hook(fract.mlx.win, 5, 0, mouse_release, &fract);
//	mlx_hook(fract.mlx.win, 6, 0, mouse_move, &fract);
	mlx_hook(fract.mlx.win, 17, 0, hook_exit, fract.mlx.mlx);
	mlx_loop(fract.mlx.mlx);
	return 0;
}
