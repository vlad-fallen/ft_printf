/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:05:46 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/17 13:35:38 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_get_len_itoa(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_fill_str(char *str, long n, int len)
{
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	else if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		len--;
		str[len] = n % 10 + '0';
		n /= 10;
	}
}

char	*ft_itoa_uint(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_get_len_itoa((long)n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str != NULL)
		ft_fill_str(str, (long)n, len);
	return (str);
}
