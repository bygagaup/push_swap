/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:53:50 by fschille          #+#    #+#             */
/*   Updated: 2019/03/27 17:53:52 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static int 		ft_check_num(char *str)
{
	int 	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

static void		ft_filling_stack(t_stc *a, char **mulstr)
{
	int		i;

	i = 0;
	while (mulstr[i])
	{
		a->elem[i] = ft_atoi(mulstr[i]);
		i++;
	}
	i = 0;
	while (mulstr[i])
	{
		ft_strdel(&mulstr[i]);
		i++;
	}
	free(mulstr);
}

static t_stc	*ft_new_stack(int len, int size)
{
	t_stc	*stc;

	stc = malloc(sizeof(t_stc));
	stc->elem = (int*)malloc(sizeof(int) * (len + 1));
	stc->max = len;
	stc->size = size;
	return (stc);
}

int				ft_creat_stack(char *str, t_g **w)
{
	char	**mulstr;
	int		i;

	i = 0;
	if (!str || ft_check_num(str) == 0)
	{
		if (str)
			free(str);
		return (0);
	}
	mulstr = ft_strsplit(str, ' ');
	free(str);
	while (mulstr[i])
		i++;
	(*w) = malloc(sizeof(t_g));
	(*w)->a = ft_new_stack(i - 1, i);
	(*w)->b = ft_new_stack(i - 1, 0);
	ft_filling_stack((*w)->a, mulstr);
	return (1);
}
