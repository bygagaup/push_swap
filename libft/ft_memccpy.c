/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <fschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:10:23 by fschille          #+#    #+#             */
/*   Updated: 2018/12/04 10:27:00 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*res;
	unsigned char	*pro;

	res = (unsigned char*)dst;
	pro = (unsigned char*)src;
	while (n)
	{
		if (*pro == (unsigned char)c)
		{
			*res = *pro;
			res++;
			return ((unsigned char*)res);
		}
		*res = *pro;
		res++;
		pro++;
		n--;
	}
	return (NULL);
}
