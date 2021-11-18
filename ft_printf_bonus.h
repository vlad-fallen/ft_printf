/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:42:21 by mbutter           #+#    #+#             */
/*   Updated: 2021/11/18 12:32:33 by mbutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flags
{
	int	type;
	int	width;
	int	minus;
	int	zero;
	int	precision;
	int	star;
	int	sharp;
	int	plus;
	int	space;
}	t_flags;

int		ft_printf(const char *format, ...);

/*--------LIBFT--------*/

void	ft_putchar(const char c);
void	ft_putstr(char *s);
int		ft_strlen(const char *str);
char	*ft_strtolower(char *str);
char	*ft_itoa(int n);
char	*ft_itoa_uint(unsigned int n);
char	*ft_tohex(unsigned long long num);
int		ft_isdigit(int c);
char	*ft_strdup(const char *src);

/*--------PARSER--------*/

int		ft_parse_input(const char *format, va_list ap);
int		ft_parser(const char *format, size_t i, t_flags *flags, va_list ap);
t_flags	ft_flag_minus(t_flags flags);
t_flags	ft_flag_plus(t_flags flags);
t_flags	ft_flag_width(va_list ap, t_flags flags);
t_flags	ft_flag_digit(char c, t_flags flags);
int		ft_flag_precision(const char *format, size_t i, t_flags *flags, \
	va_list ap);
void	ft_parse_flags(const char *format, t_flags *flags);

/*--------PROCESSOR--------*/

int		ft_processor(t_flags *flags, va_list ap);
int		proc_char(char c, t_flags *flags);
int		proc_string(char *str, t_flags *flags);
int		proc_int(int num, t_flags *flags);
int		proc_uint(unsigned int num, t_flags *flags);
int		proc_hex(unsigned int num, int cap, t_flags *flags);
int		proc_percent(t_flags *flags);
int		proc_pointer(unsigned long long ptr, t_flags *flags);
int		proc_width(int width, int minus, int zero);

#endif