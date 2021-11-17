/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:28:31 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/17 13:35:38 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void init_flags(t_flags *flags)
{
	flags->type = 0;
	flags->width = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->precision = -1;
	flags->sharp = 0;
	flags->plus = 0;
	flags->star = 0;
	flags->space = 0;
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
