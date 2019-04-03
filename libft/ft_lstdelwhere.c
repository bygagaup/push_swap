/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 13:55:39 by fschille          #+#    #+#             */
/*   Updated: 2019/01/05 15:27:14 by fschille         ###   ########.fr       */
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

void			ft_lstdelwhere(t_list **alst, int i)
{
	t_list	*tmp;
	t_list	*zam;
	int		j;

	j = 1;
	tmp = *alst;
	if (i > 0)
	{
		while (j < i && tmp->next->next)
		{
			tmp = tmp->next;
			j++;
		}
		zam = tmp->next->next;
		ft_lstdelone(&tmp->next, &ft_del);
		tmp->next = zam;
	}
	else
	{
		*alst = tmp->next;
		ft_lstdelone(&tmp, &ft_del);
	}
}
