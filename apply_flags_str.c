/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 23:20:30 by jargote           #+#    #+#             */
/*   Updated: 2017/05/17 23:47:24 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*apply_precision(char *str, t_format *f)
{
	char	*t;

	if (f->prec == -1)
		f->prec = 0;
	t = ft_strsub(str, 0, f->prec);
	return (t);
}

static char		*apply_width(char *str, t_format *f, int *len)
{
	f->width -= ft_strlen(str);
	if (f->flags.zero && !f->flags.neg)
		putnchar(f->width, '0');
	else
		putnchar(f->width, ' ');
	*len += f->width;
	return (str);
}

int				apply_flags_str(char **s, t_format f)
{
	char	*str;
	char	*t;
	int		len;

	str = *s;
	len = 0;
	if (f.prec > 0 || f.prec == -1)
	{
		t = apply_precision(str, &f);
		str = t;
	}
	if (f.flags.neg)
		ft_putstr(str);
	if (f.width > (int)ft_strlen(str))
		str = apply_width(str, &f, &len);
	if (!f.flags.neg)
		ft_putstr(str);
	len += ft_strlen(str);
	if (f.prec > 0)
		ft_strdel(&str);
	*s = str;
	return (len);
}
