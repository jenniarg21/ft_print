/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:26:40 by jargote           #+#    #+#             */
/*   Updated: 2016/11/11 15:53:18 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		b_len;
	size_t		l_len;
	char		*sub;

	if (*little == '\0')
		return ((char *)big);
	b_len = ft_strlen(big);
	l_len = ft_strlen(little);
	i = 0;
	sub = ft_strsub(big, 0, len);
	while (sub[i] != '\0' && l_len <= ft_strlen(&sub[i]))
	{
		if (little[0] == sub[i])
		{
			if (ft_strnequ(little, &sub[i], l_len))
			{
				return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (NULL);
}
