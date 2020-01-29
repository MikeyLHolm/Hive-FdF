/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:28:22 by mlindhol          #+#    #+#             */
/*   Updated: 2020/01/02 08:41:34 by mlindhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "libft/includes/libft.h"

/*
** Get the height and width of the file for malloc.
*/

void		get_size(char *file, t_fdf *data)
{
	char	*line;
	int		fd;
	int		height;
	int		width;

	if ((fd = open(file, O_RDONLY)) < 0)
	{
		ft_putstr_fd("Couldn't open the file, try again!\n", 2);
		exit(1);
	}
	height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		height++;
		width = ft_word_count(line);
		free(line);
	}
	if (close(fd) == -1)
	{
		ft_putstr_fd("Couldn't close the file!\n", 2);
		exit(1);
	}
	data->height = height;
	data->width = width;
}

/*
** Malloc the 2D table of ints.
*/

void		alloc_z(char *file, t_fdf *data)
{
	int		**map;
	int		i;

	if (!(data->map = (int **)malloc(sizeof(t_fdf *) * (data->height + 1))))
		exit(1);
	i = 0;
	while (i < data->height)
	{
		data->map[i] = (int *)malloc(sizeof(t_fdf) * (data->width + 1));
		if (!data->map[i])
			exit(1);
		i++;
	}
}

/*
** Transform string to ints and fill the line_z.
*/

void		fill_map(int *line_z, char *line)
{
	char	**map;
	int		i;

	map = ft_strsplit(line, ' ');
	i = 0;
	while (map[i])
	{
		line_z[i] = ft_atoi(map[i]);
		free(map[i]);
		i++;
	}
	free(map);
}

/*
** Read file, Malloc 2D and then fill 2D array with line_zs.
*/

void		read_file(char *file, t_fdf *data)
{
	char	*line;
	int		fd;
	int		i;

	get_size(file, data);
	if (data->width == 0 || data->height == 0)
	{
		ft_putstr_fd("Invalid file, try again!\n", 2);
		exit(1);
	}
	alloc_z(file, data);
	if ((fd = open(file, O_RDONLY)) < 0)
		exit(1);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		fill_map(data->map[i], line);
		free(line);
		i++;
	}
	data->map[i] = NULL;
	if (close(fd) == -1)
		exit(1);
}
