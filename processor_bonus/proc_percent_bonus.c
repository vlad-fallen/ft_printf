/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_percent_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:13:05 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/18 12:16:16 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	proc_percent(t_flags *flags)
{
	int	l;

	l = 0;
	if (flags->minus == 1)
		ft_putchar('%');
	l = proc_width(flags->width, 1, flags->zero);
	if (flags->minus == 0)
		ft_putchar('%');
	return (l + 1);
}
