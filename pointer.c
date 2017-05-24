/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:45:58 by jargote           #+#    #+#             */
/*   Updated: 2017/05/18 17:28:22 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pointer(t_format f, va_list ap)
{
	t_type	type;
	int		len;

	len = 0;
	type.p = va_arg(ap, void *);
	type.str = lowercase(ft_ulitoabase((unsigned long int)type.p, 16));
	f.flags.pound = 1;
	len += apply_flags(type.str, f);
	ft_strdel(&type.str);
	return (len);
}
