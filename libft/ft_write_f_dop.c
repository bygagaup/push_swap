/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_f_dop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:37:10 by fschille          #+#    #+#             */
/*   Updated: 2019/03/25 16:37:12 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"

void		ft_print_f_check(char **f, t_arg **flag, char *sign, int *ret)
{
	*sign = ft_serchsign(&(*f), (*flag));
	if ((*flag)->minus == 0 && (*flag)->width > (int)ft_strlen(*f) &&
	((*flag)->accuracy > (int)ft_strlen(*f) || ((*flag)->accuracy == 0 &&
	(*f)[0] == '0')))
		*sign != 0 ? ((*ret) += wit((*flag)->width - (*flag)->accuracy - 1,
		' ')) : ((*ret) += wit((*flag)->width - ft_strlen(*f) -
		ft_sig(*sign), ' '));
	if ((*flag)->minus == 0 && (*flag)->zero == 0 && (*flag)->accuracy <=
	(int)ft_strlen(*f) && !((*flag)->accuracy == 0 && *f[0] == '0'))
		(*ret) += wit((*flag)->width - ft_strlen(*f) - ft_sig(*sign), ' ');
	if (*sign != 0)
	{
		ft_putchar(*sign);
		(*ret)++;
	}
}
