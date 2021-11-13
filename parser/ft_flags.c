/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:26:31 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/13 14:16:24 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_flag_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags ft_flag_width(va_list ap, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(ap, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
		flags.zero = 0;
	}
	return (flags);
}

t_flags ft_flag_digit(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = flags.width * 10 + (c - '0');
	return (flags);
}

int ft_flag_precision(const char *format, size_t i, t_flags *flags, va_list ap)
{
	i++;
	if (format[i] == '*')
	{
		flags->precision = va_arg(ap, int);
		i++;
	}
	else
	{
		flags->precision = 0;
		while (format[i] >= '0' && format[i] <= '9')
		{
			flags->precision = flags->precision * 10 + (format[i] - '0');
			i++;
		}
	}
	
	return (i);
}
