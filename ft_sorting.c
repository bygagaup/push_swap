/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:32:24 by fschille          #+#    #+#             */
/*   Updated: 2019/04/03 16:32:27 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int 	g_g = 1;

int 		ft_chek_pars(t_g *w)
{
	int 	i;

	i = 0;
	while (i < w->a->size - 1)
	{
		if (w->a->elem[i] < w->a->elem[i + 1])
			i++;
		else
			return (1);
	}
	i = 0;
	while (i < w->b->size - 1)
	{
		if (w->b->elem[i] > w->b->elem[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

int 		ft_intb(t_stc *o)
{
	int 	i;
	int 	size;
	int 	tmp;

	i = 0;
	size = o->size;
	tmp = o->elem[0];
	while (i < size - 1)
	{
		i++;
		if (o->elem[i] > tmp)
			tmp = o->elem[i];
	}
	return (tmp);
}

int 		ft_intm(t_stc *o)
{
	int 	i;
	int 	size;
	int 	tmp;

	i = 0;
	size = o->size;
	tmp = o->elem[0];
	while (i < size - 1)
	{
		i++;
		if (o->elem[i] < tmp)
			tmp = o->elem[i];
	}
	return (tmp);
}

int 		ft_intsb(t_stc *o, int b)
{
	int 	i;
	int 	size;
	int 	tmp;

	i = 0;
	size = o->size;
	tmp = -2147483648;
	while (i < size)
	{
		if (o->elem[i] > tmp && o->elem[i] < b)
			tmp = o->elem[i];
		i++;
	}
	return (tmp);
}

int 		ft_intsm(t_stc *o, int m)
{
	int 	i;
	int 	size;
	int 	tmp;

	i = 0;
	size = o->size;
	tmp = 2147483647;
	while (i < size)
	{
		if (o->elem[i] < tmp && o->elem[i] > m)
			tmp = o->elem[i];
		i++;
	}
	return (tmp);
}

void		ft_sorting(t_g *w)
{
	int 	i;
	int 	j;
	int 	b;
	int 	m;
	int 	s;
	int 	tmp;
	int 	mid;
	int 	mid_i;

	i = 0;
	j = w->a->size;
	b = ft_intb(w->a);
	m = ft_intm(w->a);
	s = ft_intsb(w->a, b);
	mid = b;
	mid_i = -1;
	if (ft_chek_pars(w) == 0)
		return ;
	if (g_g == 1)
		ft_print_stack(w);
	while (++mid_i <= (w->a->size) / 2)
		mid = ft_intsb(w->a, mid);
	tmp = 1;
	if (w->a->size == 1 && ft_chek_pars(w) == 0)
		return ;
	while (w->a->size > mid_i)
	{
		if (w->a->elem[0] <= mid)
		{
			if (w->a->elem[0] > w->a->elem[1])
			{
				ft_sa(w, 1);
				if (g_g == 1)
					ft_print_stack(w);
				i++;
			}
			ft_pb(w, 1);
			i++;
		}
		else
		{
			ft_ra(w, 1);
			i++;
		}
		if (g_g == 1)
			ft_print_stack(w);
	}
	if (ft_chek_pars(w) == 0)
		return ;
	while (j > 0)
	{
		while (w->a->size > 1 + tmp)
		{
			if (w->a->elem[0] > w->a->elem[1])
			{
				ft_sa(w, 1);
				if (g_g == 1)
					ft_print_stack(w);
				i++;
				if (w->a->elem[0] != s && (!(w->a->elem[0] == s && w->a->elem[1] == b) || !(w->a->elem[0] == b && w->a->elem[1] == s)))
				{
					ft_pb(w, 1);
					if (g_g == 1)
						ft_print_stack(w);
					i++;
				}
				else
				{
					ft_rra(w, 1);
					if (g_g == 1)
						ft_print_stack(w);
					i++;
				}
			}
			else
			{
				if (w->a->elem[0] != s && (!(w->a->elem[0] == s && w->a->elem[1] == b) || !(w->a->elem[0] == b && w->a->elem[1] == s)))
				{
					ft_pb(w, 1);
					if (g_g == 1)
						ft_print_stack(w);
					i++;
				}
				else
				{
					ft_rra(w, 1);
					if (g_g == 1)
						ft_print_stack(w);
					i++;
				}
			}
		}
		if (w->a->size >= 2 && w->a->elem[0] > w->a->elem[1])
		{
			ft_sa(w, 1);
			if (g_g == 1)
				ft_print_stack(w);
			i++;
		}
		b = s;
		s = ft_intsm(w->b, m);
		while (w->b->size > 1 + tmp)
		{
			if (w->b->elem[0] > w->b->elem[1])
			{
				if (w->b->elem[0] != s && (!(w->b->elem[0] == s && w->b->elem[1] == m) || !(w->b->elem[0] == b && w->b->elem[1] == s)))
				{
					ft_pa(w, 1);
					if (g_g == 1)
						ft_print_stack(w);
					i++;
				}
				else
				{
					ft_rrb(w, 1);
					if (g_g == 1)
						ft_print_stack(w);
					i++;
				}
			}
			else
			{
					ft_sb(w, 1);
				if (g_g == 1)
					ft_print_stack(w);
					i++;
				if (w->b->elem[0] != s && (!(w->b->elem[0] == s && w->b->elem[1] == m) || !(w->b->elem[0] == b && w->b->elem[1] == s)))
				{
					ft_pa(w, 1);
					if (g_g == 1)
						ft_print_stack(w);
					i++;
				}
				else
				{
					ft_rrb(w, 1);
					if (g_g == 1)
						ft_print_stack(w);
					i++;
				}
			}
		}
		if (w->b->size >= 2 && w->b->elem[0] < w->b->elem[1])
		{
			ft_sb(w, 1);
			if (g_g == 1)
				ft_print_stack(w);
			i++;
		}
		m = s;
		s = ft_intsb(w->a, b);
		if (ft_chek_pars(w) == 0)
		{
			if (w->b->size >= 1)
			{
				while (w->b->size > 0)
				{
					ft_pa(w, 1);
					if (g_g == 1)
						ft_print_stack(w);
					i++;
				}
			}
			if (g_g == 1)
				ft_printf("operation - %d\n", i);
			return ;
		}
		tmp++;
		j--;
	}
	ft_pa(w, 1);
	i++;
	if (g_g == 1)
		ft_printf("operation - %d\n", i);
}
