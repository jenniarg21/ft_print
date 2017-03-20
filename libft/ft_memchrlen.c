/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 22:05:33 by jargote           #+#    #+#             */
/*   Updated: 2017/01/12 22:14:49 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memchrlen(char *s, int c, size_t n)
{
	int		i;
	char	*temp;

	i = 0;
	temp = s;
	while (n > 0)
	{
		if (temp[i] == c)
			return (i);
		n--;
		i++;
	}
	return (i);
}
