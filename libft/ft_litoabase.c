/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoabase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 23:27:13 by jargote           #+#    #+#             */
/*   Updated: 2017/05/16 20:54:20 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long	sfn(char *num, long int n, int base, int *neg)
{
	unsigned long long	nbr;

	if (base == 10)
	{
		num[0] = '-';
		nbr = n * -1;
	}
	else
	{
		*neg = 0;
		nbr = ULONG_MAX + n + 1;
	}
	return (nbr);
}

static void					ft_setnbr(char *num, int count, long int n, int b)
{
	unsigned long long	nbr;
	int					neg;

	num[count] = '\0';
	neg = n < 0;
	if (neg)
		nbr = sfn(num, n, b, &neg);
	else
		nbr = n;
	while ((count > 0 && !neg) || (count > 1 && neg))
	{
		count--;
		if ((nbr % b) < 10)
			num[count] = (nbr % b) + 48;
		else
			num[count] = (nbr % b) - 10 + 65;
		nbr /= b;
	}
}

static void					find_length(long int n, int base, int *count)
{
	unsigned long long	nbr;

	if (n < 0)
	{
		if (base == 10)
		{
			*count = 1;
			nbr = n * -1;
		}
		else
			nbr = ULONG_MAX + n + 1;
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

char						*ft_litoabase(long int n, int base)
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
