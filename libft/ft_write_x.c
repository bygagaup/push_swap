/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 17:55:06 by fschille          #+#    #+#             */
/*   Updated: 2019/03/23 17:55:11 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"

void	ft_print_x_check(char **x, t_arg **flag, int *ret)
{
	if ((*flag)->width > (int)ft_strlen(*x) &&
	(*flag)->accuracy > (int)ft_strlen(*x) && (*flag)->minus == 0)
		(*ret) += wit((*flag)->width - (*flag)->accuracy -
		((*flag)->oktotorp * 2), ' ');
	if ((*flag)->minus == 0 && ((*flag)->zero == 0 || ((*flag)->zero == 1 &&
	(*flag)->accuracy <= (int)ft_strlen(*x) && (*flag)->accuracy != -1)) &&
	(*flag)->accuracy <= (int)ft_strlen(*x) && !((*x)[0] == '0' &&
	(*flag)->accuracy == 0 && (*flag)->width >= 1))
		*ret += wit((*flag)->width - ft_strlen(*x) - (*flag)->oktotorp * 2, 32);
	if ((*x)[0] == '0' && (*flag)->accuracy == 0 && (*flag)->width >= 1)
		(*ret) += wit((*flag)->width, ' ');
	if (((*flag)->zero == 1 && (*flag)->minus == 0) || (*flag)->accuracy > -1)
	{
		if ((*flag)->oktotorp == 1)
			ft_putstr("0x");
		(*ret) += ((*flag)->oktotorp * 2);
		((*flag)->accuracy > -1) ? ((*ret) += wit((*flag)->accuracy -
		ft_strlen(*x), '0')) : ((*ret) += wit((*flag)->width -
		ft_strlen(*x) - ((*flag)->oktotorp * 2), '0'));
		if (!((*flag)->accuracy == 0 && (*x)[0] == '0'))
		{
			ft_putstr(*x);
			(*ret) += ft_strlen(*x);
		}
	}
}

void	ft_print_x_check2(char **x, t_arg **flag, int *ret)
{
	if ((*flag)->minus == 1 || ((*flag)->minus == 0 && (*flag)->zero == 0 &&
	(*flag)->accuracy == -1))
	{
		if (!(((*flag)->zero == 1 && (*flag)->minus == 0) ||
		(*flag)->accuracy > -1))
		{
			if ((*flag)->oktotorp == 1)
				ft_putstr("0x");
			ft_putstr(*x);
			(*ret) += ft_strlen(*x) + ((*flag)->oktotorp * 2);
		}
	}
	if ((*flag)->width > (int)ft_strlen(*x) &&
		(*flag)->accuracy > (int)ft_strlen(*x) && (*flag)->minus == 1)
		(*ret) += wit((*flag)->width - (*flag)->accuracy -
		((*flag)->oktotorp * 2), ' ');
	if ((*flag)->minus == 1 && ((*flag)->zero == 0 || ((*flag)->zero == 1 &&
	(*flag)->accuracy <= (int)ft_strlen(*x))) &&
		(*flag)->accuracy <= (int)ft_strlen(*x))
		(*ret) += wit((*flag)->width - ft_strlen(*x) -
		((*flag)->oktotorp * 2), ' ');
}

int		ft_print_x(char *x, t_arg *flag, int ret)
{
	if (x[0] == '0')
		flag->oktotorp = 0;
	if (flag->minus == 0 && flag->zero == 0 &&
		flag->width == 0 && flag->accuracy == -1)
	{
		if (flag->oktotorp == 1)
			ft_putstr("0x");
		ft_putstr(x);
		ret += (int)ft_strlen(x) + (flag->oktotorp * 2);
	}
	else
	{
		ft_print_x_check(&x, &flag, &ret);
		ft_print_x_check2(&x, &flag, &ret);
	}
	free(x);
	free(flag);
	return (ret);
}

char	*ft_write_x(va_list ap, t_arg *flag)
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
	return (ft_strlowcase(ft_utoa_base(i, 16)));
}
