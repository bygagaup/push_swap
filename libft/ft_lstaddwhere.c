/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 13:55:39 by fschille          #+#    #+#             */
/*   Updated: 2019/01/02 17:06:39 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddwhere(t_list **alst, t_list *new, int i)
{
	t_list	*tmp;
	int		j;

	j = 1;
	tmp = *alst;
	if (i > 0)
	{
		while (j < i && tmp->next)
		{
			tmp = tmp->next;
			j++;
		}
		new->next = tmp->next;
		tmp->next = new;
	}
	else
	{
		new->next = tmp;
		*alst = new;
	}
}
