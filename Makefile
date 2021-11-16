# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 11:08:16 by mbutter           #+#    #+#              #
#    Updated: 2021/11/16 14:27:49 by mbutter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS		=	ft_printf.c \
				parser/ft_parse_input.c \
				parser/ft_flags.c \
				parser/ft_parse_flags.c \
				parser/ft_parser.c \
				libft/ft_putchar.c \
				libft/ft_putstr.c \
				libft/ft_strlen.c \
				libft/ft_strtolower.c \
				libft/ft_itoa.c \
				libft/ft_itoa_uint.c \
				libft/ft_tohex.c \
				libft/ft_isdigit.c \
				libft/ft_strdup.c \
				processor/ft_processor.c \
				processor/proc_char.c \
				processor/proc_string.c \
				processor/proc_int.c \
				processor/proc_hex.c \
				processor/proc_uint.c \
				processor/proc_percent.c \
				processor/proc_pointer.c \
				processor/proc_width.c

OBJS		=	$(SRCS:.c=.o)

BONUS		=	

BONUS_OBJS	=	$(BONUS:.c=.o)

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -O2 -I ./includes

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

bonus:		all

.PHONY:		all clean fclean re bonus