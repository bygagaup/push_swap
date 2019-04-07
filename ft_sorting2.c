/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 03:45:38 by fschille          #+#    #+#             */
/*   Updated: 2019/04/07 03:45:40 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int 	g_g2 = 0;

int			ft_correct_order(t_stc *o, int m, int b)
{
	int 	i;

	i = 0;
	while (o->size - 1 > i)
	{
		if (o->elem[0] < o->elem[o->size - 1])
			return (1);
		if (o->elem[i] == b && o->elem[i + 1] == m)
			i++;
		else if (o->elem[i] < o->elem[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

int 		ft_scrolling(t_g *w, int m)
{
	int 	i;

	i = 0;
	while (w->a->size > i)
	{
		if (w->a->elem[i] == m)
		{
			if ((i) > w->a->size / 2)
				return ((w->a->size - i) * -1);
			else
			{
				return ((i));
			}
		}
		i++;
	}
	return (0);
}

int 		ft_direction(t_g *w, int b, int m, int elem)
{
	int 	i;

	i = 0;
	if (elem < w->a->elem[i] && elem > w->a->elem[w->a->size - 1])
		return (0);
	while (w->a->size - 1 > i)
	{
		if ((w->a->elem[i] != b && w->a->elem[i + 1] != m))
		{
			if (elem > w->a->elem[i] && elem < w->a->elem[i + 1])
			{
				if ((i) >= w->a->size / 2)
					return ((w->a->size - i - 1) * -1);
				else
				{
					return ((i + 1));
				}
			}
		}
		i++;
	}
	return (0);
}

void		ft_sorting2(t_g *w)
{
	int i;
	int m;
	int b;
	int s;

	if (g_g2 == 1)
		ft_print_stack(w);
	m = ft_intm(w->a);
	b = ft_intb(w->a);
	s = b;
	i = -1;
	if (ft_correct_order(w->a, m, b) == 0)
	{
		if ((s = ft_scrolling(w, m)) > 0)
		{
			while (s > 0)
			{
				ft_ra(w, 1);
				if (g_g2 == 1)
					ft_print_stack(w);
				s--;
			}
		}
		else
		{
			s = -s;
			while (s > 0)
			{
				ft_rra(w, 1);
				if (g_g2 == 1)
					ft_print_stack(w);
				s--;
			}
		}
	}
	if (ft_chek_pars(w) == 0)
		return ;
	while (++i < w->a->size / 2)
		s = ft_intsb(w->a, s);
	while(w->a->size > 3)
	{
		if (ft_correct_order(w->a, m, b) == 0)
			break ;
		if (w->a->elem[0] != b && w->a->elem[0] != m)
		{
			ft_pb(w, 1);
			if (g_g2 == 1)
				ft_print_stack(w);
		}
		else
		{
			ft_ra(w, 1);
			if (g_g2 == 1)
				ft_print_stack(w);
		}
	}
	if (w->a->elem[0] > w->a->elem[1] && w->a->elem[0] < w->a->elem[2] && w->a->elem[1] < w->a->elem[2])
	{
		ft_sa(w, 1);
		if (g_g2 == 1)
			ft_print_stack(w);
	}
	if (w->a->elem[0] > w->a->elem[1] && w->a->elem[0] > w->a->elem[2] && w->a->elem[1] > w->a->elem[2])
	{
		ft_sa(w, 1);
		if (g_g2 == 1)
			ft_print_stack(w);
	}
	if (w->a->elem[0] < w->a->elem[1] && w->a->elem[0] < w->a->elem[2] && w->a->elem[1] > w->a->elem[2])
	{
		ft_sa(w, 1);
		if (g_g2 == 1)
			ft_print_stack(w);
	}
	while (w->b->size > 0)
	{
		if ((s = ft_direction(w, b, m, w->b->elem[0])) > 0)
		{
			while (s > 0)
			{
				ft_ra(w, 1);
				if (g_g2 == 1)
					ft_print_stack(w);
				s--;
			}
		}
		else
		{
			s = -s;
			while (s > 0)
			{
				ft_rra(w, 1);
				if (g_g2 == 1)
					ft_print_stack(w);
				s--;
			}
		}
		ft_pa(w, 1);
		if (g_g2 == 1)
			ft_print_stack(w);
	}
	while (ft_chek_pars(w) != 0)
	{
		if ((s = ft_scrolling(w, m)) > 0)
		{
			while (s > 0)
			{
				ft_ra(w, 1);
				if (g_g2 == 1)
					ft_print_stack(w);
				s--;
			}
		}
		else
		{
			s = -s;
			while (s > 0)
			{
				ft_rra(w, 1);
				if (g_g2 == 1)
					ft_print_stack(w);
				s--;
			}
		}
	}
}