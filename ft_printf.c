/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 03:43:12 by jargote           #+#    #+#             */
/*   Updated: 2017/05/26 00:11:07 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			len;

	va_start(ap, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			len += find_type((char *)format, &i, ap);
		else
		{
			if (format[i] == '{' && apply_color((char *)format, &i))
				i += 1;
			else
			{
				ft_putchar(format[i]);
				len++;
			}
		}
		i++;
	}
	va_end(ap);
	return (len);
}
