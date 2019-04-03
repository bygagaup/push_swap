/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <fschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:53:45 by fschille          #+#    #+#             */
/*   Updated: 2018/11/27 15:19:33 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*res;
	char	*pro;

	i = 0;
	res = (char*)dst;
	pro = (char*)src;
	while (i < n)
	{
		res[i] = pro[i];
		i++;
	}
	return (dst);
}
