/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 23:17:37 by jargote           #+#    #+#             */
/*   Updated: 2016/11/16 18:21:33 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*t_dst;
	unsigned char	*t_src;
	unsigned int	i;

	i = 0;
	t_dst = (unsigned char *)dst;
	t_src = (unsigned char *)src;
	while (i < n)
	{
		if (t_src[i] == (unsigned char)c)
		{
			t_dst[i] = t_src[i];
			dst = (void *)&t_dst[i + 1];
			return (dst);
		}
		t_dst[i] = t_src[i];
		i++;
	}
	return (NULL);
}
