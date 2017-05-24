/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:44:05 by jargote           #+#    #+#             */
/*   Updated: 2017/05/18 18:13:33 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		octal(t_format f, va_list ap)
{
	t_type	type;
	int		len;

	len = 0;
	if (f.spec == 'O' || (f.length &&
				(f.length[0] == 'l' || f.length[1] == 'l')))
		type.str = ui_longs(ap, 8);
	else if (f.length && f.length[0] == 'j')
		type.str = ui_j_uintmax_t(ap, 8);
	else if (f.length && f.length[0] == 'z')
		type.str = ui_z_size_t(ap, 8);
	else
	{
		type.ui = va_arg(ap, unsigned int);
		if (f.length)
			type.str = ui_hhh_short_char(type.ui, f, 8);
		else
			type.str = ft_itoabase(type.ui, 8);
	}
	len += apply_flags(type.str, f);
	ft_strdel(&type.str);
	return (len);
}
