/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:39:54 by jargote           #+#    #+#             */
/*   Updated: 2017/05/24 17:55:56 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			print_char(t_format f, unsigned int *wc, int len, char c)
{
	int		i;

	if (f.spec == 'C' || (f.length && f.length[0] == 'l'))
	{
		i = -1;
		while (++i < len)
			ft_putchar(wc[i]);
	}
	else
		ft_putchar(c);
}

static int			apply_flags_c(t_format f, unsigned int *wc, int wcl, char c)
{
	int		len;

	len = 0;
	if (f.flags.neg)
		print_char(f, wc, wcl, c);
	if (f.width > 0)
	{
		if (f.flags.zero && !f.flags.neg)
			putnchar(f.width - 1, '0');
		else
			putnchar(f.width - 1, ' ');
		len += f.width - 1;
	}
	if (!f.flags.neg)
		print_char(f, wc, wcl, c);
	return (len);
}

static unsigned int	*c_longs(va_list ap, int *len, int *wcl)
{
	unsigned int	ui;
	unsigned int	*widechar;
	int				wclen;

	ui = va_arg(ap, unsigned int);
	widechar = ctowc(ui, &wclen);
	*wcl = wclen;
	*len += wclen;
	return (widechar);
}

int					character(t_format f, va_list ap)
{
	t_type			type;
	int				len;
	unsigned int	*widechar;
	int				wclen;

	len = 0;
	widechar = NULL;
	wclen = 0;
	if (f.spec == 'C' || (f.length && f.length[0] == 'l'))
		widechar = c_longs(ap, &len, &wclen);
	else
	{
		type.c = va_arg(ap, int);
		len++;
	}
	len += apply_flags_c(f, widechar, wclen, type.c);
	if (f.spec == 'C' || (f.length && f.length[0] == 'l'))
		free(widechar);
	return (len);
}
