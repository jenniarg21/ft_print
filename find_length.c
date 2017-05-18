/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 23:28:05 by jargote           #+#    #+#             */
/*   Updated: 2017/05/17 18:29:25 by jargote          ###   ########.fr       */
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
	char	*t1;
	char	*t2;

	f = fmt[*i + 1];
	if (f == 'h' || f == 'l' || f == 'j' || f == 'z')
		len = find_lengthmod_len(fmt, i);
	else
		return (NULL);
	if (!(length = ft_strnew(len)))
		return (NULL);
	if (!(t1 = ft_strsub(fmt, *i + 1, len)))
	{
		ft_strdel(&length);
		return (NULL);
	}
	t2 = length;
	length = t1;
	ft_strdel(&t2);
	*i += len;
	return (length);
}
