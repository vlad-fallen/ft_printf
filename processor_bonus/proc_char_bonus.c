/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_char_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:17:11 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/18 12:17:57 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	proc_char(char c, t_flags *flags)
{
	int	l;

	l = 0;
	if (flags->minus == 1)
		ft_putchar(c);
	l = proc_width(flags->width, 1, 0);
	if (flags->minus == 0)
		ft_putchar(c);
	return (l + 1);
}
