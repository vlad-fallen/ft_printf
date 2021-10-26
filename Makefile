# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 11:08:16 by mbutter           #+#    #+#              #
#    Updated: 2021/10/26 13:51:15 by mbutter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS		=	ft_printf.c \
				ft_parse_input.c \
				ft_processor.c \
				ft_putchar.c \
				ft_putstr.c \
				ft_strlen.c \
				ft_itoa.c \
				proc_char.c \
				proc_string.c \
				proc_int.c \
				proc_hex.c

OBJS		=	$(SRCS:.c=.o)

BONUS		=	

BONUS_OBJS	=	$(BONUS:.c=.o)

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -I ./

# D_FILES		=	$(patsubst %.c,%.d,$(SRCS)) #

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

#include $(wildcard $(D_FILES))#

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

bonus:		$(OBJS) $(BONUS_OBJS)
			ar rc $(NAME) $(OBJS) $(BONUS_OBJS)
			ranlib $(NAME)

.PHONY:		all clean fclean re bonus