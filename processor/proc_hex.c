/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:18:24 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/15 20:12:45 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int proc_output_hex(char *str, t_flags flags)
{
	int l;

	l = 0;
	if (flags.sharp == 1)
		
	if (flags.precision >=0)
		l += proc_width(flags.precision, ft_strlen(str), 1);
	l += ft_strlen(str);
	ft_putstr(str);
	return (l);
}

static int proc_put_hex(char *str, t_flags flags)
{
	int l;

	l = 0;
	if (flags.minus == 1)
		l += proc_output_hex(str, flags);
	if (flags.precision >= 0 && flags.precision < ft_strlen(str))
		flags.precision = ft_strlen(str);
	if (flags.precision >= 0)
		l += proc_width(flags.width, flags.precision, 0);
	else
		l += proc_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		l += proc_output_hex(str, flags);
	return (l);
}

int proc_hex(unsigned int num, int cap, t_flags *flags)
{
	char *str;
	int l;

	str = ft_tohex((unsigned long long)num);
	if (cap == 0)
		str = ft_strtolower(str);
	l = proc_put_hex(str, *flags);
	free(str);
	return (l);
}