/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sitoabase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 23:27:13 by jargote           #+#    #+#             */
/*   Updated: 2017/05/16 20:58:40 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		setforneg(char *num, short int n, int base, int *neg)
{
	int		nbr;

	if (base == 10)
	{
		num[0] = '-';
		nbr = n * -1;
	}
	else
	{
		*neg = 0;
		nbr = SINT_MAX + n + 1;
	}
	return (nbr);
}

static void		ft_setnbr(char *num, int count, short int n, int base)
{
	int		nbr;
	int		neg;

	num[count] = '\0';
	neg = ft_isneg(n);
	if (neg)
		nbr = setforneg(num, n, base, &neg);
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

static void		find_length(int n, int base, int *count)
{
	int		nbr;

	if (ft_isneg(n))
	{
		if (base == 10)
		{
			*count = 1;
			nbr = n * -1;
		}
		else
			nbr = SINT_MAX + n + 1;
	}
	else
		nbr = n;
	if (n == 0)
		*count += 1;
	while (nbr > 0)
	{
		nbr /= base;
		*count += 1;
	}
}

char			*ft_sitoabase(short int n, int base)
{
	int		count;
	char	*num;

	count = 0;
	find_length(n, base, &count);
	if (!(num = (char *)malloc(count + 1)))
		return (NULL);
	ft_setnbr(num, count, n, base);
	return (num);
}
