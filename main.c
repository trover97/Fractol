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

void	zoom(int button ,int x, int y, t_base *fract)
{
//	t_complex mouse;
//	double zoom;
	double dr;
	double di;
//	double zoom_re;
//	double zoom_im;

	dr = fract->max.re - fract->min.re;
	di = fract->max.im - fract->min.im;
	fract->zoom_re = ((double)x / WIDTH * dr) - dr / 2 + fract->zoom_re;
	fract->zoom_im = ((double)y / HEIGHT * di) - di / 2 + fract->zoom_im;
	if(x >= 0 && x <= WIDTH)
	{
		if(button == MOUSE_SCROLL_UP)
		{
			fract->max.re = fract->zoom_re + (dr / 1.3) / 2;
			fract->min.re = fract->zoom_re - (dr / 1.3) / 2;
			fract->max.im = fract->zoom_im + (dr / 1.3) / 2;
			fract->min.im = fract->zoom_im - (dr / 1.3) / 2;
		}
		else
		{
			fract->max.re = fract->zoom_re + (dr * 1.3) / 2;
			fract->min.re = fract->zoom_re - (dr * 1.3) / 2;
			fract->max.im = fract->zoom_im + (dr * 1.3) / 2;
			fract->min.im = fract->zoom_im - (dr * 1.3) / 2;
		}
	}

//	if (button == MOUSE_SCROLL_DOWN || MOUSE_SCROLL_UP)
//	{
//		mouse = init_complex(
//				(double)x / (WIDTH / (fract->max.re - fract->min.re))
//				+ fract->min.re,
//				(double)y / (HEIGHT / (fract->max.im - fract->min.im))
//				* -1 + fract->max.im);
//		if (button == MOUSE_SCROLL_UP)
//			zoom = 0.80;
//		else
//			zoom = 1.20;
//		draw(fract);
//	}
	draw(fract);
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
	fract->zoom_re = 0;
	fract->zoom_im = 0;
}

int main()
{
	t_base fract;


	init(&fract);
//	mandelbrot(&fract);
	draw(&fract);

	mlx_hook(fract.mlx.win, 2, 0, key_press, &fract);
	mlx_mouse_hook(fract.mlx.win, zoom, &fract);
//	mlx_hook(fract.mlx.win, 5, 0, mouse_release, &fract);
//	mlx_hook(fract.mlx.win, 6, 0, mouse_move, &fract);
	mlx_hook(fract.mlx.win, 17, 0, hook_exit, fract.mlx.mlx);
	mlx_loop(fract.mlx.mlx);
	return 0;
}
