/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:49:21 by fschille          #+#    #+#             */
/*   Updated: 2019/03/21 16:49:24 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"

void	ft_print_o_check(char **o, t_arg **flag, int *ret)
{
	if ((*flag)->width > (int)ft_strlen(*o) &&
		(*flag)->accuracy > (int)ft_strlen(*o) && (*flag)->minus == 0)
		(*ret) += wit((*flag)->width - (*flag)->accuracy, ' ');
	if ((*flag)->minus == 0 && ((*flag)->zero == 0 || ((*flag)->zero == 1 &&
	(*flag)->accuracy <= (int)ft_strlen(*o) && (*flag)->accuracy != -1)) &&
		(*flag)->accuracy <= (int)ft_strlen(*o) && !((*o)[0] == '0' &&
		(*flag)->accuracy == 0 && (*flag)->width >= 1))
		(*ret) += wit((*flag)->width - ft_strlen(*o) - (*flag)->oktotorp, ' ');
	if ((*o)[0] == '0' && (*flag)->accuracy == 0 && (*flag)->width >= 1)
		(*ret) += wit((*flag)->width, ' ');
	if (((*flag)->zero == 1 && (*flag)->minus == 0) || (*flag)->accuracy > -1)
	{
		if ((*flag)->oktotorp == 1)
			ft_putstr("0");
		(*ret) += (*flag)->oktotorp;
		((*flag)->accuracy > -1) ? ((*ret) += wit((*flag)->accuracy -
		ft_strlen(*o) - (*flag)->oktotorp, '0')) : ((*ret) +=
		wit((*flag)->width - ft_strlen(*o) - (*flag)->oktotorp, '0'));
		if (!((*flag)->accuracy == 0 && (*o)[0] == '0'))
		{
			ft_putstr(*o);
			(*ret) += ft_strlen(*o);
		}
	}
}

void	ft_print_o_check2(char **o, t_arg **flag, int *ret)
{
	if ((*flag)->minus == 1 || ((*flag)->minus == 0 && (*flag)->zero == 0 &&
	(*flag)->accuracy == -1))
		if (!(((*flag)->zero == 1 && (*flag)->minus == 0) || (*flag)->accuracy
		> -1))
		{
			if ((*flag)->oktotorp == 1)
				ft_putstr("0");
			ft_putstr(*o);
			(*ret) += ft_strlen(*o) + (*flag)->oktotorp;
		}
	if ((*flag)->width > (int)ft_strlen(*o) &&
		(*flag)->accuracy > (int)ft_strlen(*o) && (*flag)->minus == 1)
		(*ret) += wit((*flag)->width - (*flag)->accuracy, ' ');
	if ((*flag)->minus == 1 && ((*flag)->zero == 0 || ((*flag)->zero == 1 &&
	(*flag)->accuracy <= (int)ft_strlen(*o))) &&
		(*flag)->accuracy <= (int)ft_strlen(*o))
		(*ret) += wit((*flag)->width - ft_strlen(*o) - (*flag)->oktotorp, ' ');
}

int		ft_print_o(char *o, t_arg *flag, int ret)
{
	if (o[0] == '0' && flag->accuracy != 0)
		flag->oktotorp = 0;
	if (flag->minus == 0 && flag->zero == 0 &&
		flag->width == 0 && flag->accuracy == -1)
	{
		if (flag->oktotorp == 1)
			ft_putstr("0");
		ft_putstr(o);
		ret += (int)ft_strlen(o) + flag->oktotorp;
	}
	else
	{
		ft_print_o_check(&o, &flag, &ret);
		ft_print_o_check2(&o, &flag, &ret);
	}
	free(o);
	free(flag);
	return (ret);
}

char	*ft_write_o(va_list ap, t_arg *flag)
{
	unsigned long long int	i;

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
	return (ft_utoa_base(i, 8));
}
