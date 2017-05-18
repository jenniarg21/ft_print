/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 03:43:04 by jargote           #+#    #+#             */
/*   Updated: 2017/05/17 23:21:09 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define UINT_MAX 4294967295
# define PTR_PRE "0x"

# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_flags
{
	int	pound;
	int	zero;
	int	neg;
	int	sp;
	int	pos;
}				t_flags;

typedef struct	s_format
{
	char	spec;
	int		width;
	int		prec;
	char	*length;
	t_flags flags;
}				t_format;

typedef union	u_type
{
	char				c;
	char				*str;
	void				*p;
	int					i;
	long int			li;
	unsigned int		ui;
	unsigned long int	uli;
	intmax_t			imt;
	uintmax_t			uimt;
	size_t				st;
	float				f;
	long				l;
	short				s;
	long long			ll;

}				t_type;

int				ft_printf(const char *format, ...);
void			err(void);
int				apply_flags(char *str, t_format f);
int				print_padding_and_nbr(char *s, t_format f, int pad, int p_zero);
int				apply_flags_str(char **s, t_format f);
int				find_specifier(t_format f, va_list ap);
int				find_number(char *fmt, int **count);
int				find_type(char *f, int *i, va_list ap);
t_flags			find_flags(char *fmt, int *i);
char			*find_length(char *fmt, int *i);
int				find_type(char *f, int *i, va_list ap);
int				find_specifier(t_format f, va_list ap);

#endif
