# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 01:59:45 by aoueldma          #+#    #+#              #
#    Updated: 2022/04/22 02:40:37 by aoueldma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_rev.c ft_putstr.c ft_lowhexa.c ft_p.c ft_printf.c ft_putnbr.c ft_uint.c ft_uphexa.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
$(OBJS) :
	$(CC) $(CFLAGS) -c $(SRCS)
clean :
	rm -rf $(OBJS)
fclean :
	rm -rf $(NAME) $(OBJS)
re : fclean all
