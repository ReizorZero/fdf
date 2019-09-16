/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:52:15 by rzero             #+#    #+#             */
/*   Updated: 2019/04/23 19:31:27 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	transform_iso(t_obj *obj, int max_x, int max_y)
{
	int x;
	int y;

	obj->proj = 'i';
	y = 0;
	while (y < max_y)
	{
		x = 0;
		while (x < max_x)
		{
			do_net(obj, x, y, draw_iso);
			x++;
		}
		y++;
	}
}

void	transform_par(t_obj *obj, int max_x, int max_y)
{
	int x;
	int y;

	obj->proj = 'p';
	y = 0;
	while (y < max_y)
	{
		x = 0;
		while (x < max_x)
		{
			do_net(obj, x, y, draw_par);
			x++;
		}
		y++;
	}
}

int		deal_key(int key, t_obj *obj)
{
	if (key == 53)
	{
		free_all(obj);
		exit(0);
	}
	else if (key == 35)
	{
		mlx_clear_window(obj->mlx, obj->win);
		if (obj->proj == 'i')
			transform_par(obj, obj->x_n, obj->y_n);
		else if (obj->proj == 'p')
			transform_iso(obj, obj->x_n, obj->y_n);
	}
	return (0);
}

void	operate(t_obj *obj)
{
	if (obj->x_n == 0 && obj->y_n == 0)
		catch_err(5);
	obj->width = 2560;
	obj->height = 1290;
	obj->c = 0;
	obj->mlx = mlx_init();
	obj->win = mlx_new_window(obj->mlx, obj->width, obj->height, "FdF");
	transform_iso(obj, obj->x_n, obj->y_n);
	mlx_key_hook(obj->win, deal_key, obj);
	mlx_loop(obj->mlx);
}
