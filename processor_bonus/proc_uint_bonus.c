/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_uint_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:06:08 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/18 12:28:55 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	proc_output_int(char *str, t_flags flags)
{
	int	l;

	l = 0;
	if (flags.precision >= 0)
		l += proc_width(flags.precision, ft_strlen(str), 1);
	l += ft_strlen(str);
	ft_putstr(str);
	return (l);
}

static int	proc_put_int(char *str, t_flags flags)
{
	int	l;

	l = 0;
	if (flags.minus == 1)
		l += proc_output_int(str, flags);
	if (flags.precision >= 0 && flags.precision < ft_strlen(str))
		flags.precision = ft_strlen(str);
	if (flags.precision >= 0)
		l += proc_width(flags.width, flags.precision, 0);
	else
		l += proc_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		l += proc_output_int(str, flags);
	return (l);
}

int	proc_uint(unsigned int num, t_flags *flags)
{
	int		l;
	char	*str;

	l = 0;
	str = ft_itoa_uint(num);
	l = proc_put_int(str, *flags);
	free(str);
	return (l);
}
