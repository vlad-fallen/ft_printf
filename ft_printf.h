/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:42:21 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/08 14:22:28 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(const char c);
void	ft_putstr(char *s);
int		ft_strlen(char *str);
char	*ft_itoa(int n);
char	*ft_itoa_uint(unsigned int n);
int		proc_char(char c);
int		proc_string(char *str);
int		proc_int(int num);
int		proc_uint(unsigned int num);
int		proc_hex(unsigned int num, int cap);
int		proc_percent(void);
int		ft_parse_input(char *format, va_list ap);
int		ft_processor(size_t *flags, va_list ap);


#endif