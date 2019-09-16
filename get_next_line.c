/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:51:41 by rzero             #+#    #+#             */
/*   Updated: 2019/03/07 17:24:43 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		extract_line(char **leftovers, char **str)
{
	char	*copy_leftovers;
	char	*pt1;
	char	*pt2;
	int		length;

	pt1 = *leftovers;
	pt2 = ft_strchr(*leftovers, '\n');
	*str = ft_strsub(*leftovers, 0, pt2 - pt1);
	copy_leftovers = *leftovers;
	length = ft_strlen(copy_leftovers);
	*leftovers = ft_strsub(copy_leftovers, pt2 - pt1 + 1, length);
	free(pt1);
	return (1);
}

static int		operate_tail(char **leftovers, char **str)
{
	if (ft_strcmp(*leftovers, "\0") == 0)
		return (0);
	*str = *leftovers;
	*leftovers = "\0";
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int				read_res;
	char			buffer[BUFF_SIZE + 1];
	static char		*leftovers[4864];
	char			*temp;

	if (fd < 0 || fd >= 4864 || line == NULL || read(fd, buffer, 0) < 0
			|| BUFF_SIZE < MIN_SIZE || BUFF_SIZE > MAX_SIZE)
		return (-1);
	leftovers[fd] = leftovers[fd] == NULL ? ft_strnew(0) : leftovers[fd];
	if (ft_strchr(leftovers[fd], '\n') != NULL)
		return (extract_line(&leftovers[fd], line));
	while ((read_res = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[read_res] = '\0';
		temp = leftovers[fd];
		leftovers[fd] = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(leftovers[fd], '\n') != NULL)
			return (extract_line(&leftovers[fd], line));
	}
	if ((ft_strchr(leftovers[fd], '\n')) == NULL)
		return (operate_tail(&leftovers[fd], line));
	return (0);
}
