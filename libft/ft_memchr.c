/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <fschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:44:40 by fschille          #+#    #+#             */
/*   Updated: 2018/12/06 19:48:42 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*res;
	size_t			i;

	res = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (res[i] == (unsigned char)c)
		{
			return ((unsigned char*)&res[i]);
		}
		i++;
	}
	return (NULL);
}
