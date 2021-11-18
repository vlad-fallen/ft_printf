# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 11:08:16 by mbutter           #+#    #+#              #
#    Updated: 2021/11/18 13:03:20 by mbutter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS		=	ft_printf.c \
				parser/ft_parse_input.c \
				processor/ft_processor.c \
				libft/ft_putchar.c \
				libft/ft_putstr.c \
				libft/ft_strlen.c \
				libft/ft_strtolower.c \
				libft/ft_itoa.c \
				libft/ft_itoa_uint.c \
				libft/ft_tohex.c \
				processor/proc_char.c \
				processor/proc_string.c \
				processor/proc_int.c \
				processor/proc_hex.c \
				processor/proc_uint.c \
				processor/proc_percent.c \
				processor/proc_pointer.c	

OBJS		=	$(SRCS:.c=.o)

BONUS		=	ft_printf_bonus.c \
				parser_bonus/ft_parse_input_bonus.c \
				parser_bonus/ft_flags_bonus.c \
				parser_bonus/ft_parse_flags_bonus.c \
				parser_bonus/ft_parser_bonus.c \
				libft_bonus/ft_putchar.c \
				libft_bonus/ft_putstr.c \
				libft_bonus/ft_strlen.c \
				libft_bonus/ft_strtolower.c \
				libft_bonus/ft_itoa.c \
				libft_bonus/ft_itoa_uint.c \
				libft_bonus/ft_tohex.c \
				libft_bonus/ft_isdigit.c \
				libft_bonus/ft_strdup.c \
				processor_bonus/ft_processor_bonus.c \
				processor_bonus/proc_char_bonus.c \
				processor_bonus/proc_string_bonus.c \
				processor_bonus/proc_int_bonus.c \
				processor_bonus/proc_hex_bonus.c \
				processor_bonus/proc_uint_bonus.c \
				processor_bonus/proc_percent_bonus.c \
				processor_bonus/proc_pointer_bonus.c \
				processor_bonus/proc_width_bonus.c

BONUS_OBJS	=	$(BONUS:.c=.o)

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -O2 -I ./

D_FILES		=	$(patsubst %.c,%.d,$(SRCS)) 

D_FILES_B	=	$(patsubst %.c,%.d,$(BONUS))

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)
#			ranlib $(NAME)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -MMD

clean:
			$(RM) $(OBJS) $(BONUS_OBJS) $(D_FILES) $(D_FILES_B)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

bonus:		fclean
			$(MAKE) OBJS="$(BONUS_OBJS)" D_FILES="$(D_FILES_B)" all

.PHONY:		all clean fclean re bonus

include $(wildcard $(D_FILES))