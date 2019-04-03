/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <fschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:39:33 by fschille          #+#    #+#             */
/*   Updated: 2019/03/18 15:08:31 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"

int		ft_print_s(char *s, t_arg *flag)
{
	int		ret;

	ret = 0;
	if (flag->minus == 0 && flag->zero == 0 &&
	flag->width == 0 && flag->accuracy == -1)
		ft_putstr(s);
	else
	{
		if (flag->accuracy > -1)
			s = ft_strsub(s, 0, flag->accuracy);
		if (flag->zero == 1 && flag->minus == 0)
			wit(flag->width - ft_strlen(s), '0');
		if (flag->minus == 0 && flag->zero == 0)
			wit(flag->width - ft_strlen(s), ' ');
		ft_putstr(s);
		if (flag->minus == 1)
			wit(flag->width - ft_strlen(s), ' ');
	}
	if (flag->width > 0)
		ret = flag->width;
	if (flag->width < (int)ft_strlen(s))
		ret = ft_strlen(s);
	free(s);
	free(flag);
	return (ret);
}

char	*ft_write_s(va_list ap)
{
	char	*s;
	char	*tmp;

	tmp = va_arg(ap, char*);
	if (tmp == NULL)
		s = ft_strdup("(null)");
	else
		s = ft_strdup(tmp);
	return (s);
}
