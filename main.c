/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:50:58 by rzero             #+#    #+#             */
/*   Updated: 2019/04/22 21:09:44 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_obj	*obj;
	int		fd;

	if (argc != 2)
		catch_err(1);
	else
	{
		obj = (t_obj*)malloc(sizeof(t_obj));
		if (!obj)
			catch_err(4);
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			catch_err(2);
		read_file(fd, obj, argv[1]);
		if (close(fd) == -1)
			catch_err(3);
		operate(obj);
	}
	return (0);
}
