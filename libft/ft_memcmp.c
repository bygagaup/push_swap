/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <fschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:40:31 by fschille          #+#    #+#             */
/*   Updated: 2018/12/03 18:34:33 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_dub;
	unsigned char	*s2_dub;

	i = 0;
	s1_dub = (unsigned char*)s1;
	s2_dub = (unsigned char*)s2;
	while (i < n)
	{
		if (s1_dub[i] != s2_dub[i])
			return (s1_dub[i] - s2_dub[i]);
		i++;
	}
	return (0);
}
