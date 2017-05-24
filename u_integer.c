/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_integer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:45:22 by jargote           #+#    #+#             */
/*   Updated: 2017/05/18 18:34:25 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ui_longs(va_list ap, int base)
{
	t_type	type;

	type.uli = va_arg(ap, unsigned long int);
	type.str = ft_ulitoabase(type.uli, base);
	return (type.str);
}

char	*ui_j_uintmax_t(va_list ap, int base)
{
	t_type	type;

	type.uimt = va_arg(ap, uintmax_t);
	type.str = ft_uimtitoabase(type.uimt, base);
	return (type.str);
}

char	*ui_z_size_t(va_list ap, int base)
{
	t_type	type;

	type.st = va_arg(ap, size_t);
	type.str = ft_ustitoabase(type.st, base);
	return (type.str);
}

char	*ui_hhh_short_char(unsigned int ui, t_format f, int base)
{
	t_type	type;

	if (f.length[0] == 'h' && f.length[1] == '\0')
		type.str = ft_usitoabase((unsigned short)ui, base);
	else if (f.length[1] == 'h')
		type.str = ft_ucitoabase((unsigned char)ui, base);
	return (type.str);
}

int		u_integer(t_format f, va_list ap)
{
	t_type	type;
	int		len;

	len = 0;
	if (f.spec == 'U' ||
			(f.length && (f.length[0] == 'l' || f.length[1] == 'l')))
		type.str = ui_longs(ap, 10);
	else if (f.length && f.length[0] == 'j')
		type.str = ui_j_uintmax_t(ap, 10);
	else if (f.length && f.length[0] == 'z')
		type.str = ui_z_size_t(ap, 10);
	else
	{
		type.ui = va_arg(ap, unsigned int);
		if (f.length)
			type.str = ui_hhh_short_char(type.ui, f, 10);
		else
			type.str = ft_uitoa(type.ui);
	}
	len += apply_flags(type.str, f);
	ft_strdel(&type.str);
	return (len);
}
