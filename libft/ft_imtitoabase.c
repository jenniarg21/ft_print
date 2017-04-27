/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imtitoabase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 23:27:13 by jargote           #+#    #+#             */
/*   Updated: 2017/03/23 18:26:46 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_setnbr(char *num, int count, intmax_t n, int base)
{
	uintmax_t			nbr;
	int						neg;

	num[count] = '\0';
	neg = n < 0;
	if (neg)
	{
		if (base == 10)
		{
			num[0] = '-';
			nbr = n * -1;
		}
		else
		{
			neg = 0;
			nbr = INTMAX_MAX + n + 1;
		}
	}
	else
		nbr = n;
	while ((count > 0 && !neg) || (count > 1 && neg))
	{
		count--;
		if ((nbr % base) < 10)
			num[count] = (nbr % base) + 48;
		else
			num[count] = (nbr % base) - 10 + 65;
		nbr /= base;
	}
}

char			*ft_imtitoabase(intmax_t n, int base)
{
	int						count;
	char					*num;
	uintmax_t			nbr;

	count = 0;
	if (n < 0)
	{
		if (base == 10)
		{
			count = 1;
			nbr = n * -1;
		}
		else
			nbr = INTMAX_MAX + n + 1;
	}
	else
		nbr = n;
	if (n == 0)
		count++;
	while (nbr > 0)
	{
		nbr /= base;
		count++;
	}
	if (!(num = (char *)malloc(count + 1)))
		return (NULL);
	ft_setnbr(num, count, n, base);
	return (num);
}
