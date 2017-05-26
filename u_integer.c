/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_integer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:45:22 by jargote           #+#    #+#             */
/*   Updated: 2017/05/24 19:00:41 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ui_longs(va_list ap, int base)
{
	t_type	type;

	type.uli = va_arg(ap, unsigned long int);
	return (ft_ulitoabase(type.uli, base));
}

char	*ui_j_uintmax_t(va_list ap, int base)
{
	t_type	type;

	type.uimt = va_arg(ap, uintmax_t);
	return (type.str = ft_uimtitoabase(type.uimt, base));
}

char	*ui_z_size_t(va_list ap, int base)
{
	t_type	type;

	type.st = va_arg(ap, size_t);
	return (ft_ustitoabase(type.st, base));
}

char	*ui_hhh_short_char(unsigned int ui, t_format f, int base)
{
	if (f.length[0] == 'h' && f.length[1] == '\0')
		return (ft_usitoabase((unsigned short)ui, base));
	else
		return (ft_ucitoabase((unsigned char)ui, base));
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
		if (f.length && f.length[0] == 'h')
			type.str = ui_hhh_short_char(type.ui, f, 10);
		else
			type.str = ft_uitoa(type.ui);
	}
	len += apply_flags(type.str, f);
	free(type.str);
	type.str = NULL;
	return (len);
}
