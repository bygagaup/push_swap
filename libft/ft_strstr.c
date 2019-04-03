/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <fschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:09:19 by fschille          #+#    #+#             */
/*   Updated: 2018/11/27 15:37:46 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		x;

	i = 0;
	j = 0;
	x = 0;
	if (needle[0] == '\0' && (haystack[0] == '\0' || needle[0] == '\0'))
		return ((char*)&haystack[x - j]);
	if (haystack[0] == '\0')
		return (NULL);
	while (haystack[i])
	{
		j = 0;
		while (needle[j] && haystack[x] == needle[j])
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
