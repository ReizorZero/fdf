/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_proj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:35:32 by rzero             #+#    #+#             */
/*   Updated: 2019/04/22 21:08:44 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_dw_dh(t_obj *obj)
{
	if (obj->proj == 'i')
	{
		obj->dw = (obj->width / 2) - (obj->x_n - 1);
		obj->dh = (obj->height / 2) - (obj->y_n - 1);
	}
	else if (obj->proj == 'p')
	{
		obj->dw = (obj->width / 2) - (((obj->x_n - 1) * obj->d) / 2);
		obj->dh = (obj->height / 2) - (((obj->y_n - 1) * obj->d) / 2);
	}
}

void	draw_iso(t_obj *obj, int x, int y)
{
	int		t_x;
	int		t_y;
	int		i_x;
	int		i_y;
	float	a;

	set_dw_dh(obj);
	a = 0.523599;
	i_x = obj->x0;
	i_y = obj->y0;
	t_x = (obj->x0 * obj->d);
	t_y = (obj->y0 * obj->d);
	obj->x0 = (t_x - t_y) * cos(a) + obj->dw;
	obj->y0 = (-obj->z[i_y][i_x] * 30) + (t_x + t_y) * sin(a) + obj->dh;
	i_x = x;
	i_y = y;
	t_x = (x * obj->d);
	t_y = (y * obj->d);
	obj->x1 = (t_x - t_y) * cos(a) + obj->dw;
	obj->y1 = (-obj->z[i_y][i_x] * 30) + (t_x + t_y) * sin(a) + obj->dh;
	drawer(obj);
}

void	draw_par(t_obj *obj, int x, int y)
{
	set_dw_dh(obj);
	obj->x0 = (obj->x0 * obj->d + obj->dw);
	obj->y0 = (obj->y0 * obj->d + obj->dh);
	obj->x1 = (x * obj->d + obj->dw);
	obj->y1 = (y * obj->d + obj->dh);
	drawer(obj);
}
