/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:18:24 by mbutter           #+#    #+#             */
/*   Updated: 2021/10/26 14:07:46 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int proc_hex(unsigned int num, int cap)
{
	char *str;
	int l;
	int a;
	int t;
	size_t i;
	

	t = num;
	i = 0;
	if (cap == 0)
		a = 97;
	else
		a = 65;
	if (num == 0)
	{
		ft_putchar('0');
		return (1);
	}
	while (t != 0)
	{
		i++;
		t = t / 16;
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	i--;
	while (num != 0)
	{
		if (num % 16 < 10)
			str[i] = num % 16 + 48;
		else
			str[i] = num % 16 % 10 + a;
		num = num / 16;
		i--;
	}
	ft_putstr(str);
	l = ft_strlen(str);
	free(str);
	return (l);
}