/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:51:51 by fschille          #+#    #+#             */
/*   Updated: 2019/03/27 16:51:52 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int			ft_check_repeat(t_g *w, int i, int tmp, int size)
{
	if (!w->a)
		return (0);
	size = w->a->size - 1;
	while (tmp <= size)
	{
		while (i <= size)
		{
			if (i != tmp)
			{
				if (w->a->elem[tmp] == w->a->elem[i])
				{
					free(w->a->elem);
					free(w->a);
					free(w->b->elem);
					free(w->b);
					free(w);
					return (0);
				}
			}
			i++;
		}
		i = 0;
		tmp++;
	}
	return (1);
}

static int	ft_check_num_sp(char *argv)
{
	int		i;

	i = 0;
	while (argv[i])
	{
		if ((argv[i] >= '0' && argv[i] <= '9') || argv[i] == ' ')
			i++;
		else if (argv[i] == '-' && argv[i + 1] >= '0' && argv[i + 1] <= '9')
		{
			i++;
			while (argv[i] >= '0' && argv[i] <= '9')
			{
				i++;
				if (argv[i] == ' ' || argv[i] == '\0')
					break ;
				else if (argv[i] < '0' || argv[i] > '9')
					return (0);
			}
		}
		else
			return (0);
	}
	return (1);
}

char		*ft_check_argv(int argc, char **argv)
{
	char	*str;
	int		i;

	str = ft_strnew(0);
	i = 1;
	while (i < argc)
	{
		if (ft_check_num_sp(argv[i]))
			i++;
		else
			return (NULL);
	}
	i = 1;
	str = ft_strjoin_free(str, argv[i++], 1, 0);
	while (i < argc)
	{
		str = ft_strjoin_free(str, " ", 1, 0);
		str = ft_strjoin_free(str, argv[i], 1, 0);
		i++;
	}
	return (str);
}
