/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strreverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 15:32:57 by jargote           #+#    #+#             */
/*   Updated: 2017/05/16 15:33:40 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strreverse(char *str)
{
	int		len;
	int		end;
	int		count;
	char	t;

	len = ft_strlen(str) - 1;
	end = len / 2;
	count = 0;
	while (count <= end)
	{
		t = str[count];
		str[count] = str[len];
		str[len] = t;
		count++;
		len--;
	}
	return (str);
}
