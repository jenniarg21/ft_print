/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctowc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 20:39:25 by jargote           #+#    #+#             */
/*   Updated: 2017/05/24 17:51:57 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		utf8len(unsigned int n)
{
	if (n <= 127)
		return (1);
	if (n <= 2047)
		return (2);
	if (n <= 65535)
		return (3);
	if (n <= 2097151)
		return (4);
	if (n <= 67108863)
		return (5);
	return (6);
}

static int		calc_widechar(unsigned int ui, int begblen, int len, int i)
{
	unsigned int	val;
	unsigned int	mask;

	mask = 63;
	if (len == 1 && i == 0)
		val = ui & 127;
	else if (i == 0)
	{
		val = (ui >> (6 * (len - 1)) | ((exponent(2, len) - 1)
					<< (begblen + 1)));
		ui = ui & (exponent(2, (6 * (len - 1))) - 1);
	}
	else
		val = ((ui >> (6 * (len - 1))) & mask) | 128;
	return (val);
}

unsigned int	*ctowc(unsigned int ui, int *size)
{
	int				len;
	int				i;
	unsigned int	*wc;
	int				begblen;

	len = utf8len(ui);
	*size = len;
	if (!(wc = (unsigned int *)malloc(sizeof(unsigned int) * len)))
		return (NULL);
	begblen = 7 - len;
	i = 0;
	while (len > 0)
	{
		wc[i] = calc_widechar(ui, begblen, len, i);
		len--;
		i++;
	}
	return (wc);
}
