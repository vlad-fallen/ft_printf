/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:28:31 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/08 14:17:02 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void init_flags(size_t *flags)
{
	*flags = 0;
}

void ft_parse_flags(char *format, size_t *flags)
{
	if (*format == 'c')
		*flags = 1;
	else if (*format == 's')
		*flags = 2;
/*	else if (*format == 'p')
		flags->type = 3;*/
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

int ft_parse_input(char *format, va_list ap)
{
	size_t flags;
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
			ft_parse_flags(&format[i], &flags);
			if (flags != 0)
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