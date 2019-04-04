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
	int 	b[2];
	int 	m[2];
	int 	s[2];
	int 	tmp;

	i = 0;
	j = w->a->size;
	b[0] = ft_intb(w->a);
	m[0] = ft_intm(w->a);
	b[1] = ft_intsb(w->a, b[0]);
	m[1] = ft_intsm(w->a, m[0]);
	s[0] = ft_intsb(w->a, b[0]);
	s[1] = ft_intsb(w->a, b[1]);
	tmp = 2;
	while (j > 0)
	{
		while (w->a->size > 1 + tmp)
		{
			if (w->a->elem[0] > w->a->elem[1])
			{
				ft_sa(w, 1);
//				ft_print_stack(w);
				i++;
				if (w->a->elem[0] != s[0] && ((w->a->elem[0] != s[0] && w->a->elem[1] != b[0]) || (w->a->elem[0] != b[0] && w->a->elem[1] != s[0])) &&
				w->a->elem[0] != s[1] && ((w->a->elem[0] != s[1] && w->a->elem[1] != b[1]) || (w->a->elem[0] != b[1] && w->a->elem[1] != s[1])))
				{
					ft_pb(w, 1);
//					ft_print_stack(w);
					i++;
				}
				else
				{
					ft_rra(w, 1);
					i++;
				}
			}
			else
			{
				if (w->a->elem[0] != s[0] && ((w->a->elem[0] != s[0] && w->a->elem[1] != b[0]) || (w->a->elem[0] != b[0] && w->a->elem[1] != s[0])) &&
				w->a->elem[0] != s[1] && ((w->a->elem[0] != s[1] && w->a->elem[1] != b[1]) || (w->a->elem[0] != b[1] && w->a->elem[1] != s[1])))
				{
					ft_pb(w, 1);
//					ft_print_stack(w);
					i++;
				}
				else
				{
					ft_rra(w, 1);
					i++;
				}
			}
		}
		b[0] = s[0];
		b[1] = s[1];
		s[0] = ft_intsm(w->b, m[0]);
		s[1] = ft_intsm(w->b, m[1]);
		while (w->b->size > 1 + tmp)
		{
			if (w->b->elem[0] > w->b->elem[1])
			{
				if (w->b->elem[0] != s[0] && ((w->b->elem[0] != s[0] && w->b->elem[1] != m[0]) || (w->b->elem[0] != b[0] && w->b->elem[1] != s[0])) &&
				w->b->elem[0] != s[1] && ((w->b->elem[0] != s[1] && w->b->elem[1] != m[1]) || (w->b->elem[0] != b[1] && w->b->elem[1] != s[1])))
				{
					ft_pa(w, 1);
//					ft_print_stack(w);
					i++;
				}
				else
				{
					ft_rrb(w, 1);
					i++;
				}
			}
			else
			{
					ft_sb(w, 1);
//					ft_print_stack(w);
					i++;
				if (w->b->elem[0] != s[0] && ((w->b->elem[0] != s[0] && w->b->elem[1] != m[0]) || (w->b->elem[0] != b[0] && w->b->elem[1] != s[0])) &&
					w->b->elem[0] != s[1] && ((w->b->elem[0] != s[1] && w->b->elem[1] != m[1]) || (w->b->elem[0] != b[1] && w->b->elem[1] != s[1])))
				{
					ft_pa(w, 1);
//					ft_print_stack(w);
					i++;
				}
				else
				{
					ft_rrb(w, 1);
					i++;
				}
			}
		}
		if (w->b->elem[0] < w->b->elem[1])
		{
			ft_sb(w, 1);
//			ft_print_stack(w);
			i++;
		}
		m[0] = s[0];
		m[1] = s[1];
		s[0] = ft_intsb(w->a, b[0]);
		s[1] = ft_intsb(w->a, b[1]);
		if (ft_chek_pars(w) == 0)
		{
			while (tmp--)
				ft_pa(w, 1);
			ft_pa(w, 1);
			i++;
//			ft_printf("operation - %d\n", i);
			return ;
		}
		tmp++;
		j--;
	}
	ft_pa(w, 1);
	i++;
//	ft_printf("operation - %d\n", i);
}
