/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:51:13 by fschille          #+#    #+#             */
/*   Updated: 2019/04/03 16:51:15 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static void		ft_checker(t_g *w, int flag)
{
	char 	*line;
	char 	*str;

	str = ft_strnew(0);
	while (get_next_line(0, &line))
		str = ft_strjoin_free(str, line, 1, 1);
	ft_printf("%s\n", str);
	free(str);
}

int				main(int argc, char **argv)
{
	t_g		*w;
	int		flag;

	flag = 0;
	if (argc > 1 && ft_strcmp(argv[1], "-v") == 0)
	{
		flag = 1;
		argv++;
	}
	if (ft_creat_stack(ft_check_argv(argc - flag, argv), &w) == 1 && ft_check_repeat(w, 0, 0, 0) == 1)
	{
		ft_print_stack(w);
		ft_checker(w, flag);
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