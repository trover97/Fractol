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

void	print_menu(t_base *fract)
{
	int y;
	int color;

	y = 0;
	color = AUSTRALIUM_GOLD;
	mlx_string_put(fract->mlx.mlx, fract->mlx.win, 20, y + 20, color, ft_itoa(fract->iter.max_i));
//	menu1(mlx, color, &y);
//	menu2(mlx, color, &y);
}