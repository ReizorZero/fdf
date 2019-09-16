/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:57:06 by rzero             #+#    #+#             */
/*   Updated: 2019/04/22 21:13:23 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_d(t_obj *obj)
{
	if (obj->x_n > obj->width || obj->y_n > obj->height)
		catch_err(5);
	if (obj->x_n <= 20)
		obj->d = 30;
	else if (obj->x_n > 20 && obj->x_n <= 50)
		obj->d = 20;
	else if (obj->x_n > 50 && obj->x_n <= 100)
		obj->d = 10;
	else if (obj->x_n > 100 && obj->x_n <= 200)
		obj->d = 5;
	else if (obj->x_n > 200)
		obj->d = 2;
}

void	initialize_obj(t_obj *obj, int x, int y)
{
	int i;

	i = 0;
	obj->z = (int**)malloc(sizeof(int*) * y);
	if (!obj->z)
		catch_err(4);
	while (i < y)
	{
		obj->z[i] = (int*)malloc(sizeof(int) * x);
		if (!obj->z[i])
			catch_err(4);
		i++;
	}
	obj->x_n = x;
	obj->y_n = y;
	set_d(obj);
}

void	fill_obj(t_obj *obj, int x, int y, char *file)
{
	int		fd;
	char	*ys;
	char	**xs;

	initialize_obj(obj, x, y);
	y = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		catch_err(2);
	while (get_next_line(fd, &ys) == 1)
	{
		xs = ft_strsplit(ys, ' ');
		x = 0;
		while (xs[x] != NULL)
		{
			obj->z[y][x] = readncheck(xs[x]);
			x++;
		}
		ft_arraydel(xs);
		y++;
		free(ys);
	}
	if (close(fd) == -1)
		catch_err(3);
}

void	check_row_length(int y, int x, int curr_x)
{
	if (y > 0 && x != curr_x)
		catch_err(5);
}

void	read_file(int fd, t_obj *obj, char *file)
{
	char	*ys;
	char	**xs;
	int		x;
	int		y;
	int		curr_x;

	fd = open(file, O_RDONLY);
	y = 0;
	if (fd == -1)
		catch_err(2);
	while (get_next_line(fd, &ys) == 1)
	{
		xs = ft_strsplit(ys, ' ');
		x = 0;
		while (xs[x] != NULL)
			x++;
		check_row_length(y, x, curr_x);
		y++;
		curr_x = x;
		ft_arraydel(xs);
		free(ys);
	}
	fill_obj(obj, x, y, file);
	if (close(fd) == -1)
		catch_err(3);
}
