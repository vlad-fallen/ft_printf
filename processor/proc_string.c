/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:28:21 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/11 15:54:07 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int proc_string(char *str, t_flags *flags)
{
	int l;

	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	l = 0;
	ft_putstr(str);
	l = ft_strlen(str);
	return (l);
}
