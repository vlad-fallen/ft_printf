/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_hex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:18:24 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/18 12:19:10 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	proc_output_hex(char *str, t_flags flags, unsigned int num, int cap)
{
	int	l;

	l = 0;
	if (flags.sharp == 1 && flags.zero == 0 && num != 0)
	{
		if (cap == 1)
			ft_putstr("0X");
		else
			ft_putstr("0x");
		l += 2;
	}
	if (flags.precision >= 0)
		l += proc_width(flags.precision, ft_strlen(str), 1);
	l += ft_strlen(str);
	ft_putstr(str);
	return (l);
}

static int	proc_put_hex(char *str, t_flags flags, unsigned int num, int cap)
{
	int	l;

	l = 0;
	if (flags.minus == 1)
		l += proc_output_hex(str, flags, num, cap);
	if (flags.sharp == 1 && flags.zero == 0)
		flags.width -= 2;
	if (flags.precision >= 0 && flags.precision < ft_strlen(str))
		flags.precision = ft_strlen(str);
	if (flags.precision >= 0)
		l += proc_width(flags.width, flags.precision, 0);
	else
		l += proc_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		l += proc_output_hex(str, flags, num, cap);
	return (l);
}

int	proc_hex(unsigned int num, int cap, t_flags *flags)
{
	char	*str;
	int		l;

	l = 0;
	str = ft_tohex((unsigned long long)num);
	if (cap == 0)
		str = ft_strtolower(str);
	if (flags->zero == 1 && flags->precision == -1 && flags->sharp == 1 && \
		num != 0)
	{
		if (cap == 1)
			ft_putstr("0X");
		else
			ft_putstr("0x");
		flags->width -= 2;
		l += 2;
	}
	l += proc_put_hex(str, *flags, num, cap);
	free(str);
	return (l);
}
