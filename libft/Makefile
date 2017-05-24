# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jargote <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/31 11:03:52 by jargote           #+#    #+#              #
#    Updated: 2017/05/20 21:03:54 by jargote          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	ft_memset.c \
			ft_bzero.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strdup.c \
			ft_atoi.c \
			ft_itoa.c \
			ft_strlen.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_isalnum.c \
		    ft_isalpha.c \
		    ft_isascii.c \
		    ft_isdigit.c \
		    ft_isprint.c \
		    ft_putchar.c \
		    ft_putchar_fd.c \
		    ft_putendl.c \
		    ft_putendl_fd.c \
		    ft_putnbr.c \
		    ft_putnbr_fd.c \
		    ft_putstr.c \
		    ft_putstr_fd.c \
		    ft_strclr.c \
		    ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
		    ft_strnequ.c \
			ft_strsub.c \
		    ft_tolower.c \
		    ft_toupper.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_iswhitespace.c \
			ft_printstrings.c \
			ft_isneg.c \
			ft_ispos.c \
			ft_printbits.c \
			ft_memchrlen.c \
			get_next_line.c \
			count_isdigit.c \
			lowercase.c \
			putnchar.c \
			ft_putuint.c \
			strreverse.c \
			strinconce.c \
			ft_itoabase.c \
			ft_uitoa.c \
			ft_uitoabase.c \
			ft_litoa.c \
			ft_ulitoa.c \
			ft_ulitoabase.c \
			ft_uimtitoabase.c \
			ft_ustitoabase.c \
			ft_litoabase.c \
			ft_sitoabase.c \
			ft_citoabase.c \
			ft_usitoa.c \
			ft_ucitoa.c \
			ft_imtitoabase.c \
			ft_usitoabase.c \
			ft_ucitoabase.c \
			exponent.c \
			ctowc.c \
			charhextoi.c

OBJS	=	$(SRCS:.c=.o)


all:		$(NAME)

$(NAME):	$(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)
	ar rs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)

re:			fclean all
