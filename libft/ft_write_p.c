/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <fschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:31:49 by fschille          #+#    #+#             */
/*   Updated: 2019/02/16 15:49:44 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"

void	ft_print_p_check(char **p, t_arg **flag, int *ret)
{
	if ((*flag)->width > (int)ft_strlen(*p) &&
	(*flag)->accuracy > (int)ft_strlen(*p))
		(*ret) += wit((*flag)->width - (*flag)->accuracy - 2, ' ');
	if ((*flag)->minus == 0 && (*flag)->zero == 0 &&
	(*flag)->accuracy < (int)ft_strlen(*p))
		(*ret) += wit((*flag)->width - ft_strlen(*p) - 2, ' ');
	if (((*flag)->zero == 1 && (*flag)->minus == 0) || (*flag)->accuracy > -1)
	{
		ft_putstr("0x");
		(*ret) += 2;
		if ((*flag)->accuracy > -1)
			(*ret) += wit((*flag)->accuracy - ft_strlen(*p), '0');
		else
			(*ret) += wit((*flag)->width - ft_strlen(*p) - 2, '0');
		if ((*flag)->accuracy != 0)
		{
			ft_putstr(*p);
			(*ret) += ft_strlen(*p);
		}
	}
}

int		ft_print_p(char *p, t_arg *flag, int ret)
{
	if (flag->minus == 0 && flag->zero == 0 &&
		flag->width == 0 && flag->accuracy == -1)
	{
		ft_putstr("0x");
		ft_putstr(p);
		ret += (int)ft_strlen(p) + 2;
	}
	else
	{
		ft_print_p_check(&p, &flag, &ret);
		if (flag->minus == 1 || (flag->minus == 0 && flag->zero == 0 &&
		flag->accuracy == -1))
		{
			ft_putstr("0x");
			ft_putstr(p);
			ret += ft_strlen(p) + 2;
		}
		if (flag->minus == 1)
			ret += wit(flag->width - ft_strlen(p) - 2, ' ');
	}
	free(p);
	free(flag);
	return (ret);
}

char	*ft_write_p(va_list ap)
{
	unsigned long long	p;

	p = va_arg(ap, unsigned long long);
	return (ft_strlowcase(ft_utoa_base(p, 16)));
}
