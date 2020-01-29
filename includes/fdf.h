/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 09:37:05 by mlindhol          #+#    #+#             */
/*   Updated: 2019/12/17 17:31:56 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum
{
	ISOMETRIC,
	PARALLEL
}	t_projection;

typedef enum
{
	BNW,
	FUTURISMO,
	HELL,
	REGULAR,
}	t_palette;

typedef struct		s_draw
{
	int				dx;
	int				dy;
	int				x;
	int				x2;
	int				y;
	int				y2;
	int				z;
	int				z2;
}					t_draw;

typedef struct		s_fdf
{
	int				**map;
	int				map_h;
	int				map_w;
	int				height;
	int				width;
	int				zoom;
	int				altit;
	int				color;
	int				pos_x;
	int				pos_y;
	double			alpha;
	double			beta;
	double			gamma;
	t_projection	projection;
	t_palette		palette;
	void			*mlx;
	void			*win;
}					t_fdf;

void				read_file(char *file, t_fdf *data);
void				draw(t_fdf *data);
int					event_key(int key, t_fdf *data);
int					event_mouse(int key, int x, int y, t_fdf *data);
void				print_menu(t_fdf *data);
void				color(t_fdf *data, int x, int y);
void				projection(t_fdf *data, t_draw *info);
void				isometric(int *x, int *y, int z);
void				reset_map(t_fdf *data);

#endif
