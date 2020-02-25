/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:28:57 by wquirrel          #+#    #+#             */
/*   Updated: 2020/02/25 17:00:42 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	menu2(t_base *fract, int color, int *y)
{
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, *y += 20, color,
	"Change pallet:");
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, *y += 20, color,
	"  Main pad -|+");
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, *y += 20, color,
	"LSD mode:");
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, *y += 20, color,
	"  Main pad +(hold)");
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, *y += 20, color,
	"Julia motion:");
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, *y += 20, color,
	"  MLB: freeze; MRB: unfreeze");
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, *y += 20, color,
	"  Mouse movement");
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, *y += 20, color,
	"Menu color: M");
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, *y += 20, color,
	"Fractals: M_pad 1 - 8");
}

static void	menu1(t_base *fract, int color, int *y)
{
	char *iter;

	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 100, *y += 20, color
	, "Help");
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, *y += 20, color,
	"Iter:");
	iter = ft_itoa(fract->iter.max_i);
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 70, *y, color,
	iter);
	free(iter);
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, *y += 20, color,
	"Change x|y position:");
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, *y += 20, color,
	"  Up|Dwn|L|R");
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, *y += 20, color,
	"Iteration +|-");
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, *y += 20, color,
	"  Num_pad +|-:");
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, *y += 20, color,
	"Reset: Num pad 0");
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, *y += 20, color,
	"Change channel value(RGB):");
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, *y += 20, color,
	"  R G B");
}

void		print_menu(t_base *fract)
{
	int y;
	char *iter;

	y = 0;
	if (fract->f1_pressed < 0)
	{
		mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, y += 20
		, fract->m_color, "Press F1 for Help");
		mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, y += 20
		, fract->m_color, "Iteration:");
		iter = ft_itoa(fract->iter.max_i);
		mlx_string_put(fract->mlx.mlx, fract->mlx.win, 120, y
		, fract->m_color, iter);
		free(iter);
	}
	else if (fract->f1_pressed > 0)
	{
		menu1(fract, fract->m_color, &y);
		menu2(fract, fract->m_color, &y);
	}
}
