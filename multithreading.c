/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithreading.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:16:36 by wquirrel          #+#    #+#             */
/*   Updated: 2020/02/04 16:16:39 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h> // KILL ME

void	*part_of_fract(void *param)
{
//	t_potok *thr;
	t_base *fract;
	int y;
	int x;

/*	thr = (t_potok *)param;
	y = thr->s_line;
	while (y < thr->f_line)
	{
		x = 0;
		while (x < WIDTH)
		{
			mandelbrot(x, y, thr->fract, thr);
			x++;
		}
		y++;
	}
	pthread_exit(0);*/
	fract = (t_base *)param;
	y = fract->thr.s_line;
	while (y < fract->thr.f_line)
	{
		x = 0;
		while (x < WIDTH)
		{
			mandelbrot(x, y, fract);
			x++;
		}
		y++;
	}
	pthread_exit(0);
}

void	multip(t_base *fract)
{
	int status;
	int i;
	pthread_t tid[THREADS];
	t_base fr[THREADS];
//	t_potok thr[THREADS];

	i = 0;
	mlx_destroy_image(fract->mlx.mlx, fract->img.img_ptr);
	img_new(fract);
	while(i < THREADS)
	{
		fr[i] = *fract;
		fr[i].thr.s_line = HEIGHT * ((float)i / THREADS);
		fr[i].thr.f_line = HEIGHT * ((float)(i + 1) / THREADS);
//		thr[i].s_line = HEIGHT * ((float)i / THREADS);
//		thr[i].f_line = HEIGHT * ((float)(i + 1) / THREADS);
//		thr[i].fract = fract;
//		status = pthread_create(&tid[i], NULL, part_of_fract, &(thr[i]));
		status = pthread_create(&tid[i], NULL, part_of_fract, &fr[i]);
		if (status)
			exit(ERROR_CREATE_THREAD);
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		status = pthread_join(tid[i], NULL);
		if (status)
			exit(ERROR_JOIN_THREAD);
		i++;
	}
	mlx_put_image_to_window(fract->mlx.mlx, fract->mlx.win, fract->img.img_ptr, 0, 0);
}