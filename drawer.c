/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:45:53 by rzero             #+#    #+#             */
/*   Updated: 2019/04/22 21:09:30 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		max_int(int a, int b)
{
	return ((a > b) ? a : b);
}

void	drawer_first(t_obj *obj, t_draw *draw)
{
	int x;
	int y;
	int d;

	x = obj->x0;
	y = obj->y0;
	d = -draw->length_x;
	draw->length++;
	while (draw->length--)
	{
		mlx_pixel_put(obj->mlx, obj->win, x, y, 0xFF8C00);
		x += draw->dx;
		d += 2 * draw->length_y;
		if (d > 0)
		{
			d -= 2 * draw->length_x;
			y += draw->dy;
		}
	}
}

void	drawer_second(t_obj *obj, t_draw *draw)
{
	int x;
	int y;
	int d;

	x = obj->x0;
	y = obj->y0;
	d = -draw->length_y;
	draw->length++;
	while (draw->length--)
	{
		mlx_pixel_put(obj->mlx, obj->win, x, y, 0xFF8C00);
		y += draw->dy;
		d += 2 * draw->length_x;
		if (d > 0)
		{
			d -= 2 * draw->length_y;
			x += draw->dx;
		}
	}
}

void	drawer(t_obj *obj)
{
	t_draw *draw;

	draw = (t_draw*)malloc(sizeof(t_draw));
	if (!draw)
		catch_err(4);
	draw->dx = (obj->x1 - obj->x0 >= 0 ? 1 : -1);
	draw->dy = (obj->y1 - obj->y0 >= 0 ? 1 : -1);
	draw->length_x = abs(obj->x1 - obj->x0);
	draw->length_y = abs(obj->y1 - obj->y0);
	draw->length = max_int(draw->length_x, draw->length_y);
	if (draw->length == 0)
		mlx_pixel_put(obj->mlx, obj->win, obj->x0, obj->y0, 0xFF8C00);
	if (draw->length_y <= draw->length_x)
		drawer_first(obj, draw);
	else
		drawer_second(obj, draw);
}

void	do_net(t_obj *obj, int x, int y, void (*f)(t_obj*, int, int))
{
	obj->x0 = x;
	obj->y0 = y;
	if (x + 1 < obj->x_n)
		f(obj, x + 1, y);
	obj->x0 = x;
	obj->y0 = y;
	if (y + 1 < obj->y_n)
		f(obj, x, y + 1);
	obj->x0 = x;
	obj->y0 = y;
	if (x - 1 > -1)
		f(obj, x - 1, y);
	obj->x0 = x;
	obj->y0 = y;
	if (y - 1 > -1)
		f(obj, x, y - 1);
}
