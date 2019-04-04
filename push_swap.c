/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:31:16 by fschille          #+#    #+#             */
/*   Updated: 2019/03/27 13:31:18 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_g		*w;

	if (ft_creat_stack(ft_check_argv(argc, argv), &w) == 1 && ft_check_repeat(w, 0, 0, 0) == 1)
	{
//		ft_print_stack(w);
		ft_sorting(w);
		ft_print_stack(w);
		free(w->a->elem);
		free(w->a);
		free(w->b->elem);
		free(w->b);
		free(w);
	}
	else
		ft_printf("Error\n");
	return (0);
}
