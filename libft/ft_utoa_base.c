/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:16:11 by fschille          #+#    #+#             */
/*   Updated: 2019/03/21 15:16:13 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_converter(int elem)
{
	if (elem > 9 && elem < 16)
		return (elem + 55);
	else
		return (elem + '0');
}

static int	ft_how_much(unsigned long long value, int base)
{
	int i;

	i = 0;
	while (value > (unsigned int)base)
	{
		value = value / base;
		i++;
	}
	return (i + 1);
}

char		*ft_utoa_base(unsigned long long value, int base)
{
	int		elem[ft_how_much(value, base)];
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = (char*)malloc(sizeof(char) * (ft_how_much(value, base) + 1));
	while (value >= (unsigned int)base)
	{
		elem[i] = value % base;
		value = value / base;
		i++;
	}
	elem[i++] = value;
	while (--i >= 0)
		res[j++] = ft_converter(elem[i]);
	res[j] = '\0';
	return (res);
}
