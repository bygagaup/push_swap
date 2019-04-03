/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <fschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:41:49 by fschille          #+#    #+#             */
/*   Updated: 2018/12/06 11:01:08 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	if (content)
	{
		if ((list->content = malloc(content_size)) == NULL)
		{
			free(list);
			return (NULL);
		}
		ft_memcpy(list->content, (void*)content, content_size);
		list->content_size = content_size;
	}
	else
	{
		list->content = NULL;
		list->content_size = 0;
	}
	list->next = NULL;
	return (list);
}
