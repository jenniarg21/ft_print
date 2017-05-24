/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_lower.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:43:15 by jargote           #+#    #+#             */
/*   Updated: 2017/05/18 18:33:59 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ui_longs_hexlc(va_list ap, int base)
{
	t_type	type;

	type.uli = va_arg(ap, unsigned long int);
	type.str = lowercase(ft_ulitoabase(type.uli, base));
	return (type.str);
}

static char	*ui_j_uintmax_t_hexlc(va_list ap, int base)
{
	t_type	type;

	type.uimt = va_arg(ap, uintmax_t);
	type.str = lowercase(ft_uimtitoabase(type.uimt, base));
	return (type.str);
}

static char	*ui_z_size_t_hexlc(va_list ap, int base)
{
	t_type	type;

	type.st = va_arg(ap, size_t);
	type.str = lowercase(ft_ustitoabase(type.st, base));
	return (type.str);
}

static char	*ui_hhh_short_char_hexlc(unsigned int ui, t_format f, int base)
{
	t_type	type;

	if (f.length[0] == 'h' && f.length[1] == '\0')
		type.str = lowercase(ft_usitoabase((unsigned short)ui, base));
	else if (f.length[1] == 'h')
		type.str = lowercase(ft_ucitoabase((unsigned char)ui, base));
	return (type.str);
}

int			hex_lower(t_format f, va_list ap)
{
	t_type	type;
	int		len;

	len = 0;
	if (f.length && (f.length[0] == 'l' || f.length[1] == 'l'))
		type.str = ui_longs_hexlc(ap, 16);
	else if (f.length && f.length[0] == 'j')
		type.str = ui_j_uintmax_t_hexlc(ap, 16);
	else if (f.length && f.length[0] == 'z')
		type.str = ui_z_size_t_hexlc(ap, 16);
	else
	{
		type.ui = va_arg(ap, unsigned int);
		if (f.length)
			type.str = ui_hhh_short_char_hexlc(type.ui, f, 16);
		else
			type.str = lowercase(ft_itoabase(type.ui, 16));
	}
	if (f.spec == 'p')
		f.flags.pound = 1;
	len += apply_flags(type.str, f);
	ft_strdel(&type.str);
	return (len);
}
