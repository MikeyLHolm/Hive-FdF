/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 09:53:18 by mlindhol          #+#    #+#             */
/*   Updated: 2019/12/17 16:31:41 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

/*
**  palette futurismo
*/

void	color_futurismo(t_fdf *data, int x, int y)
{
	int		z;

	z = data->map[y][x];
	if (z * data->altit < 0)
		data->color = 0xe80c0c;
	if (z * data->altit == 0)
		data->color = 0x96ebdc;
	if (z * data->altit > 0 && z * data->altit <= 20)
		data->color = 0xffa28d;
	if (z * data->altit > 20 && z * data->altit <= 50)
		data->color = 0xf8a7e7;
	if (z * data->altit > 50 && z * data->altit <= 99)
		data->color = 0xee2db6;
	if (z * data->altit >= 100)
		data->color = 0x5d0089;
}

/*
**  palette bnw
*/

void	color_bnw(t_fdf *data, int x, int y)
{
	int		z;

	z = data->map[y][x];
	if (z * data->altit < 0)
		data->color = 0xe80c0c;
	if (z * data->altit == 0)
		data->color = 0xffffff;
	if (z * data->altit > 0 && z * data->altit <= 20)
		data->color = 0xbfbfbf;
	if (z * data->altit > 20 && z * data->altit <= 50)
		data->color = 0x7f7f7f;
	if (z * data->altit > 50 && z * data->altit <= 99)
		data->color = 0x404040;
	if (z * data->altit >= 100)
		data->color = 0x000000;
}

/*
**  palette hell
*/

void	color_hell(t_fdf *data, int x, int y)
{
	int		z;

	z = data->map[y][x];
	if (z * data->altit < 0)
		data->color = 0xe80c0c;
	if (z * data->altit == 0)
		data->color = 0x3b0505;
	if (z * data->altit > 0 && z * data->altit <= 20)
		data->color = 0x5f0505;
	if (z * data->altit > 20 && z * data->altit <= 50)
		data->color = 0x7f3b08;
	if (z * data->altit > 50 && z * data->altit <= 99)
		data->color = 0xa6660b;
	if (z * data->altit >= 100)
		data->color = 0xbb9f0c;
}

/*
**  palette regular
*/

void	color_regular(t_fdf *data, int x, int y)
{
	int		z;

	z = data->map[y][x];
	if (z * data->altit < 0)
		data->color = 0xe80c0c;
	if (z * data->altit == 0)
		data->color = 0x00b1cc;
	if (z * data->altit > 0 && z * data->altit <= 20)
		data->color = 0x6ec165;
	if (z * data->altit > 20 && z * data->altit <= 50)
		data->color = 0xffef00;
	if (z * data->altit > 50 && z * data->altit <= 99)
		data->color = 0xd39a6a;
	if (z * data->altit > 100)
		data->color = 0xafc2e6;
}

/*
**	color dispatcher
*/

void	color(t_fdf *data, int x, int y)
{
	if (data->palette == REGULAR)
		color_regular(data, x, y);
	else if (data->palette == HELL)
		color_hell(data, x, y);
	else if (data->palette == BNW)
		color_bnw(data, x, y);
	else if (data->palette == FUTURISMO)
		color_futurismo(data, x, y);
}
