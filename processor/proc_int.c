/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:52:46 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/15 19:16:10 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int proc_output_int(char *str, t_flags flags, int num)
{
	int l;

	l = 0;
	if (num < 0 && flags.precision >= 0)
		ft_putchar('-');
	else if (flags.plus == 1 && flags.precision >= 0)
		ft_putchar('+');
	else if (flags.space == 1 && (flags.minus == 1 || 
	flags.width < flags.precision || flags.width < ft_strlen(str)))
		ft_putchar(' ');
	if (flags.precision >=0)
		l += proc_width(flags.precision, ft_strlen(str), 1);
	l += ft_strlen(str);
	ft_putstr(str);
	return (l);
}

static int proc_put_int(char *str, t_flags flags, int num)
{
	int l;

	l = 0;
	if (flags.minus == 1)
		l += proc_output_int(str, flags, num);
	if ((num < 0 || flags.plus == 1 || (flags.space == 1 && flags.minus == 1)) 
	&& flags.zero == 0)
		flags.width--;
	if (flags.precision >= 0 && flags.precision < ft_strlen(str))
		flags.precision = ft_strlen(str);
	if (flags.precision >= 0)
		l += proc_width(flags.width, flags.precision, 0);
	else
		l += proc_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		l += proc_output_int(str, flags, num);
	return (l);
}

int proc_int(int num, t_flags *flags)
{
	int l;
	int buf_num;
	char *str;

	l = 0;
	buf_num = num;
	if (num < 0)
		num *= (-1);
	str = ft_itoa(num);
	if (flags->zero == 1 && flags->precision == -1 && (flags->plus == 1
	|| buf_num < 0 || flags->space == 1))
	{
		if (buf_num < 0)
			ft_putchar('-');
		else if (flags->plus == 1)
			ft_putchar('+');
		else if (flags->space == 1 && (flags->minus == 1 || 
		flags->width < ft_strlen(str)))
			ft_putchar(' ');
		flags->width--;
		l++;
	}
	l += proc_put_int(str, *flags, buf_num);
	free(str);
	return (l);
}
