# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 11:08:16 by mbutter           #+#    #+#              #
#    Updated: 2021/11/09 15:13:14 by mbutter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS		=	ft_printf.c \
				ft_parse_input.c \
				ft_processor.c \
				ft_putchar.c \
				ft_putstr.c \
				ft_strlen.c \
				ft_strtolower.c \
				ft_itoa.c \
				ft_itoa_uint.c \
				ft_tohex.c \
				proc_char.c \
				proc_string.c \
				proc_int.c \
				proc_hex.c \
				proc_uint.c \
				proc_percent.c \
				proc_pointer.c			

OBJS		=	$(SRCS:.c=.o)

BONUS		=	

BONUS_OBJS	=	$(BONUS:.c=.o)

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -O2 -I ./

D_FILES		=	$(patsubst %.c,%.d,$(SRCS)) 

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -MD

include $(wildcard $(D_FILES))

clean:
			$(RM) $(OBJS) $(BONUS_OBJS) $(D_FILES)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

bonus:		$(OBJS) $(BONUS_OBJS)
			ar rc $(NAME) $(OBJS) $(BONUS_OBJS)
			ranlib $(NAME)

.PHONY:		all clean fclean re bonus