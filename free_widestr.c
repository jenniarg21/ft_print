/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_widestr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 16:35:59 by jargote           #+#    #+#             */
/*   Updated: 2017/05/25 15:50:51 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		free_widestr(t_widestr **ws)
{
	t_widestr	*w;
	t_widestr	*next;

	w = *ws;
	while (w)
	{
		if (w->wc != NULL)
			free(w->wc);
		w->wc = NULL;
		w->len = 0;
		next = w->next;
		w->next = NULL;
		w->prev = NULL;
		free(w);
		w = next;
	}
	*ws = w;
}
