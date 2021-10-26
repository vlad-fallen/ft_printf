#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

// void ft_putchar(const char c)
// {
// 	write(1, &c, 1);
// }

// void	ft_putstr(char *s)
// {
// 	size_t	i;

// 	if (s == NULL)
// 		return ;
// 	i = 0;
// 	while (s[i])
// 		i++;
// 	write(1, s, i);
// }

// int ft_strlen(char *str)
// {
// 	int i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// int ft_printf(char *str, ...)
// {
// 	int len;
// 	int i;

// 	i = 0;
// 	len = 0;
// 	va_list ap;
// 	va_start(ap, str);
// 	while (str[i])
// 	{
// 		if (str[i] == '%')
// 		{
// 			i++;
// 			if (str[i] == 'c')
// 			{
// 				char c = (char)va_arg (ap, int);
// 				ft_putchar(c);
// 				len++;
// 			}
// 			else if (str[i] == 's')
// 			{
// 				char *s = va_arg(ap, char *);
// 				ft_putstr(s);
// 				len += ft_strlen(s);
// 			}
// 		}
// 		else
// 		{
// 			ft_putchar(str[i]);
// 			len++;
// 		}
// 		i++;
// 	}
// 	va_end(ap);
// 	return (len);
// }

int ft_printf(char *format, ...);

int main ()
{
	ft_printf("hello %s, %X", "world", 10);
}