/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:34:54 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/19 18:03:36 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	proc_pointer(unsigned long ptr)
{
	char	*str;
	int		l;

	str = NULL;
	if (ptr == 0)
	{
		ft_putstr("0x0");
		return (3);
	}
	else
	{
		str = ft_tohex((unsigned long long)ptr);
		str = ft_strtolower(str);
	}
	ft_putstr("0x");
	l = 2;
	ft_putstr(str);
	l += ft_strlen(str);
	free(str);
	return (l);
}
