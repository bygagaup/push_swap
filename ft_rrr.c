/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:32:00 by fschille          #+#    #+#             */
/*   Updated: 2019/04/03 16:32:03 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_rrr(t_g *w)
{
	ft_operation_rev_rot(w->a);
	ft_operation_rev_rot(w->b);
	ft_printf("rrr\n");
}
