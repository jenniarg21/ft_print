/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 22:41:12 by jargote           #+#    #+#             */
/*   Updated: 2016/11/11 00:22:05 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	size_t			d_len;
	size_t			s_len;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (d_len > size)
		return (size + s_len);
	else
	{
		i = d_len;
		j = 0;
		while (i < (size - 1) && src[j] != '\0')
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
		return (d_len + s_len);
	}
}
