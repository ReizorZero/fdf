/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:34:32 by rzero             #+#    #+#             */
/*   Updated: 2019/04/22 17:34:53 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	catch_err(int id)
{
	if (id == 1)
	{
		ft_putstr(ARGC_ERR);
		exit(1);
	}
	else if (id == 2)
	{
		ft_putstr(OPEN_ERR);
		exit(2);
	}
	else if (id == 3)
	{
		ft_putstr(CLOSE_ERR);
		exit(3);
	}
	else if (id == 4)
	{
		ft_putstr(MEM_ERR);
		exit(4);
	}
	else if (id == 5)
	{
		ft_putstr(MAP_ERR);
		exit(5);
	}
}
