/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:52:46 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/11 15:55:15 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int proc_int(int num, t_flags *flags)
{
	int l;
	char *str;

	l = 0;
	str = ft_itoa(num);
	l = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (l);
}
