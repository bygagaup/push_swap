/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <fschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:34:24 by fschille          #+#    #+#             */
/*   Updated: 2019/03/18 13:44:00 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_mynbr(char *str, long long n, int size)
{
	int i;

	i = 0;
	if (n == (long long)-9223372036854775807 - 1)
	{
		str[i] = '-';
		i++;
		str[i] = '9';
		i++;
		n = 223372036854775808;
	}
	if (n < 0)
	{
		str[i] = '-';
		i++;
		n = -n;
	}
	if (n >= 10)
	{
		ft_mynbr(str, n / 10, size - 1);
		str[size] = (n % 10) + '0';
	}
	else
		str[size] = n + '0';
	return (str);
}

char		*ft_itoa(long long n)
{
	int		size;
	char	*str;

	size = ft_intlen(n);
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	ft_mynbr(str, n, size - 1);
	str[size] = '\0';
	return (str);
}
