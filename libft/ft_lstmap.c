/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <fschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:58:15 by fschille          #+#    #+#             */
/*   Updated: 2019/01/05 16:29:08 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		ft_del(void *content, size_t content_size)
{
	free(content);
	content = NULL;
	content_size = 0;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*new_list;

	if (lst == NULL || !f)
		return (NULL);
	start = (t_list*)malloc(sizeof(t_list));
	if (start == NULL)
		return (NULL);
	start = f(lst);
	new_list = start;
	while (lst->next != NULL)
	{
		lst = lst->next;
		new_list->next = (t_list*)malloc(sizeof(t_list));
		if (new_list->next == NULL)
		{
			ft_lstdel(&start, &ft_del);
			return (NULL);
		}
		new_list->next = f(lst);
		new_list = new_list->next;
	}
	return (start);
}
