/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:26:54 by jargote           #+#    #+#             */
/*   Updated: 2016/11/11 15:42:13 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*temp;
	void			*ptr;

	i = 0;
	temp = (unsigned char *)s;
	while (n > 0)
	{
		if (temp[i] == (unsigned char)c)
		{
			ptr = &temp[i];
			return (ptr);
		}
		n--;
		i++;
	}
	return (NULL);
}
