/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 20:54:45 by rzero             #+#    #+#             */
/*   Updated: 2019/04/22 21:08:06 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "get_next_line.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>

# define ARGC_ERR "usage: ./fillit source_file\n"
# define OPEN_ERR "Unable to open file.\n"
# define CLOSE_ERR "Unable to close file.\n"
# define MEM_ERR "Unable to allocate memory.\n"
# define MAP_ERR "Map is invalid.\n"

typedef struct		s_obj
{
	int		**z;
	int		d;
	void	*mlx;
	void	*win;
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		x_n;
	int		y_n;
	int		width;
	int		height;
	int		dw;
	int		dh;
	char	proj;
	int		c;
}					t_obj;

typedef struct		s_draw
{
	int	dx;
	int	dy;
	int	length_x;
	int	length_y;
	int	length;
}					t_draw;

void				read_file(int fd, t_obj *obj, char *file);
int					readncheck(char *x);
void				ft_arraydel(char **ar);
void				operate(t_obj *obj);
void				catch_err(int id);
void				do_net(t_obj *o, int x, int y, void(*f)(t_obj*, int, int));
void				drawer(t_obj *obj);
void				draw_iso(t_obj *obj, int x, int y);
void				draw_par(t_obj *obj, int x, int y);
void				free_all(t_obj *obj);

#endif
