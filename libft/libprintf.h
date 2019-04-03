/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <fschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 23:45:10 by fschille          #+#    #+#             */
/*   Updated: 2019/03/18 13:44:57 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H
# include <stdarg.h>

typedef	struct		s_arg
{
	int				minus;
	int				plus;
	int				space;
	int				oktotorp;
	int				zero;
	int				width;
	int				accuracy;
	int				specifier;
}					t_arg;

int					ft_printf(const char *format, ...);
int					ft_discover(const char *format, va_list ap,
int	i_flag, int i);
int					ft_printarg(va_list ap, t_arg *flag, char conver);
char				ft_write_c(va_list ap);
int					ft_print_c(char c, t_arg *flag);
int					ft_print_s(char *s, t_arg *flag);
char				*ft_write_s(va_list ap);
int					ft_print_p(char *p, t_arg *flag, int ret);
char				*ft_write_p(va_list ap);
char				*ft_write_d(va_list ap, t_arg *flag);
int					ft_print_d(char *d, t_arg *flag, char sign,
int ret);
int					wit(int size, char sym);
char				*ft_write_o(va_list ap, t_arg *flag);
int					ft_print_o(char *o, t_arg *flag, int ret);
char				*ft_write_u(va_list ap, t_arg *flag);
int					ft_print_u(char *u, t_arg *flag, int ret);
char				*ft_write_x(va_list ap, t_arg *flag);
int					ft_print_x(char *x, t_arg *flag, int ret);
char				*ft_write_xx(va_list ap, t_arg *flag);
int					ft_print_xx(char *x, t_arg *flag);
char				*ft_after_before_point(long double f, int accuracy,
char **before_point, int *last);
char				*ft_double(long double f, t_arg *flag);
char				*ft_write_f(va_list ap, t_arg *flag);
char				ft_serchsign(char **d, t_arg *flag);
int					ft_sig(char sign);
int					ft_print_f(char *f, t_arg *flag, char sign, int ret);
void				ft_print_f_check(char **d, t_arg **flag, char *sign,
int *ret);

#endif
