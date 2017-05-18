/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_citoabase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 23:27:13 by jargote           #+#    #+#             */
/*   Updated: 2017/05/16 17:07:19 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		adjust_for_neg(char *num, int n, int base, int *neg)
{
	int		nbr;

	if (n < CHAR_MIN)
	{
		nbr = (CHAR_MIN - n) - 1 + CHAR_MAX;
		*neg = 0;
	}
	else if (base == 10)
	{
		num[0] = '-';
		nbr = n * -1;
	}
	else
	{
		*neg = 0;
		nbr = UINT_MAX + n + 1;
	}
	return (nbr);
}

static int		adjust_bounds_set(char *num, int n, int base, int *neg)
{
	int		nbr;

	if (*neg)
		nbr = adjust_for_neg(num, n, base, neg);
	else if (n > CHAR_MAX)
	{
		num[0] = '-';
		nbr = ((n - CHAR_MAX) - 1 + CHAR_MIN) * -1;
		*neg = 1;
	}
	else
		nbr = n;
	return (nbr);
}

static int		adjust_bounds_count(int n, int base, int *count)
{
	int		nbr;

	if (ft_isneg(n))
	{
		if (n < CHAR_MIN)
			nbr = (CHAR_MIN - n) - 1 + CHAR_MAX;
		else if (base == 10)
		{
			*count = 1;
			nbr = n * -1;
		}
		else
			nbr = UINT_MAX + n + 1;
	}
	else if (n > CHAR_MAX)
	{
		nbr = ((n - CHAR_MAX) - 1 + CHAR_MIN) * -1;
		*count = 1;
	}
	else
		nbr = n;
	return (nbr);
}

static int		find_length(int n, int base)
{
	int		count;
	int		nbr;

	count = 0;
	nbr = adjust_bounds_count(n, base, &count);
	if (n == 0)
		count++;
	while (nbr > 0)
	{
		nbr /= base;
		count++;
	}
	return (count);
}

char			*ft_citoabase(int n, int base)
{
	int				count;
	char			*num;
	int				nbr;
	int				neg;

	count = find_length(n, base);
	if (!(num = (char *)malloc(count + 1)))
		return (NULL);
	num[count] = '\0';
	neg = ft_isneg(n);
	nbr = adjust_bounds_set(num, n, base, &neg);
	while ((count > 0 && !neg) || (count > 1 && neg))
	{
		count--;
		if ((nbr % base) < 10)
			num[count] = (nbr % base) + 48;
		else
			num[count] = (nbr % base) - 10 + 65;
		nbr /= base;
	}
	return (num);
}
