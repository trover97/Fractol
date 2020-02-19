/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:43:26 by wquirrel          #+#    #+#             */
/*   Updated: 2020/02/18 16:13:51 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>
# include <stdint.h>
#	include <stdio.h> // KILL ME

/*
** Window
*/

# define WIDTH 1000
# define HEIGHT 1000

/*
** Colors
*/

# define WHITE 0xffffff
# define BLACK 0x000000
# define RED 0xe80c0c
# define MIDDLE_GRAY 0x7a7a7a
# define VERY_DARK_GRAY 0x0d0d0d
# define ORANGE 0xFFA500
# define MANN_CO_ORANGE 0xCF7336
# define AUSTRALIUM_GOLD 0xE7B53B

/*
** Keys
*/

# define ESC				53
# define R					15
# define G					5
# define B					11
# define M 					46
# define MLB 				1
# define MRB 				2
# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5
# define NUM_PAD_PLUS		69
# define NUM_PAD_MINUS		78
# define MAIN_PAD_PLUS		24
# define MAIN_PAD_MINUS		27


/*
** Threads
*/

#define ERROR_CREATE_THREAD -11
#define ERROR_JOIN_THREAD   -12
#define SUCCESS               0

/*
** Other
*/

# define THREADS 10
# define SHIFT 0.001

typedef struct	s_color
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
}				t_color;

typedef struct	s_potok
{
	uint16_t s_line;
	uint16_t f_line;
}				t_potok;

typedef	struct	s_iter
{
	int16_t i;
	int16_t max_i;
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
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct	s_base
{
	t_mlx mlx;
	t_img img;
	t_iter iter;
	t_complex min;
	t_complex max;
	t_complex k;
	t_complex c;
	t_complex factor;
	int16_t z;
	t_color rgb;
	char *name;
	uint8_t fractal;
	uint_fast8_t is_pressed;
//	int color;
//	double zoom_re;
//	double zoom_im;
	double	shift_y;
	double	shift_x;
	t_potok thr;
}				t_base;

void			biomorph(int x, int y, t_base *fract);
void			burning_ship(int x, int y, t_base *fract);
void			burning_julia(int x, int y, t_base *fract);
void 			choose_f(t_base *fract);
void			douady_rabbit(int x, int y, t_base *fract);
void			draw(t_base *fract);
void			img_new(t_base *fract);
t_complex		init_complex(double re, double im);
void			julia(int x, int y, t_base *fract);
int				julia_motion(int x, int y, t_base *fract);
int				key_press(int keycode, t_base *fract);
void			mandelbar(int x, int y, t_base *fract);
void			mandelbrot(int x, int y, t_base *fract);
void			multip(t_base *fract);
void			*part_of_fract(void *param);
void			perpendicular_mandelbrot(int x, int y, t_base *fract);
void			put_dot(int x, int y, t_iter iter, t_base *fract);
void			print_menu(t_base *fract);
void			usage();
void			wtf(int x, int y, t_base *fract);
void			zoom(int button ,int x, int y, t_base *fract);

#endif
