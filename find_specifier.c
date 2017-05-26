/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 13:34:15 by jargote           #+#    #+#             */
/*   Updated: 2017/05/26 00:19:20 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	specifier(t_format f, va_list ap)
{
	int		len;

	if (f.spec == '%')
		len = percent(f);
	else if (f.spec == 's' || f.spec == 'S')
		len = string(f, ap);
	else if (f.spec == 'c' || f.spec == 'C')
		len = character(f, ap);
	else if (f.spec == 'i' || f.spec == 'd' || f.spec == 'D')
		len = integer(f, ap);
	else if (f.spec == 'X')
		len = hex_upper(f, ap);
	else if (f.spec == 'x')
		len = hex_lower(f, ap);
	else if (f.spec == 'o' || f.spec == 'O')
		len = octal(f, ap);
	else if (f.spec == 'u' || f.spec == 'U')
		len = u_integer(f, ap);
	else if (f.spec == 'p')
		len = pointer(f, ap);
	else if (f.spec == 'b')
		len = binary(f, ap);
	else
		len = catch_other(f);
	return (len);
}

int			find_specifier(t_format f, va_list ap)
{
	int		len;

	len = specifier(f, ap);
	if (len == -1)
		err(ap);
	return (len);
}
