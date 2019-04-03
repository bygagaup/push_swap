/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <fschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:31:49 by fschille          #+#    #+#             */
/*   Updated: 2019/02/16 15:49:44 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"

int		wit(int size, char sym)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putchar(sym);
		i++;
	}
	if (size > 0)
		return (size);
	else
		return (0);
}

int		ft_print_c(char c, t_arg *flag)
{
	int		ret;

	ret = 1;
	if (flag->minus == 0 && flag->zero == 0 && flag->width == 0)
		ft_putchar(c);
	else
	{
		if (flag->minus == 0 && flag->zero == 0)
			wit(flag->width - 1, ' ');
		if (flag->zero == 1 && flag->minus == 0)
			wit(flag->width - 1, '0');
		ft_putchar(c);
		if (flag->minus == 1)
			wit(flag->width - 1, ' ');
	}
	if (flag->width > 0)
		ret = flag->width;
	free(flag);
	return (ret);
}

char	ft_write_c(va_list ap)
{
	char	c;

	c = (char)va_arg(ap, int);
	return (c);
}
