/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:37:43 by jargote           #+#    #+#             */
/*   Updated: 2017/05/23 16:37:50 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_widestr	*set_widestr(t_widestr *widestr, wchar_t *ws, int i)
{
	t_widestr	*t;

	if (i == 0)
	{
		widestr = init_widestr();
		widestr->wc = ctowc(ws[i], &widestr->len);
	}
	else
	{
		t = init_widestr();
		t->wc = ctowc(ws[i], &t->len);
		t->prev = widestr;
		widestr->next = t;
		widestr = t;
	}
	return (widestr);
}

static int			s_longs(wchar_t *ws, t_format f)
{
	t_widestr	*widestr;
	int			i;
	int			len;

	i = -1;
	widestr = NULL;
	i = -1;
	while (ws[++i])
		widestr = set_widestr(widestr, ws, i);
	while (widestr && widestr->prev != NULL)
		widestr = widestr->prev;
	len = 0;
	len += apply_flags_widestr(widestr, f);
	free_widestr(&widestr);
	return (len);
}

static int			blank_empty_val(unsigned int *ui, t_format f)
{
	t_type	type;
	int		len;

	len = 0;
	if (!ui)
		type.str = "(null)";
	else
		type.str = "";
	len += apply_flags_str(&type.str, f);
	return (len);
}

int					string(t_format f, va_list ap)
{
	t_type			type;
	int				len;
	unsigned int	*ui;

	len = 0;
	if (f.spec == 'S' || (f.length && f.length[0] == 'l'))
	{
		type.ws = va_arg(ap, wchar_t *);
		ui = (unsigned int *)type.ws;
		if (ui != NULL && ui != '\0' && type.ws != NULL && type.ws != '\0')
			len += s_longs(type.ws, f);
		else
			len += blank_empty_val(ui, f);
	}
	else
	{
		type.str = va_arg(ap, char *);
		if (!type.str)
			type.str = "(null)";
		len += apply_flags_str(&type.str, f);
	}
	return (len);
}
