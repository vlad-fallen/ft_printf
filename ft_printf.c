/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:12:28 by mbutter           #+#    #+#             */
/*   Updated: 2021/10/26 11:44:00 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(char *format, ...)
{
	int len;
	va_list ap;
	va_start(ap, format);
	len = ft_parse_input(format, ap);
	va_end(ap);
	return (len);
}
