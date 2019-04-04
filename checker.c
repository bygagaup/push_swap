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

static void		ft_freemulstr(char ***mulstr)
{
	int i;

	i = 0;
	while ((*mulstr)[i])
	{
		free((*mulstr)[i]);
		i++;
	}
	free(*mulstr);
}

static void		ft_printchecker(t_g *w, char **mulstr, int flag, int i)
{
	while (mulstr[++i])
	{
		if (strcmp(mulstr[i], "sa") == 0)
			ft_sa(w, 0);
		else if (strcmp(mulstr[i], "sb") == 0)
			ft_sb(w, 0);
		else if (strcmp(mulstr[i], "ss") == 0)
			ft_ss(w, 0);
		else if (strcmp(mulstr[i], "pa") == 0)
			ft_pa(w, 0);
		else if (strcmp(mulstr[i], "pb") == 0)
			ft_pb(w, 0);
		else if (strcmp(mulstr[i], "ra") == 0)
			ft_ra(w, 0);
		else if (strcmp(mulstr[i], "rb") == 0)
			ft_rb(w, 0);
		else if (strcmp(mulstr[i], "rr") == 0)
			ft_rr(w, 0);
		else if (strcmp(mulstr[i], "rra") == 0)
			ft_rra(w, 0);
		else if (strcmp(mulstr[i], "rrb") == 0)
			ft_rrb(w, 0);
		else if (strcmp(mulstr[i], "rrr") == 0)
			ft_rrr(w, 0);
		if (flag == 1)
			ft_print_stack(w);
	}
}

static void			ft_checker(t_g *w, int flag)
{
	char 	*line;
	char 	*str;
	char 	**mulstr;
	int 	i;
	int 	check;

	str = ft_strnew(0);
	i = 0;
	check = 0;
	while (get_next_line(0, &line))
	{
		str = ft_strjoin_free(str, line, 1, 1);
		str = ft_strjoin_free(str, "\n", 1, 0);
	}
	mulstr = ft_strsplit(str, '\n');
	free(str);
	while (mulstr[i] && check == 0)
	{
		if ((strcmp(mulstr[i], "sa")) == 0 || (strcmp(mulstr[i], "sb")) == 0 || (strcmp(mulstr[i], "ss")) == 0 ||
		(strcmp(mulstr[i], "pa")) == 0 || (strcmp(mulstr[i], "pb")) == 0 || (strcmp(mulstr[i], "ra")) == 0 ||
		(strcmp(mulstr[i], "rb")) == 0 || (strcmp(mulstr[i], "rr")) == 0 ||(strcmp(mulstr[i], "rra")) == 0 ||
		(strcmp(mulstr[i], "rrb")) == 0 || (strcmp(mulstr[i], "rrr")) == 0)
			i++;
		else
			check = 1;

	}
	if (check == 0)
	{
		ft_printchecker(w, mulstr, flag, -1);
		if (ft_chek_pars(w) == 0)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	else
		ft_printf("Error\n");
	ft_freemulstr(&mulstr);
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
//		ft_print_stack(w);
		ft_checker(w, flag);
//	 	ft_print_stack(w);
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