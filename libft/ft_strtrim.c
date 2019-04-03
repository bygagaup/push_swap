/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <fschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:03:07 by fschille          #+#    #+#             */
/*   Updated: 2018/12/08 17:00:02 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_spaces(char const *s, size_t *pass1, size_t *pass2, size_t i)
{
	*pass1 = 0;
	*pass2 = 0;
	while (s[*pass1] == ' ' || s[*pass1] == '\n' || s[*pass1] == '\t')
		(*pass1)++;
	while (s[i - *pass2] == ' ' || s[i - *pass2] == '\n'
	|| s[i - *pass2] == '\t')
		(*pass2)++;
	if (*pass1 == i + 1)
		return (0);
	return (1);
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	pass1;
	size_t	pass2;
	char	*str;

	if (!s)
		return (NULL);
	i = ft_strlen(s) - 1;
	if (ft_spaces(s, &pass1, &pass2, i) == 0)
	{
		str = ft_strnew(1);
		return (str);
	}
	str = (char*)malloc(sizeof(char) * (((i + 1) - pass1 - pass2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i + pass1 + pass2])
	{
		str[i] = s[i + pass1];
		i++;
	}
	str[i] = '\0';
	return (str);
}
