/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <fschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:31:49 by fschille          #+#    #+#             */
/*   Updated: 2019/02/16 15:49:44 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"

char		ft_serchsign(char **d, t_arg *flag)
{
	char	sign;
	char	*tmp;

	sign = 0;
	if (*d[0] != '-' && flag->space > 0 && flag->plus == 0)
		sign = ' ';
	if (*d[0] != '-' && flag->plus > 0)
		sign = '+';
	if (*d[0] == '-')
	{
		sign = '-';
		tmp = *d;
		*d = ft_strsub(*d, 1, ft_strlen(*d));
		free(tmp);
	}
	return (sign);
}

int			ft_sig(char sign)
{
	if (sign == 0)
		return (0);
	else
		return (1);
}

void		ft_print_d_check(char **d, t_arg **flag, char *sign, int *ret)
{
	*sign = ft_serchsign(&(*d), (*flag));
	if ((*flag)->minus == 0 && (*flag)->width > (int)ft_strlen(*d) &&
	((*flag)->accuracy > (int)ft_strlen(*d) || ((*flag)->accuracy == 0 &&
	(*d)[0] == '0')))
		*sign != 0 ? (*ret += wit((*flag)->width - (*flag)->accuracy - 1, ' '))
		: (*ret += wit((*flag)->width - (*flag)->accuracy, ' '));
	if ((*flag)->minus == 0 && ((*flag)->accuracy != -1 || (*flag)->zero == 0)
	&& (*flag)->accuracy <= (int)ft_strlen(*d) &&
	!((*flag)->accuracy == 0 && (*d)[0] == '0'))
		*ret += wit((*flag)->width - ft_strlen(*d) - ft_sig(*sign), ' ');
	if (*sign != 0)
	{
		ft_putchar(*sign);
		(*ret)++;
	}
}

int			ft_print_d(char *d, t_arg *flag, char sign, int ret)
{
	ft_print_d_check(&d, &flag, &sign, &ret);
	if ((flag->zero == 1 && flag->minus == 0) || flag->accuracy > -1)
		flag->accuracy > -1 ? (ret += wit(flag->accuracy - ft_strlen(d), '0')) :
		(ret += wit(flag->width - ft_strlen(d) - ft_sig(sign), '0'));
	if (!(flag->accuracy == 0 && d[0] == '0'))
	{
		ft_putstr(d);
		ret += ft_strlen(d);
		if (flag->minus == 1 && flag->width > (int)ft_strlen(d) &&
		flag->accuracy > (int)ft_strlen(d))
			sign != 0 ? (ret += wit(flag->width - flag->accuracy - 1, ' ')) :
			(ret += wit(flag->width - flag->accuracy, ' '));
		if ((flag->minus == 1 && flag->zero == 0 &&
		flag->accuracy <= (int)ft_strlen(d)) ||
			(flag->minus == 1 && flag->zero == 1))
			ret += wit(flag->width - ft_strlen(d) - ft_sig(sign), ' ');
	}
	free(d);
	free(flag);
	return (ret);
}

char		*ft_write_d(va_list ap, t_arg *flag)
{
	long long int	i;
	char			*d;

	i = va_arg(ap, long long int);
	if (flag->specifier == 1)
		i = (signed char)i;
	else if (flag->specifier == 2)
		i = (short int)i;
	else if (flag->specifier == 3)
		i = (long long int)i;
	else if (flag->specifier == 4)
		i = (long int)i;
	else
		i = (int)i;
	d = ft_itoa(i);
	return (d);
}
