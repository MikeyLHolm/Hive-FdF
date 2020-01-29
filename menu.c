/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 09:50:24 by mlindhol          #+#    #+#             */
/*   Updated: 2019/12/17 17:52:09 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

/*
**	text menu for top left corner
*/

void	print_menu(t_fdf *data)
{
	mlx_string_put(data->mlx, data->win, 50, 50, 0xFFFFFF, "** MENU **");
	mlx_string_put(data->mlx, data->win, 50, 100, 0xFFFFFF, "ESC: quit");
	mlx_string_put(data->mlx, data->win, 50, 130,
		0xFFFFFF, "Mouse wheel: zoom");
	mlx_string_put(data->mlx, data->win, 50, 160, 0xFFFFFF, "*//: altitude");
	mlx_string_put(data->mlx, data->win, 50, 190, 0xFFFFFF, "Arrows: move map");
	mlx_string_put(data->mlx, data->win, 50, 220,
		0xFFFFFF, "Mouse R/L: projection");
	mlx_string_put(data->mlx, data->win, 50, 250, 0xFFFFFF, "1-4: color");
	mlx_string_put(data->mlx, data->win, 50, 280, 0xFFFFFF, "R: reset");
	mlx_string_put(data->mlx, data->win, 50, 310,
		0xFFFFFF, "Numpad 456789: tilt");
}
