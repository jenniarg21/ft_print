/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 23:07:03 by jargote           #+#    #+#             */
/*   Updated: 2016/11/11 17:39:49 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*t_dst;
	char			*t_src;

	t_dst = (char *)dst;
	t_src = (char *)src;
	if (dst < src)
	{
		t_dst = ft_memcpy(dst, src, len);
	}
	else if (dst > src)
	{
		while (len > 0)
		{
			t_dst[len - 1] = t_src[len - 1];
			len--;
		}
	}
	return (t_dst);
}
