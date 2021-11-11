/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:18:24 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/11 15:56:09 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int proc_hex(unsigned int num, int cap, t_flags *flags)
{
	char *str;
	int l;

	if (num == 0)
	{
		ft_putchar('0');
		return (1);
	}
	str = ft_tohex((unsigned long long)num);
	if (cap == 0)
		str = ft_strtolower(str);
	ft_putstr(str);
	l = ft_strlen(str);
	free(str);
	return (l);
}