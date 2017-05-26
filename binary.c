/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:45:22 by jargote           #+#    #+#             */
/*   Updated: 2017/05/25 22:23:07 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		binary(t_format f, va_list ap)
{
	t_type	type;
	int		len;

	len = 0;
	type.ui = va_arg(ap, unsigned int);
	type.str = (ft_uitoabase(type.ui, 2));
	len += apply_flags(type.str, f);
	free(type.str);
	type.str = NULL;
	return (len);
}
