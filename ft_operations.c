/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_sa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:08:07 by fschille          #+#    #+#             */
/*   Updated: 2019/03/28 18:08:09 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_operation_swap(t_stc *o)
{
	int 	tmp;

	if (o->size < 2)
		return ;
	tmp = o->elem[0];
	o->elem[0] = o->elem[1];
	o->elem[1] = tmp;
}

void	ft_operation_push(t_stc *o1, t_stc *o2)
{
	int 	tmp;
	int 	i;

	if (o1->size == 0)
		return ;
	i = 0;
	tmp = o1->elem[i];
	while (o1->size > i + 1)
	{
		o1->elem[i] = o1->elem[i + 1];
		i++;
	}
	i = o2->size;
	while (i > 0)
	{
		o2->elem[i] = o2->elem[i - 1];
		i--;
	}
	o2->elem[i] = tmp;
	o1->size -= 1;
	o2->size += 1;
}

void	ft_operation_rot(t_stc *o)
{
	int 	tmp;
	int 	i;

	if (o->size < 2)
		return ;
	i = 0;
	tmp = o->elem[i];
	while (o->size > i + 1)
	{
		o->elem[i] = o->elem[i + 1];
		i++;
	}
	o->elem[i] = tmp;
}

void	ft_operation_rev_rot(t_stc *o)
{
	int 	tmp;
	int 	i;

	if (o->size < 2)
		return ;
	i = o->size - 1;
	tmp = o->elem[i];
	while (i > 0)
	{
		o->elem[i] = o->elem[i - 1];
		i--;
	}
	o->elem[i] = tmp;
}