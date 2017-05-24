/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:46:48 by jargote           #+#    #+#             */
/*   Updated: 2017/05/18 17:23:34 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		catch_other(t_format f)
{
	int		len;

	len = 0;
	if (f.flags.neg)
		ft_putchar(f.spec);
	if (f.width > 0)
	{
		if (f.flags.zero && !f.flags.neg)
			putnchar(f.width - 1, '0');
		else
			putnchar(f.width - 1, ' ');
		len += f.width - 1;
	}
	if (!f.flags.neg)
		ft_putchar(f.spec);
	len++;
	return (len);
}
