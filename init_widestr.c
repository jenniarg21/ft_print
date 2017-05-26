/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_widestr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 16:35:50 by jargote           #+#    #+#             */
/*   Updated: 2017/05/24 21:34:46 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_widestr	*init_widestr(wchar_t ws)
{
	t_widestr	*widestr;

	if (!(widestr = (t_widestr *)malloc(sizeof(t_widestr) * 1)))
		return (NULL);
	if (ws)
	{
		if (!(widestr->wc = ctowc(ws, &widestr->len)))
		{
			free(widestr);
			return (NULL);
		}
		widestr->next = NULL;
		widestr->prev = NULL;
	}
	else
	{
		widestr->wc = NULL;
		widestr->len = 0;
		widestr->next = NULL;
		widestr->prev = NULL;
	}
	return (widestr);
}
