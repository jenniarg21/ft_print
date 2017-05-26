/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 23:28:05 by jargote           #+#    #+#             */
/*   Updated: 2017/05/25 18:48:23 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_lengthmod_len(char *fmt, int *i)
{
	char	f;
	int		len;

	f = fmt[*i + 2];
	if (f == 'h' || f == 'l')
		len = 2;
	else
		len = 1;
	return (len);
}

char		*find_length(char *fmt, int *i)
{
	char	*length;
	int		len;
	char	f;

	f = fmt[*i + 1];
	if (f == '*')
	{
		len = 0;
		length = NULL;
	}
	else
	{
		if (f == 'h' || f == 'l' || f == 'j' || f == 'z')
			len = find_lengthmod_len(fmt, i);
		else
			return (NULL);
		if (!(length = ft_strsub(fmt, *i + 1, len)))
		{
			ft_strdel(&length);
			return (NULL);
		}
	}
	*i += len;
	return (length);
}
