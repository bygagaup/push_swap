/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa_sb_ss_pa_pb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:32:09 by fschille          #+#    #+#             */
/*   Updated: 2019/04/03 16:32:15 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_sa(t_g *w)
{
	ft_operation_swap(w->a);
	ft_printf("sa\n");
}

void	ft_sb(t_g *w)
{
	ft_operation_swap(w->b);
	ft_printf("sb\n");
}

void	ft_ss(t_g *w)
{
	ft_operation_swap(w->a);
	ft_operation_swap(w->b);
	ft_printf("ss\n");
}

void	ft_pa(t_g *w)
{
	ft_operation_push(w->b, w->a);
	ft_printf("pa\n");
}

void	ft_pb(t_g *w)
{
	ft_operation_push(w->a, w->b);
	ft_printf("pb\n");
}
