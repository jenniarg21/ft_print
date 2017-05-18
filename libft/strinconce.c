/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strinconce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 15:41:11 by jargote           #+#    #+#             */
/*   Updated: 2017/05/16 17:03:15 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strinconce(char *s, char *str, int count)
{
	char	*t;

	if (count == 1)
		ft_bzero(str, count + 1);
	else
	{
		t = str;
		str = (char *)malloc(count + 1);
		ft_bzero(str, count + 1);
		str = ft_strcpy(str, t);
		free(t);
	}
	str = ft_strcat(str, s);
	return (str);
}
