/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:06:08 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/11 15:55:38 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int proc_uint(unsigned int num, t_flags *flags)
{
	int l;
	char *str;

	l = 0;
	str = ft_itoa_uint(num);
	l = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (l);
}
