# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jargote <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/06 03:43:21 by jargote           #+#    #+#              #
#    Updated: 2017/03/20 22:15:48 by jargote          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
LIBFTPATH	=	./libft
LIBFT		=	./libft/libft.a
SRCS		=	ft_printf.c
OBJS		=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(SRCS)
	make all -C $(LIBFTPATH)
	$(CC) $(CFLAGS) -c $(SRCS)
	cp $(LIBFT) $(NAME)
	ar -rvcs $(NAME) $(OBJS)

clean:
	make clean -C $(LIBFTPATH)
	rm -f $(OBJS)

fclean:		clean
	make fclean -C $(LIBFTPATH)
	rm -f $(NAME)

re:			fclean all
	make re -C $(LIBFTPATH)
