/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 13:43:34 by mlindhol          #+#    #+#             */
/*   Updated: 2019/12/17 17:43:08 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

/*
**	mouse controls
*/

int		event_mouse(int button, int x, int y, t_fdf *data)
{
	if (button == 1 && x && y)
		data->projection = PARALLEL;
	else if (button == 2)
		data->projection = ISOMETRIC;
	else if (button == 4)
		data->zoom += 1;
	else if (button == 5)
		data->zoom -= 1;
	draw(data);
	return (0);
}

/*
**	part 2 of keyboard controls
*/

void	event_key_rest(int key, t_fdf *data)
{
	if (key == 18)
		data->palette = REGULAR;
	else if (key == 19)
		data->palette = HELL;
	else if (key == 20)
		data->palette = BNW;
	else if (key == 21)
		data->palette = FUTURISMO;
	else if (key == 34)
		data->projection = ISOMETRIC;
	else if (key == 35)
		data->projection = PARALLEL;
	else if (key == 86)
		data->alpha -= 0.05;
	else if (key == 87)
		data->beta -= 0.05;
	else if (key == 89)
		data->gamma -= 0.05;
	else if (key == 88)
		data->alpha += 0.05;
	else if (key == 91)
		data->beta += 0.05;
	else if (key == 92)
		data->gamma += 0.05;
}

/*
**	part 1 of keyboard controls
*/

int		event_key(int key, t_fdf *data)
{
	write(1, "X", 1);
	if (key == 53)
		exit(0);
	else if (key == 67)
		data->altit += 1;
	else if (key == 75)
		data->altit -= 1;
	else if (key == 69)
		data->zoom += 1;
	else if (key == 78 && data->zoom > 0)
		data->zoom -= 1;
	else if (key == 123)
		data->pos_x -= 5;
	else if (key == 124)
		data->pos_x += 5;
	else if (key == 125)
		data->pos_y += 5;
	else if (key == 126)
		data->pos_y -= 5;
	else if (key == 15)
		reset_map(data);
	event_key_rest(key, data);
	draw(data);
	return (0);
}
