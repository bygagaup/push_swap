/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 17:24:04 by fschille          #+#    #+#             */
/*   Updated: 2019/03/23 17:24:06 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"

void			ft_print_u_check(char **u, t_arg **flag, int *ret)
{
	ft_putstr(*u);
	(*ret) += ft_strlen(*u);
	if ((*flag)->minus == 1 && (*flag)->width > (int)ft_strlen(*u) &&
		(*flag)->accuracy > (int)ft_strlen(*u))
		(*ret) += wit((*flag)->width - (*flag)->accuracy, ' ');
	if (((*flag)->minus == 1 && (*flag)->zero == 0 &&
		(*flag)->accuracy <= (int)ft_strlen(*u)) ||
		((*flag)->minus == 1 && (*flag)->zero == 1))
		(*ret) += wit((*flag)->width - ft_strlen(*u), ' ');
}

int				ft_print_u(char *u, t_arg *flag, int ret)
{
	if (flag->minus == 0 && flag->width > (int)ft_strlen(u) &&
	(flag->accuracy > (int)ft_strlen(u) || (flag->accuracy == 0 &&
	u[0] == '0')))
		ret += wit(flag->width - flag->accuracy, ' ');
	if (flag->minus == 0 && (flag->accuracy != -1 || flag->zero == 0) &&
		flag->accuracy <= (int)ft_strlen(u) &&
		!(flag->accuracy == 0 && u[0] == '0'))
		ret += wit(flag->width - ft_strlen(u), ' ');
	if ((flag->zero == 1 && flag->minus == 0) || flag->accuracy > -1)
		flag->accuracy > -1 ? (ret += wit(flag->accuracy - ft_strlen(u), '0')) :
		(ret += wit(flag->width - ft_strlen(u), '0'));
	if (!(flag->accuracy == 0 && u[0] == '0'))
	{
		ft_print_u_check(&u, &flag, &ret);
	}
	free(u);
	free(flag);
	return (ret);
}

char			*ft_write_u(va_list ap, t_arg *flag)
{
	unsigned long long int	i;
	char					*d;

	i = va_arg(ap, unsigned long long int);
	if (flag->specifier == 1)
		i = (unsigned char)i;
	else if (flag->specifier == 2)
		i = (unsigned short int)i;
	else if (flag->specifier == 3)
		i = (unsigned long long int)i;
	else if (flag->specifier == 4)
		i = (unsigned long int)i;
	else
		i = (unsigned int)i;
	d = ft_utoa_base(i, 10);
	return (d);
}
