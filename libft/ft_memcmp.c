/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 23:11:25 by jargote           #+#    #+#             */
/*   Updated: 2016/11/12 17:08:46 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*t1;
	unsigned char	*t2;

	if ((!s1 && !s2) || n == 0)
		return (0);
	i = 0;
	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	while (i < n)
	{
		if (t1[i] != t2[i])
		{
			return (t1[i] - t2[i]);
		}
		i++;
	}
	return (t1[i - 1] - t2[i - 1]);
}
