/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:10:50 by rzero             #+#    #+#             */
/*   Updated: 2018/12/12 15:17:09 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	new = (t_list*)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (content == NULL || content == 0)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = malloc(sizeof(content) * content_size);
		if (!new->content)
			return (NULL);
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
