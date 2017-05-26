/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:37:43 by jargote           #+#    #+#             */
/*   Updated: 2017/05/25 16:17:34 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_widestr	*set_widestr(wchar_t *ws, t_widestr *w, int i)
{
	if (i == 0)
	{
		if (!(w = init_widestr(ws[i])))
			return (NULL);
	}
	else
	{
		if (!(w->next = init_widestr(ws[i])))
			return (NULL);
		w->next->prev = w;
		w = w->next;
	}
	return (w);
}

static int			s_longs(wchar_t *ws, t_format f)
{
	t_widestr	*head;
	t_widestr	*widestr;
	int			len;
	int			i;

	i = -1;
	while (ws[++i])
	{
		if (!(widestr = set_widestr(ws, widestr, i)))
		{
			if (i > 0)
				free(&head);
			return (-1);
		}
		if (i == 0)
			head = widestr;
	}
	len = apply_flags_widestr(head, f);
	free_widestr(&head);
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
		if (ui != NULL && ui != 0 && ft_strcmp((char *)ui, ""))
			len = s_longs(type.ws, f);
		else
			len = blank_empty_val(ui, f);
	}
	else
	{
		type.str = va_arg(ap, char *);
		if (!type.str)
			type.str = "(null)";
		len = apply_flags_str(&type.str, f);
	}
	return (len);
}
