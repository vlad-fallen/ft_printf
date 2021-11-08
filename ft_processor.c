/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:39:36 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/08 14:13:32 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_processor(size_t *flags, va_list ap)
{
	int length;

	length = 0;
	if (*flags == 1)
		length = proc_char((char)va_arg(ap, int));
	else if (*flags == 2)
		length = proc_string(va_arg(ap, char *));
/*	else if (flags->type == 3)
		length = proc_pointer(va_arg(ap, char));*/
	else if (*flags == 4 || *flags == 5)
		length = proc_int(va_arg(ap, int));
	else if (*flags == 6)
		length = proc_uint(va_arg(ap, unsigned int));
	else if (*flags == 7)
		length = proc_hex(va_arg(ap, unsigned int), 0);
	else if (*flags == 8)
		length = proc_hex(va_arg(ap, unsigned int), 1);
	else if (*flags == 9)
		length = proc_percent();
	return (length);
}
