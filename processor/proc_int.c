/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:52:46 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/11 11:49:53 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	proc_int(int num)
{
	int		l;
	char	*str;

	l = 0;
	str = ft_itoa(num);
	l = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (l);
}
