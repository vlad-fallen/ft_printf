/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:51:54 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/09 14:03:54 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_tohex(unsigned long long num)
{
	char *str;
	unsigned long long t;
	size_t i;

	t = num;
	i = 0;
	while (t != 0)
	{
		i++;
		t /=  16;
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	i--;
	while (num != 0)
	{
		if (num % 16 < 10)
			str[i] = num % 16 + 48;
		else
			str[i] = num % 16 % 10 + 65;
		num /= 16;
		i--;
	}
	return (str);
}