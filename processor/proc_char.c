/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:17:11 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/11 15:51:46 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int proc_char(char c, t_flags *flags)
{
	int l;

	l = 0;
	ft_putchar(c);
	return (l + 1);
}
