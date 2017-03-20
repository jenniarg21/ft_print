/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 03:43:04 by jargote           #+#    #+#             */
/*   Updated: 2017/03/20 00:17:47 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define UINT_MAX 4294967295
# define PTR_PRE "0x7fff"

# include <stdarg.h>
# include "libft/libft.h"

typedef union		s_type
{
	char			c;
	char			*str;
	void			*p;
	int				i;
	unsigned int	ui;
	float			f;
	long			l;
	short			s;
	long long		ll;

}					t_type;

int		ft_printf(const char * format, ...);

void	err(void);
void	ft_putuint(unsigned int n);
char	*lowercase(char *str);
void	putspaces(int n);
void	find_specifier(char specifier, va_list ap, int width, int precision);
int		count_isdigit(char *str);
int		find_number(char *fmt, int **count);
void	find_type(char *fmt, int *i, va_list ap);


#endif
