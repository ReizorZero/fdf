/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readncheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 20:58:17 by rzero             #+#    #+#             */
/*   Updated: 2019/04/23 19:51:57 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_color(char **arr, char *x)
{
	int i;

	if (ft_strlen(arr[0]) + ft_strlen(arr[1]) + 1 != ft_strlen(x))
		catch_err(5);
	if (ft_strlen(arr[1]) > 8 || ft_strlen(arr[1]) < 3)
		catch_err(5);
	if (arr[1][0] != '0' || arr[1][1] != 'x')
		catch_err(5);
	i = 0;
	while (arr[1][i] != '\0')
	{
		arr[1][i] = ft_toupper(arr[1][i]);
		i++;
	}
	i = 2;
	while (arr[1][i] != '\0')
	{
		if (ft_isdigit(arr[1][i]) == 0 && (arr[1][i] < 65 || arr[1][i] > 70))
			catch_err(5);
		i++;
	}
}

int		readncheck(char *x)
{
	int		i;
	char	**arr;

	i = 0;
	arr = ft_strsplit(x, ',');
	if (arr[1] != NULL)
		check_color(arr, x);
	if (arr[0][0] != '-' && arr[0][0] != '+' && ft_isdigit(arr[0][0]) == 0)
		catch_err(5);
	else
		i++;
	while (arr[0][i] != '\0')
	{
		if (ft_isdigit(arr[0][i]) == 0)
			catch_err(5);
		i++;
	}
	ft_arraydel(arr);
	return (ft_atoi(x));
}
