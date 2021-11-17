/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:28:21 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/17 13:35:38 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int proc_strprec(char *str, int prec)
{
	int l;

	l = 0;
	while (str[l] && l < prec)
		ft_putchar(str[l++]);
	return (l);
}

int proc_string(char *str, t_flags *flags)
{
	int l;

	if (str == NULL)
		str = "(null)";
	l = 0;
	if (flags->precision >= 0 && flags->precision > ft_strlen(str))
		flags->precision = ft_strlen(str);
	if (flags->minus == 1)
	{
		if (flags->precision >= 0)
			l += proc_strprec(str, flags->precision);
		else
			l += proc_strprec(str, ft_strlen(str));
	}
	if (flags->precision >= 0)
		l += proc_width(flags->width, flags->precision, 0);
	else
		l += proc_width(flags->width, ft_strlen(str), 0);
	if (flags->minus == 0)
	{
		if (flags->precision >= 0)
			l += proc_strprec(str, flags->precision);
		else
			l += proc_strprec(str, ft_strlen(str));
	}
	return (l);
}
