# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jargote <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/06 03:43:21 by jargote           #+#    #+#              #
#    Updated: 2017/05/17 21:10:34 by jargote          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
LIBFTPATH	=	./libft
LIBFT		=	./libft/libft.a
SRCS		=	ft_printf.c \
				apply_flags.c \
				print_padding_and_nbr.c \
				apply_flags_str.c \
				err.c \
				find_flags.c \
				find_length.c \
				find_number.c \
				find_specifier.c \
				find_type.c
OBJS		=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(SRCS)
	make all -C $(LIBFTPATH)
	$(CC) $(CFLAGS) -c $(SRCS)
	cp $(LIBFT) $(NAME)
	ar -rvcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFTPATH)

fclean:		clean
	rm -f $(NAME)
	make fclean -C $(LIBFTPATH)

re:			fclean all
	make re -C $(LIBFTPATH)
