/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:41:08 by jargote           #+#    #+#             */
/*   Updated: 2017/05/18 17:54:50 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*longs(va_list ap)
{
	t_type	type;

	type.li = va_arg(ap, long int);
	type.str = ft_litoa(type.li);
	return (type.str);
}

static char	*j_intmax_t(va_list ap)
{
	t_type	type;

	type.imt = va_arg(ap, intmax_t);
	type.str = ft_imtitoabase(type.imt, 10);
	return (type.str);
}

int			integer(t_format f, va_list ap)
{
	t_type	type;
	int		len;

	len = 0;
	if (f.spec == 'D' || (f.length && (f.length[0] == 'l' ||
					f.length[1] == 'l' || f.length[0] == 'z')))
		type.str = longs(ap);
	else if (f.length && f.length[0] == 'j')
		type.str = j_intmax_t(ap);
	else
	{
		type.i = va_arg(ap, int);
		if (f.length)
		{
			if (f.length[0] == 'h' && f.length[1] == '\0')
				type.str = ft_sitoabase((short)type.i, 10);
			else if (f.length[1] == 'h')
				type.str = ft_citoabase((char)type.i, 10);
		}
		else
			type.str = ft_itoa(type.i);
	}
	len += apply_flags(type.str, f);
	ft_strdel(&type.str);
	return (len);
}
