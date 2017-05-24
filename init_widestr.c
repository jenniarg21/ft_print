/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_widestr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 16:35:50 by jargote           #+#    #+#             */
/*   Updated: 2017/05/23 16:36:43 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_widestr	*init_widestr(void)
{
	t_widestr	*widestr;

	if (!(widestr = (t_widestr *)malloc(sizeof(t_widestr))))
		return (NULL);
	widestr->wc = NULL;
	widestr->len = 0;
	widestr->next = NULL;
	widestr->prev = NULL;
	return (widestr);
}
