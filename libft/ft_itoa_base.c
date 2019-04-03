/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 06:07:12 by fschille          #+#    #+#             */
/*   Updated: 2019/03/20 06:07:15 by fschille         ###   ########.fr       */
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

static int	ft_how_much(long long value, int base)
{
	int i;

	i = 0;
	if (value < 0)
		value = -value;
	while (value > base)
	{
		value = value / base;
		i++;
	}
	return (i + 1);
}

static int	ft_sign(long long *value, int base)
{
	if (base == 10 && *value < 0)
	{
		*value = -(*value);
		return (1);
	}
	if (*value < 0)
	{
		*value = -(*value);
		return (0);
	}
	return (0);
}

char		*ft_itoa_base(long long value, int base)
{
	int		elem[ft_how_much(value, base)];
	int		i;
	int		j;
	int		neg;
	char	*res;

	i = 0;
	j = 0;
	neg = ft_sign(&value, base);
	res = (char*)malloc(sizeof(char) * (ft_how_much(value, base) + neg + 1));
	if (neg == 1)
		res[j++] = '-';
	while (value >= base)
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
