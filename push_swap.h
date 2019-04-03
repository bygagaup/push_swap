/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:32:10 by fschille          #+#    #+#             */
/*   Updated: 2019/03/27 13:32:13 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdio.h> //удалить

typedef	struct		s_stc
{
	int	max;
	int	*elem;
	int	size;
}					t_stc;

typedef	struct		s_g
{
	t_stc	*a;
	t_stc	*b;
}					t_g;

char				*ft_check_argv(int argc, char **argv);
int					ft_creat_stack(char *str, t_g **w);
void				ft_print_stack(t_g *w);
void				ft_operation_swap(t_stc *o);
void				ft_operation_push(t_stc *o1, t_stc *o2);
void				ft_operation_rot(t_stc *o);
void				ft_operation_rev_rot(t_stc *o);
void				ft_sa(t_g *w);
void				ft_sb(t_g *w);
void				ft_ss(t_g *w);
void				ft_pa(t_g *w);
void				ft_pb(t_g *w);
void				ft_ra(t_g *w);
void				ft_rb(t_g *w);
void				ft_rr(t_g *w);
void				ft_rra(t_g *w);
void				ft_rrb(t_g *w);
void				ft_rrr(t_g *w);
void				ft_sorting(t_g *w);
int 				ft_check_repeat(t_g *w, int i, int tmp, int size);

#endif
