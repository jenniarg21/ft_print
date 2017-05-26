/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 03:43:04 by jargote           #+#    #+#             */
/*   Updated: 2017/05/25 23:46:48 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define UINT_MAX 4294967295
# define PTR_PRE "0x"

# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_widestr
{
	unsigned int		*wc;
	int					len;
	struct s_widestr	*next;
	struct s_widestr	*prev;
}				t_widestr;

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
	wchar_t				*ws;
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
void			err(va_list ap);
int				apply_flags(char *str, t_format f);
int				print_padding_and_nbr(char *s, t_format f, int pad, int p_zero);
int				apply_flags_str(char **s, t_format f);
int				apply_flags_widestr(t_widestr *ws, t_format f);
t_widestr		*init_widestr(wchar_t ws);
void			free_widestr(t_widestr **ws);
int				find_specifier(t_format f, va_list ap);
int				find_number(char *fmt, int **count);
int				find_type(char *f, int *i, va_list ap);
t_flags			find_flags(char *fmt, int *i);
char			*find_length(char *fmt, int *i);
int				find_type(char *f, int *i, va_list ap);
int				find_specifier(t_format f, va_list ap);
int				character(t_format f, va_list ap);
int				integer(t_format f, va_list ap);
int				hex_lower(t_format f, va_list ap);
int				hex_upper(t_format f, va_list ap);
int				octal(t_format f, va_list ap);
int				percent(t_format f);
int				pointer(t_format f, va_list ap);
int				string(t_format f, va_list ap);
int				binary(t_format f, va_list ap);
int				u_integer(t_format f, va_list ap);
int				catch_other(t_format f);
char			*ui_longs(va_list ap, int base);
char			*ui_j_uintmax_t(va_list ap, int base);
char			*ui_z_size_t(va_list ap, int base);
char			*ui_hhh_short_char(unsigned int ui, t_format f, int base);
int				apply_color(char *f, int *i);

#endif
