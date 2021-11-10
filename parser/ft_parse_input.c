/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:28:31 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/10 17:40:34 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void init_flags(t_flags *flags)
{
	flags->type = 0;
	flags->width = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->precision = 0;
	flags->star = 0;
}

void ft_parse_flags(const char *format, size_t *flags)
{
	if (*format == 'c')
		*flags = 1;
	else if (*format == 's')
		*flags = 2;
	else if (*format == 'p')
		*flags = 3;
	else if (*format == 'd')
		*flags = 4;
	else if (*format == 'i')
		*flags = 5;
	else if (*format == 'u')
		*flags = 6;
	else if (*format == 'x')
		*flags = 7;
	else if (*format == 'X')
		*flags = 8;
	else if (*format == '%')
		*flags = 9;
}

int ft_parse_input(const char *format, va_list ap)
{
	t_flags flags;
	int length;
	int i;

	length = 0;
	i = 0;
	while (format[i])
	{
		init_flags(&flags);
		if (format[i] == '%')
		{
			i++;
			i = ft_parser(format, i, &flags, ap);
			if (flags.type != 0)
				length += ft_processor(&flags, ap);
		}
		else
		{
			ft_putchar(format[i]);
			length++;
		}
		i++;
	}
	return (length);
}
