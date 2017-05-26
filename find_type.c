/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 23:28:56 by jargote           #+#    #+#             */
/*   Updated: 2017/05/25 18:47:02 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_format	set_precision(char *f, t_format fmt, int *i, va_list ap)
{
	if (f[*i + 1] == '*')
	{
		fmt.prec = va_arg(ap, int);
		*i += 1;
	}
	else
		fmt.prec = find_number(f, &i);
	if (fmt.prec < 0)
		fmt.prec = 0;
	else if (fmt.prec == 0)
		fmt.prec = -1;
	fmt.spec = f[*i + 1];
	return (fmt);
}

static t_format	set_width(char *f, t_format fmt, int *i, va_list ap)
{
	if (f[*i + 1] == '*')
	{
		fmt.width = va_arg(ap, int);
		*i += 1;
		if (fmt.width < 0)
		{
			fmt.width *= -1;
			fmt.flags.neg = 1;
		}
		fmt.spec = f[*i + 1];
	}
	else if (ft_isdigit(fmt.spec))
	{
		fmt.width = find_number(f, &i);
		fmt.spec = f[*i + 1];
	}
	return (fmt);
}

int				find_type(char *f, int *i, va_list ap)
{
	int			len;
	t_format	fmt;

	len = 0;
	if (f[*i + 1])
	{
		fmt.flags = find_flags(f, i);
		fmt.length = find_length(f, i);
		fmt.spec = f[*i + 1];
		fmt.width = 0;
		fmt = set_width(f, fmt, i, ap);
		fmt.prec = 0;
		if (fmt.spec == '.')
		{
			*i += 1;
			fmt = set_precision(f, fmt, i, ap);
		}
		if (fmt.spec == '*' || ft_isdigit(fmt.spec))
			fmt = set_width(f, fmt, i, ap);
		len += find_specifier(fmt, ap);
		if (fmt.length)
			ft_strdel(&fmt.length);
		*i += 1;
	}
	return (len);
}
