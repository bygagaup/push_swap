/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <fschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:00:41 by fschille          #+#    #+#             */
/*   Updated: 2018/12/05 19:38:03 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_i;
	size_t	src_i;

	i = 0;
	dst_i = ft_strlen(dst);
	src_i = ft_strlen(src);
	if (size > dst_i)
	{
		while (((dst_i + 1 + i) < size) && src[i])
		{
			dst[dst_i + i] = src[i];
			i++;
		}
		dst[dst_i + i] = '\0';
	}
	else
	{
		return (src_i + size);
	}
	return (dst_i + src_i);
}
