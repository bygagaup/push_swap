/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra_rb_rr_rra_rrb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:31:49 by fschille          #+#    #+#             */
/*   Updated: 2019/04/03 16:31:54 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_ra(t_g *w)
{
	ft_operation_rot(w->a);
	ft_printf("ra\n");
}

void	ft_rb(t_g *w)
{
	ft_operation_rot(w->b);
	ft_printf("rb\n");
}

void	ft_rr(t_g *w)
{
	ft_operation_rot(w->a);
	ft_operation_rot(w->b);
	ft_printf("rr\n");
}

void	ft_rra(t_g *w)
{
	ft_operation_rev_rot(w->a);
	ft_printf("rra\n");
}

void	ft_rrb(t_g *w)
{
	ft_operation_rev_rot(w->b);
	ft_printf("rrb\n");
}
