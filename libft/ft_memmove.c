/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <fschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 21:20:14 by fschille          #+#    #+#             */
/*   Updated: 2018/12/01 19:50:31 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*res;
	char	*pro;

	i = 0;
	res = (char*)dst;
	pro = (char*)src;
	if ((dst - src) < 0)
	{
		while (i < len)
		{
			res[i] = pro[i];
			i++;
		}
	}
	else
		while (len--)
			res[len] = pro[len];
	return (dst);
}
