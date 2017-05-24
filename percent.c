/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:36:58 by jargote           #+#    #+#             */
/*   Updated: 2017/05/18 17:27:36 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		percent(t_format f)
{
	int		len;

	len = 0;
	if (f.flags.neg)
		ft_putchar(f.spec);
	if (f.width)
	{
		if (f.flags.zero && !f.flags.neg)
			putnchar(f.width - 1, '0');
		else
			putnchar(f.width - 1, ' ');
		len += f.width;
	}
	else
		len++;
	if (!f.flags.neg)
		ft_putchar(f.spec);
	return (len);
}
