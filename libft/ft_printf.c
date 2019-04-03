/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <fschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:09:54 by fschille          #+#    #+#             */
/*   Updated: 2019/02/16 14:56:56 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			res;

	va_start(ap, format);
	res = ft_discover(format, ap, 0, 0);
	va_end(ap);
	return (res);
}
