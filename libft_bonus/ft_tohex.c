/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:51:54 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/18 11:53:14 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*ft_fill_tohex(char *str, int num, size_t i)
{
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

char	*ft_tohex(unsigned long long num)
{
	char				*str;
	unsigned long long	t;
	size_t				i;

	t = num;
	i = 0;
	if (num == 0)
		return (ft_strdup("0"));
	while (t != 0)
	{
		i++;
		t /= 16;
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	i--;
	str = ft_fill_tohex(str, num, i);
	return (str);
}
