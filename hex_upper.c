/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_upper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:42:30 by jargote           #+#    #+#             */
/*   Updated: 2017/05/18 18:14:40 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		hex_upper(t_format f, va_list ap)
{
	t_type	type;
	int		len;

	len = 0;
	if (f.length && (f.length[0] == 'l' || f.length[1] == 'l'))
		type.str = ui_longs(ap, 16);
	else if (f.length && f.length[0] == 'j')
		type.str = ui_j_uintmax_t(ap, 16);
	else if (f.length && f.length[0] == 'z')
		type.str = ui_z_size_t(ap, 16);
	else
	{
		type.ui = va_arg(ap, unsigned int);
		if (f.length)
			type.str = ui_hhh_short_char(type.ui, f, 16);
		else
			type.str = ft_itoabase(type.ui, 16);
	}
	len += apply_flags(type.str, f);
	ft_strdel(&type.str);
	return (len);
}
