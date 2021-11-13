/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:59:21 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/13 15:03:33 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int proc_width(int width, int minus, int zero)
{
	int l;

	l = 0;
	while (width - minus > 0)
	{
		if (zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width--;
		l++;
	}
	return (l);
}