/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:39:36 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/13 15:23:38 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_processor(t_flags *flags, va_list ap)
{
	int length;

	length = 0;
	if (flags->type == 1)
		length = proc_char((char)va_arg(ap, int), flags);
	else if (flags->type == 2)
		length = proc_string(va_arg(ap, char *));
	else if (flags->type == 3)
		length = proc_pointer(va_arg(ap, unsigned long long));
	else if (flags->type == 4 || flags->type == 5)
		length = proc_int(va_arg(ap, int));
	else if (flags->type == 6)
		length = proc_uint(va_arg(ap, unsigned int));
	else if (flags->type == 7)
		length = proc_hex(va_arg(ap, unsigned int), 0);
	else if (flags->type == 8)
		length = proc_hex(va_arg(ap, unsigned int), 1);
	else if (flags->type == 9)
		length = proc_percent();
	return (length);
}
