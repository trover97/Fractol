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

void	*part_of_fract(void *param)
{
	t_base *fract;
	int y;
	int x;

	fract = (t_base *)param;
	y = (int)fract->s_line;
	while(y != fract->f_line)
	{
		x = 0;
		while(x != WIDTH)
		{
			mandelbrot(x, y, fract);
			x++;
		}
		y++;
	}
}

void	multip(t_base *fract)
{
	int status;
	int i;
	pthread_t tid[THREADS];
//	pthread_attr_t attr;

	i = 0;
	mlx_destroy_image(fract->mlx.mlx, fract->img.img_ptr);
	img_new(fract);
//	pthread_attr_init(&attr);
	while(i != THREADS)
	{
		fract->s_line = HEIGHT * ((double)i / THREADS);
		fract->f_line = HEIGHT * ((double)(i + 1) / THREADS);
		if((status = pthread_create(&tid[i], NULL, part_of_fract, fract)))
			exit(ERROR_CREATE_THREAD);
		i++;
	}
	i = 0;
	while(i != THREADS)
	{
		status = pthread_join(tid[i], NULL);
		if (status)
			exit(ERROR_JOIN_THREAD);
		i++;
	}
	mlx_put_image_to_window(fract->mlx.mlx, fract->mlx.win, fract->img.img_ptr, 0, 0);
}