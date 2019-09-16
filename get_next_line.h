/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:24:00 by rzero             #+#    #+#             */
/*   Updated: 2019/03/07 17:24:09 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 666

# define MAX_SIZE 160000
# define MIN_SIZE 1

# include "libft/libft.h"

int get_next_line(const int fd, char **line);

#endif
