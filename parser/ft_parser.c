/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:16:22 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/11 15:33:57 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_find_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u')
		return (1);
	else if (c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static void ft_parse_flags(const char *format, t_flags *flags)
{
	if (*format == 'c')
		flags->type = 1;
	else if (*format == 's')
		flags->type = 2;
	else if (*format == 'p')
		flags->type = 3;
	else if (*format == 'd')
		flags->type = 4;
	else if (*format == 'i')
		flags->type = 5;
	else if (*format == 'u')
		flags->type = 6;
	else if (*format == 'x')
		flags->type = 7;
	else if (*format == 'X')
		flags->type = 8;
	else if (*format == '%')
		flags->type = 9;
}

int ft_parser(const char *format, size_t i, t_flags *flags, va_list ap)
{
	while (1)
	{
		if (format[i] == '0' && !(flags->width) && !(flags->minus))
			flags->zero = 1;
		if (format[i] == '.')
			i = ft_flag_precision(format, i, flags, ap);
		if (format[i] == '-')
			flags = ft_flag_minus(flags);
		if (format[i] == '+')
			flags->plus = 1;
		if (format[i] == '#')
			flags->sharp = 1;
		if (format[i] >= '0' && format[i] <= '9')
			flags = ft_flag_width(format[i], flags)
		if (ft_find_type(format[i]))
		{
			ft_parse_flags(&format[i], flags);
			break;
		}
		i++;
	}
	return (i);
}