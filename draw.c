/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 09:32:48 by mlindhol          #+#    #+#             */
/*   Updated: 2019/12/17 16:48:15 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/includes/libft.h"

/*
** The actual line drawing algorithm. d = data, s = start, e = end
*/

static void		draw_pixels(t_fdf *d, t_draw s, t_draw e)
{
	int dx;
	int dy;
	int dir[2];
	int p[2];

	dx = ft_abs(e.x - s.x);
	dy = ft_abs(e.y - s.y);
	dir[0] = (s.x < e.x ? 1 : -1);
	dir[1] = (s.y < e.y ? 1 : -1);
	p[0] = (dx > dy ? dx : -dy) / 2;
	while (s.x != e.x || s.y != e.y)
	{
		mlx_pixel_put(d->mlx, d->win, d->pos_x + s.x, d->pos_y + s.y, d->color);
		p[1] = p[0];
		if (p[1] > -dx)
		{
			p[0] -= dy;
			s.x += dir[0];
		}
		if (p[1] < dy)
		{
			p[0] += dx;
			s.y += dir[1];
		}
	}
}

/*
** Giving t_draw *info all the data Bresenham needs.
*/

static void		draw_lines(t_fdf *data, t_draw start, t_draw end)
{
	t_draw		*info;

	if (!(info = (t_draw*)malloc(sizeof(t_draw))))
		exit(-1);
	info->z = data->map[start.y][start.x] * data->altit;
	info->z2 = data->map[end.y][end.x] * data->altit;
	info->x = start.x * data->zoom;
	info->x2 = end.x * data->zoom;
	info->y = start.y * data->zoom;
	info->y2 = end.y * data->zoom;
	if (data->projection == ISOMETRIC)
		projection(data, info);
	start.x = info->x;
	start.y = info->y;
	end.x = info->x2;
	end.y = info->y2;
	draw_pixels(data, start, end);
	free(info);
}

/*
** Setting up color and x, x2, y, y2 coordinate values.
*/

void			set_coords(t_fdf *data, int x, int y)
{
	t_draw		coords[2];

	color(data, x, y);
	coords[0].x = x;
	coords[0].y = y;
	if (x < data->width - 1)
	{
		coords[1].x = x + 1;
		coords[1].y = y;
		draw_lines(data, coords[0], coords[1]);
	}
	if (y < data->height - 1)
	{
		coords[1].x = x;
		coords[1].y = y + 1;
		draw_lines(data, coords[0], coords[1]);
	}
}

/*
** Main drawing function that calls for different sub-functions
** and loops thru 'till the edges of the map.
*/

void			draw(t_fdf *data)
{
	int			x;
	int			y;

	y = 0;
	mlx_clear_window(data->mlx, data->win);
	print_menu(data);
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			set_coords(data, x, y);
			x++;
		}
		y++;
	}
}
