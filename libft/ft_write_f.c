/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 12:57:55 by fschille          #+#    #+#             */
/*   Updated: 2019/03/24 12:57:57 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"

int			ft_print_f(char *f, t_arg *flag, char sign, int ret)
{
	ft_print_f_check(&f, &flag, &sign, &ret);
	if ((flag->zero == 1 && flag->minus == 0))
		ret += wit(flag->width - ft_strlen(f) - ft_sig(sign), '0');
	ft_putstr(f);
	ret += ft_strlen(f);
	if (flag->minus == 1 && flag->width > (int)ft_strlen(f) &&
		flag->accuracy > (int)ft_strlen(f))
		sign != 0 ? (ret += wit(flag->width - flag->accuracy - 1, ' ')) :
		(ret += wit(flag->width - flag->accuracy, ' '));
	if ((flag->minus == 1 && flag->zero == 0 &&
		flag->accuracy <= (int)ft_strlen(f)) ||
		(flag->minus == 1 && flag->zero == 1))
		ret += wit(flag->width - ft_strlen(f) - ft_sig(sign), ' ');
	free(f);
	free(flag);
	return (ret);
}

void		ft_rounding(char **number, int lass, int i)
{
	if (lass >= 5)
	{
		if ((*number)[i] >= '0' && (*number)[i] <= '8')
			(*number)[i] += 1;
		else if ((*number)[i] == '9')
		{
			(*number)[i--] -= 9;
			while (i >= 0)
			{
				if ((*number)[i] == '9')
					(*number)[i] -= 9;
				else if ((*number)[i] >= '0' && (*number)[i] <= '8')
				{
					(*number)[i] += 1;
					break ;
				}
				i--;
			}
			if ((*number)[0] == '0')
				(*number) = ft_strjoin_free("1", (*number), 0, 1);
			if ((*number)[0] == '-' && (*number)[1] == '0')
				(*number) = ft_strjoin_free("-1", ft_strsub_free((*number), 1,
				ft_strlen(*number)), 0, 1);
		}
	}
}

char		*ft_after_before_point(long double f, int accuracy,
char **before_point, int *last)
{
	char				*after_char;
	long long int		before;
	int					i;

	if (accuracy == -1)
		accuracy = 6;
	*before_point = ft_itoa((long long int)f);
	if (f < 0)
		f = -f;
	after_char = ft_strnew((size_t)accuracy + 1);
	before = f;
	f -= before;
	i = 0;
	while (i < accuracy)
	{
		f *= 10;
		before = f;
		after_char[i++] = f + '0';
		f -= before;
	}
	f *= 10;
	if (i == accuracy)
		*last = f;
	after_char[i] = '\0';
	return (after_char);
}

char		*ft_double(long double f, t_arg *flag)
{
	char	*after_point;
	char	*before_point;
	char	*number;
	int		last;

	after_point = ft_after_before_point(f, flag->accuracy,
	&before_point, &last);
	if ((int)ft_strlen(after_point) == 0)
	{
		number = ft_strdup(before_point);
		free(before_point);
		free(after_point);
	}
	else
	{
		number = ft_strjoin_free(before_point, ".", 1, 0);
		number = ft_strjoin_free(number, after_point, 1, 1);
	}
	ft_rounding(&number, last, ft_strlen(number) - 1);
	if (flag->oktotorp == 1 && flag->accuracy == 0)
		number = ft_strjoin_free(number, ".", 1, 0);
	return (number);
}

char		*ft_write_f(va_list ap, t_arg *flag)
{
	long double	f;

	if (flag->specifier == 5)
		f = va_arg(ap, long double);
	else if (flag->specifier == 3)
		f = va_arg(ap, double);
	else
		f = va_arg(ap, double);
	return (ft_double(f, flag));
}
