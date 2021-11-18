/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 13:22:10 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/18 11:56:03 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_parse_flags(const char *format, t_flags *flags)
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
