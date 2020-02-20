/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:28:57 by wquirrel          #+#    #+#             */
/*   Updated: 2020/02/12 16:29:00 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	menu2(t_base *fract, int color)
{

}

void menu1(t_base *fract, int color)
{
	int y;

	y = 0;
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 100, y += 20, color
			, "Help");
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, y += 20, color,
				   "Iter:");
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 70, y, color,
				   ft_itoa(fract->iter.max_i));
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, y += 20, color,
				   "Change x|y position:");
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, y += 20, color,
				   "  Up|Dwn|L|R");
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, y += 20, color,
				   "Num_pad +|-:");
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, y += 20, color,
				   "  iteration +|-");
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, y += 20, color,
				   "Reset: Num pad 0");
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, y += 20, color,
				   "Change channel(RGB):");
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, y += 20, color,
				   "  R G B");
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, y += 20, color,
				   "Change pallet:");
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, y += 20, color,
				   "  Main pad -|+");
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, y += 20, color,
				   "LSD mode:");
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, y += 20, color,
				   "  Main pad +(hold)");
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, y += 20, color,
				   "Julia motion:");
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, y += 20, color,
				   "  MLB: freeze; MRB: unfreeze");
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, y += 20, color,
				   "  Mouse movement");
}

void	print_menu(t_base *fract)
{
	int y;
	int color;

	y = 0;
	color = AUSTRALIUM_GOLD;
	if(fract->f1_pressed < 0)
	{
		mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, y += 20, color,
					   "Press F1 for Help");
		mlx_string_put(fract->mlx.mlx, fract->mlx.win, 15, y += 20, color,
					   "Iteration:");
		mlx_string_put(fract->mlx.mlx, fract->mlx.win, 120, y, color,
					   ft_itoa(fract->iter.max_i));
	}
	else if(fract->f1_pressed > 0)
	{
		menu1(fract, color);
		menu2(fract, color);
	}
}