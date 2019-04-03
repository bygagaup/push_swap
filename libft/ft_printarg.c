/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <fschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:05:33 by fschille          #+#    #+#             */
/*   Updated: 2019/03/18 15:07:23 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"

int		ft_printarg(va_list ap, t_arg *flag, char conver)
{
	if (conver == '%')
		return (ft_print_c('%', flag));
	if (conver == 'c')
		return (ft_print_c(ft_write_c(ap), flag));
	if (conver == 's')
		return (ft_print_s(ft_write_s(ap), flag));
	if (conver == 'p')
		return (ft_print_p(ft_write_p(ap), flag, 0));
	if (conver == 'd' || conver == 'i')
		return (ft_print_d(ft_write_d(ap, flag), flag, 0, 0));
	if (conver == 'o')
		return (ft_print_o(ft_write_o(ap, flag), flag, 0));
	if (conver == 'u')
		return (ft_print_u(ft_write_u(ap, flag), flag, 0));
	if (conver == 'x')
		return (ft_print_x(ft_write_x(ap, flag), flag, 0));
	if (conver == 'X')
		return (ft_print_xx(ft_write_xx(ap, flag), flag));
	if (conver == 'f')
		return (ft_print_f(ft_write_f(ap, flag), flag, 0, 0));
	else
		free(flag);
	return (0);
}
