/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:26:31 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/11 15:17:30 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_flag_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags ft_flag_width(char c, t_flags flags)
{
	flags.width = flags.width * 10 + (c - '0');
	return (flags);
}

int ft_flag_precision(const char *format, size_t i, t_flags *flags, va_list ap)
{
	flags->precision = 0;
	i++;
	while (format[i] >= '0' && format[i] <= '9')
	{
		flags->precision = flags->precision * 10 + (format[i] - '0');
		i++;
	}
	return (i);
}
