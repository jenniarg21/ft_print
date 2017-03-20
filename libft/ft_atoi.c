/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 21:56:16 by jargote           #+#    #+#             */
/*   Updated: 2016/11/12 16:48:08 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned int	i;
	int				num;
	int				sign;

	i = 0;
	num = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i] != '\0')
		i++;
	if (str[i] == 45)
	{
		sign = -1;
		i++;
	}
	else
	{
		sign = 1;
		if (str[i] == 43)
			i++;
	}
	while (ft_isdigit(str[i]) == 1 && str[i] != '\0')
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	return (num * sign);
}
