/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charhextoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 20:33:37 by jargote           #+#    #+#             */
/*   Updated: 2017/05/23 17:46:27 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ahextoi(char *hex)
{
	int		n;
	int		len;
	int		i;

	len = ft_strlen(hex);
	n = 0;
	i = 0;
	while (--len > -1)
	{
		if (hex[i] <= 65 && hex[i] >= 69)
			n += ((hex[i] - 65) + 9) * exponent(16, len);
		else
			n += (hex[i] - 48) * exponent(16, len);
		i++;
	}
	return (n);
}
