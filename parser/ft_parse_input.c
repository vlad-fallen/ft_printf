/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:28:31 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/11 16:02:10 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void init_flags(t_flags *flags)
{
	flags->type = 0;
	flags->width = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->precision = 0;
	flags->sharp = 0;
}

static int ft_whitespace(const char *format, int i)
{
	while (format[i] == ' ')
		i++;
	ft_putchar(' ');
	return (i);
}

int ft_parse_input(const char *format, va_list ap)
{
	t_flags flags;
	int length;
	size_t i;

	length = 0;
	i = 0;
	while (format[i])
	{
		init_flags(&flags);
		if (format[i] == '%')
		{
			i++;
			if (format[i] == ' ')
			{
				i = ft_whitespace(format, i);
				length++;
			}
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
