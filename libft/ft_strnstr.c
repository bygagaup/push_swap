/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <fschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:39:45 by fschille          #+#    #+#             */
/*   Updated: 2018/12/03 19:51:16 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	x;

	i = 0;
	j = 0;
	x = 0;
	if (needle[0] == '\0' && (haystack[0] == '\0' || needle[0] == '\0'))
		return ((char*)&haystack[x - j]);
	if (haystack[0] == '\0')
		return (NULL);
	while (haystack[i] && (i + j) < len)
	{
		j = 0;
		while (needle[j] && haystack[x] == needle[j] && (i + j) < len)
		{
			if (needle[j + 1] == '\0')
				return ((char*)&haystack[x - j]);
			x++;
			j++;
		}
		i++;
		x = i;
	}
	return (NULL);
}
