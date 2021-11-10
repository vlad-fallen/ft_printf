/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:28:21 by mbutter           #+#    #+#             */
/*   Updated: 2021/10/25 16:19:03 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int proc_string(char *str)
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
