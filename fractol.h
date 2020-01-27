/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:43:26 by wquirrel          #+#    #+#             */
/*   Updated: 2020/01/24 15:43:30 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "libft.h"
#include "mlx.h"
#include <math.h>

# define WIDTH 1281
# define HEIGHT 1281

typedef	struct	s_iter
{
	int i;
	int max_i;
}				t_iter;

typedef	struct	s_complex
{
	double re;
	double im;
}				t_complex;

typedef struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct	s_mlx
{
	void *mlx;
	void *win;
}				t_mlx;

typedef struct	s_base
{
	t_mlx mlx;
	t_img img;
}				t_base;

void			mandelbrot(t_base base);
t_complex		init_complex(double re, double im);
void			put_pixel(int x, int y, t_iter iter, t_base *base);

#endif
