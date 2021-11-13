/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:16:22 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/13 14:16:30 by mbutter          ###   ########.fr       */
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

static int ft_find_flag(char c)
{
	if (c == '.' || c == '-' || c == '+' || c == '0' || c == '#' || c == '*')
		return (1);
	return (0);
}

int ft_parser(const char *format, size_t i, t_flags *flags, va_list ap)
{
	while (1)
	{
		if (!ft_find_type(format[i]) && !ft_find_flag(format[i]) && !ft_isdigit(format[i]))
			break;
		if (format[i] == '0' && !(flags->width) && !(flags->minus))
			flags->zero = 1;
		if (format[i] == '.')
			i = ft_flag_precision(format, i, flags, ap);
		if (format[i] == '-')
			*flags = ft_flag_minus(*flags);
		if (format[i] == '*')
			*flags = ft_flag_width(ap, *flags);
		if (format[i] == '+')
			flags->plus = 1;
		if (format[i] == '#')
			flags->sharp = 1;
		if (format[i] >= '0' && format[i] <= '9')
			*flags = ft_flag_digit(format[i], *flags);
		if (ft_find_type(format[i]))
		{
			ft_parse_flags(&format[i], flags);
			break;
		}
		i++;
	}
	return (i);
}