/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_widestr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 23:20:30 by jargote           #+#    #+#             */
/*   Updated: 2017/05/23 16:11:48 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		count_widestrs(t_widestr *ws)
{
	int	count;

	count = 0;
	while (ws)
	{
		count += ws->len;
		ws = ws->next;
	}
	return (count);
}

static int		calc_width_adjust(t_widestr *ws, int width, int prec)
{
	int		currlen;

	currlen = 0;
	if (prec == -1)
		return (width);
	while (ws)
	{
		currlen += ws->len;
		if (prec == 0 || prec >= currlen)
			ws = ws->next;
		else
		{
			if (prec > 0)
				width += prec - (currlen - ws->len);
			ws = NULL;
		}
	}
	return (width);
}

static int		print_widestr(t_widestr *ws, int prec)
{
	int		plen;
	int		currlen;
	int		i;
	int		j;

	plen = 0;
	currlen = 0;
	i = -1;
	if (prec == -1)
		return (0);
	while (ws)
	{
		currlen += ws->len;
		if (prec == 0 || prec >= currlen)
		{
			j = -1;
			while (++j < ws->len)
				ft_putchar(ws->wc[j]);
			plen += ws->len;
			ws = ws->next;
		}
		else
			ws = NULL;
	}
	return (plen);
}

static void		apply_width(t_format *f, int wlen, int *len)
{
	if (f->prec == 0)
		f->width -= wlen;
	else if (f->prec != -1)
		f->width -= f->prec;
	if (f->flags.zero && !f->flags.neg)
		putnchar(f->width, '0');
	else
		putnchar(f->width, ' ');
	*len += f->width;
}

int				apply_flags_widestr(t_widestr *ws, t_format f)
{
	int		len;

	len = 0;
	f.width = calc_width_adjust(ws, f.width, f.prec);
	if (f.flags.neg)
		len += print_widestr(ws, f.prec);
	if ((f.prec == -1 && f.width > count_widestrs(ws)) || f.width > f.prec)
		apply_width(&f, count_widestrs(ws), &len);
	if (!f.flags.neg)
		len += print_widestr(ws, f.prec);
	return (len);
}
