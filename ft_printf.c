/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 03:43:12 by jargote           #+#    #+#             */
/*   Updated: 2017/05/17 18:53:49 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			count;
	int			len;

	va_start(ap, format);
	count = 0;
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			len += find_type((char *)format, &i, ap);
		else
		{
			ft_putchar(format[i]);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}
