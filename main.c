/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:26:27 by mlindhol          #+#    #+#             */
/*   Updated: 2019/12/18 11:57:20 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/includes/libft.h"

/*
**	reset map to starting position
*/

void	reset_map(t_fdf *data)
{
	data->zoom = 25;
	if (data->height > 300 || data->width > 300)
		data->zoom = 2;
	else if (data->height > 100 || data->width > 100)
		data->zoom = 5;
	else if (data->height > 25 || data->width > 25)
		data->zoom = 9;
	data->altit = 1;
	data->alpha = 0;
	data->beta = 0;
	data->gamma = 0;
	data->palette = REGULAR;
	data->projection = PARALLEL;
	data->pos_x = data->map_w / 2 - (data->map_w / 10);
	data->pos_y = 50;
	draw(data);
}

/*
**	setting map zoom and dimensions according to map size
*/

void	setup_map(t_fdf *data)
{
	if (data->height > 300 || data->width > 300)
	{
		data->zoom = 2;
		data->map_h = 1300;
		data->map_w = 2400;
	}
	else if (data->height > 100 || data->width > 100)
	{
		data->zoom = 5;
		data->map_h = 1150;
		data->map_w = 2000;
	}
	else if (data->height > 25 || data->width > 25)
	{
		data->zoom = 9;
		data->map_h = 1000;
		data->map_w = 1600;
	}
}

/*
**	setting up map data
*/

void	setup(t_fdf *data)
{
	data->zoom = 25;
	data->map_h = 700;
	data->map_w = 1000;
	data->color = 0xFFFFFF;
	data->altit = 1;
	data->alpha = 0;
	data->beta = 0;
	data->gamma = 0;
	data->palette = REGULAR;
	data->projection = PARALLEL;
	setup_map(data);
	data->pos_x = data->map_w / 2 - (data->map_w / 10);
	data->pos_y = 50;
}

/*
**	Once upon a time...it all started here.
*/

int		main(int ac, char **av)
{
	t_fdf		*data;

	if (!(data = (t_fdf*)malloc(sizeof(t_fdf))))
		exit(-1);
	if (ac != 2)
	{
		ft_putstr_fd("Wrong number of arguments. Only one map at time.\n", 2);
		ft_putstr_fd("Usage: ./fdf <filename>\n", 2);
		return (1);
	}
	read_file(av[1], data);
	setup(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->map_w, data->map_h, "FDF");
	draw(data);
	mlx_hook(data->win, 2, 0, event_key, data);
	mlx_hook(data->win, 4, 0, event_mouse, data);
	mlx_loop(data->mlx);
	return (0);
}
