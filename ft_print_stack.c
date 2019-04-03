/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:38:50 by fschille          #+#    #+#             */
/*   Updated: 2019/04/03 16:31:14 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void		ft_print_stack(t_g *w)
{
	int		i;
	int		i_a;
	int		i_b;
	char	*c_a;
	char	*c_b;

	i = 0;
	i_a = w->a->size;
	i_b = w->b->size;
	ft_printf("|-----------|-----------|\n");
	ft_printf("|         a | b         |\n|-----------|-----------|\n");
	while (i <= w->a->max)
	{
		if (i_a > 0)
		    c_a = ft_itoa(w->a->elem[i]);
		else
			c_a = ft_strdup(" ");
		if (i_b > 0)
			c_b = ft_itoa(w->b->elem[i]);
		else
			c_b = ft_strdup(" ");
		ft_printf("|%10s | %-10s|\n", c_a, c_b);
		i_b--;
		i_a--;
		free(c_a);
		free(c_b);
		i++;
	}
	ft_printf("|-----------|-----------|\n\n");
}
