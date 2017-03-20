/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 23:27:13 by jargote           #+#    #+#             */
/*   Updated: 2017/03/16 23:57:45 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_setnbr(char *num, int count, int n, int base)
{
	unsigned int	nbr;
	int				neg;

	num[count] = '\0';
	neg = ft_isneg(n);
	if (neg)
	{
		if (base == 10)
			num[0] = '-';
		else
			neg = 0;
		nbr = n * -1;
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

char			*ft_itoabase(int n, int base)
{
	int				count;
	char			*num;
	unsigned int	nbr;

	count = 0;
	if (ft_isneg(n))
	{
		if (base == 10)
			count = 1;
		nbr = n * -1;
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
