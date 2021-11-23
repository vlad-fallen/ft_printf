/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_uint_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:06:08 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/23 13:34:23 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	proc_output_int(char *str, t_flags flags, unsigned int num)
{
	int	l;

	l = 0;
	if (flags.precision >= 0)
		l += proc_width(flags.precision, ft_strlen(str), 1);
	if (!(num == 0) || !(flags.precision == 0))
	{
		l += ft_strlen(str);
		ft_putstr(str);
	}
	return (l);
}

static int	proc_put_int(char *str, t_flags flags, unsigned int num)
{
	int	l;

	l = 0;
	if (flags.minus == 1)
		l += proc_output_int(str, flags, num);
	if (flags.precision > 0 && flags.precision < ft_strlen(str))
		flags.precision = ft_strlen(str);
	if (flags.precision > 0 && (flags.width > ft_strlen(str) || num == 0))
		l += proc_width(flags.width, flags.precision, 0);
	else if (flags.precision == 0 && num != 0)
		l += proc_width(flags.width, ft_strlen(str), 0);
	else if (flags.precision == 0 && num == 0)
		l += proc_width(flags.width, flags.precision, 0);
	else
		l += proc_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		l += proc_output_int(str, flags, num);
	return (l);
}

int	proc_uint(unsigned int num, t_flags *flags)
{
	int		l;
	char	*str;

	l = 0;
	str = ft_itoa_uint(num);
	l = proc_put_int(str, *flags, num);
	free(str);
	return (l);
}
