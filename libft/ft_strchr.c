/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <fschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:41:15 by fschille          #+#    #+#             */
/*   Updated: 2018/12/03 19:41:15 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] || s[i] == c)
	{
		if (s[i + 1] == c && s[i + 1] == '\0')
			return ((char*)&s[i + 1]);
		if (s[i] == c)
			return ((char*)&s[i]);
		i++;
	}
	return (NULL);
}
