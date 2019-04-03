/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_discover.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <fschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:56:18 by fschille          #+#    #+#             */
/*   Updated: 2019/03/18 17:45:02 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"

static t_arg	*ft_newflag(t_arg *flag)
{
	flag->minus = 0;
	flag->plus = 0;
	flag->space = 0;
	flag->oktotorp = 0;
	flag->zero = 0;
	flag->width = 0;
	flag->accuracy = -1;
	flag->specifier = 0;
	return (flag);
}

static void		ft_seachflag(t_arg *flag, char *elem, int i)
{
	if (elem[i] == '-')
		flag->minus = 1;
	if (elem[i] == '+')
		flag->plus = 1;
	if (elem[i] == ' ')
		flag->space = 1;
	if (elem[i] == '#')
		flag->oktotorp = 1;
	if (elem[i] == '0')
		flag->zero = 1;
	if (flag->specifier == 0)
	{
		if (elem[i] == 'h')
			flag->specifier = 2;
		if (elem[i] == 'l')
			flag->specifier = 4;
		if (elem[i + 1])
			if (elem[i] == 'h' && elem[i + 1] == 'h')
				flag->specifier = 1;
		if (elem[i + 1])
			if (elem[i] == 'l' && elem[i + 1] == 'l')
				flag->specifier = 3;
		if (elem[i] == 'L')
			flag->specifier = 5;
	}
}

static t_arg	*ft_addf(char *flags, int i)
{
	t_arg	*flag;

	flag = malloc(sizeof(t_arg));
	flag = ft_newflag(flag);
	while (flags[i])
		if (flags[i] >= '1' && flags[i] <= '9' && flag->width == 0)
		{
			flag->width = ft_atoi(flags + i);
			while (flags[i] >= '0' && flags[i] <= '9')
				i++;
		}
		else if (flags[i] == '.')
		{
			i++;
			flag->accuracy = ft_atoi(flags + i);
			while (flags[i] >= '0' && flags[i] <= '9')
				i++;
		}
		else if (flags[i] < '1' || flags[i] > '9')
			ft_seachflag(flag, flags, i++);
		else
			i++;
	free(flags);
	return (flag);
}

static int		ft_check(char f, int *i_f, int l)
{
	if (f == '-' || f == '+' || f == ' ' || f == '#' || f == '0' ||
		f == 'h' || f == 'l' || f == 'L' || f == '.' || (f >= '0' && f <= '9'))
		return (1);
	if (f == 'c' || f == 's' ||
		f == 'p' || f == 'd' || f == 'i' ||
		f == 'o' || f == 'u' || f == 'x' ||
		f == 'X' || f == 'f' || f == '%')
		return (0);
	else
	{
		if (l == 1)
			return (-1);
		*i_f = 0;
		return (0);
	}
}

int				ft_discover(const char *f, va_list ap, int i_f, int i)
{
	int		r;

	r = 0;
	while (f[i])
		if (f[i] == '%')
		{
			i++;
			while (f[i + i_f] && ft_check(f[i + i_f], &i_f, 0))
				i_f++;
			r = r + ft_printarg(ap, ft_addf(ft_strsub(f, i, i_f), 0),
			f[i + i_f]);
			if (ft_check(f[i + i_f], &i_f, 1) == -1)
				i = i + i_f;
			else if (i < (int)ft_strlen(f) - 1)
				i = i + 1 + i_f;
			else
				(i = (int)ft_strlen(f) - i_f);
			i_f = 0;
		}
		else
		{
			ft_putchar(f[i++]);
			r++;
		}
	return (r);
}
