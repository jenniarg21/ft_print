/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding_and_nbr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:43:12 by jargote           #+#    #+#             */
/*   Updated: 2017/05/17 23:27:23 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_padding_and_nbr(char *s, t_format f, int pad, int p_zero)
{
	int		len;

	len = 0;
	if (f.prec > (int)ft_strlen(s))
	{
		putnchar(f.prec - ft_strlen(s), '0');
		len += f.prec - ft_strlen(s);
	}
	if (!f.flags.neg && f.flags.zero && pad && !f.prec && !p_zero)
		putnchar(f.width, '0');
	if (!p_zero)
	{
		ft_putstr(s);
		len += ft_strlen(s);
	}
	if (f.flags.neg && pad)
		putnchar(f.width, ' ');
	return (len);
}
