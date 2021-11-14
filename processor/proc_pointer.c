/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:34:54 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/14 16:43:28 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int proc_put_null(t_flags flags)
{
	int l;

	l = 3;
	if (flags.minus == 1)
		ft_putstr("0x0");
	l += proc_width(flags.width, 3, 0);
	if (flags.minus == 0)
		ft_putstr("0x0");
	return (l);
}

static int proc_put_pointer(char *str)
{
	int l;

	ft_putstr("0x");
	l = 2;
	ft_putstr(str);
	l += ft_strlen(str);
	return (l);
}

int proc_pointer(unsigned long long ptr, t_flags *flags)
{
	char *str;
	int l;

	l = 0;
	str = NULL;
	if (ptr == 0)
	{
		l = proc_put_null(*flags);
		return (l);
	}
	str = ft_tohex((unsigned long long)ptr);
	str = ft_strtolower(str);
	if (flags->minus == 1)
		l += proc_put_pointer(str);
	l += proc_width(flags->width, ft_strlen(str) + 2, 0);
	if (flags->minus == 0)
		l += proc_put_pointer(str);
	free(str);
	return (l);
}