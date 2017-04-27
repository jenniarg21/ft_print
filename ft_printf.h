/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 03:43:04 by jargote           #+#    #+#             */
/*   Updated: 2017/03/21 22:25:46 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define UINT_MAX 4294967295
# define PTR_PRE "0x7fff"

# include <stdarg.h>
# include "libft/libft.h"

typedef struct		s_flags
{
	int	pound;
	int	zero;
	int	neg;
	int	sp;
	int	pos;
}		t_flags;

typedef struct		s_format
{
	char	specifier;
	int		width;
	int		precision;
	char	*length;
	t_flags flags;
}			t_format;

typedef union		u_type
{
	char				c;
	char				*str;
	wchar_t				wc;
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

}					t_type;

int		ft_printf(const char * format, ...);

void	err(void);
void	ft_putuint(unsigned int n);
char	*lowercase(char *str);
void	putnchar(int n, char c);
int		apply_flags(char *str, t_flags f, int width, int precision, char s);
int		apply_flags_str(char *str, t_flags f, int widht, int precision, char s);
int		find_specifier(t_format f, va_list ap);
int		count_isdigit(char *str);
int		find_number(char *fmt, int **count);
int		find_type(char *fmt, int *i, va_list ap);
t_flags		find_flags(char *fmt, int *i);
char		*fine_length(char* fmt, int *i);


#endif
