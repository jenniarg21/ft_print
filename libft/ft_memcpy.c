/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 22:53:24 by jargote           #+#    #+#             */
/*   Updated: 2016/11/11 00:02:11 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*t_dst;
	char			*t_src;
	unsigned int	i;

	i = 0;
	t_dst = (char *)dst;
	t_src = (char *)src;
	while (i < n)
	{
		t_dst[i] = t_src[i];
		i++;
	}
	return (dst);
}
