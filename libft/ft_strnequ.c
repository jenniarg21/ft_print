/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:46:44 by jargote           #+#    #+#             */
/*   Updated: 2016/11/14 16:49:07 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int		i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (i < n && n != 0)
		if (s1[i] != s2[i])
			return (0);
	if (i < n && (s1[i] == '\0' || s2[i] == '\0'))
		if (s1[i] != s2[i])
			return (0);
	return (1);
}
