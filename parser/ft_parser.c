/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:16:22 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/10 17:59:07 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_whitespace(const char *format, int i)
{
	while (format[i] == ' ')
		i++;
	ft_putchar(' ');
	return (i);
}

int ft_parser(const char *format, int i, t_flags *flags, va_list ap)
{
	while (format[i])
	{
		if (format[i] == ' ')
			i = ft_whitespace(format, i);
		if (format[i] == '0')
			flags->zero = 1;
	}
}