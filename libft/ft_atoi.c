/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <fschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 03:46:47 by fschille          #+#    #+#             */
/*   Updated: 2018/12/08 16:30:07 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				i;
	int				neg;
	long int		nbr;

	i = 0;
	neg = 1;
	nbr = 0;
	while (str[i] == '\t' || str[i] == '\r' || str[i] == '\f' || str[i] == '\v'
	|| str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (nbr * 10 / 10 != nbr)
			return (neg == 1 ? -1 : 0);
		nbr = nbr * 10;
		nbr = nbr + str[i] - '0';
		i++;
	}
	return (int)(nbr * neg);
}
