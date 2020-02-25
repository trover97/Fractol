/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithreading.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:16:36 by wquirrel          #+#    #+#             */
/*   Updated: 2020/02/25 16:38:24 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	*part_of_fract(void *param)
{
	t_base			*fract;
	unsigned int	y;
	unsigned int	x;

	fract = (t_base *)param;
	y = fract->thr.s_line;
	while (y < fract->thr.f_line)
	{
		x = 0;
		while (x < WIDTH)
		{
			wtf(x, y, fract);
			x++;
		}
		y++;
	}
	pthread_exit(0);
}

void		multip(t_base *fract)
{
	int			status;
	int			i;
	pthread_t	tid[THREADS];
	t_base		fr[THREADS];

	i = 0;
	if (fract->img.img_ptr)
		mlx_destroy_image(fract->mlx.mlx, fract->img.img_ptr);
	img_new(fract);
	while (i < THREADS)
	{
		fr[i] = *fract;
		fr[i].thr.s_line = HEIGHT * ((float)i / THREADS);
		fr[i].thr.f_line = HEIGHT * ((float)(i + 1) / THREADS);
		if ((status = pthread_create(&tid[i], NULL, part_of_fract, &fr[i])))
			exit(ERROR_CREATE_THREAD);
		i++;
	}
	i = -1;
	while (++i < THREADS)
		if ((status = pthread_join(tid[i], NULL)))
			exit(ERROR_JOIN_THREAD);
	mlx_put_image_to_window(fract->mlx.mlx, fract->mlx.win, fract->img.img_ptr
			, 0, 0);
	print_menu(fract);
}
