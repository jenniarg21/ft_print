/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 23:27:13 by jargote           #+#    #+#             */
/*   Updated: 2016/11/15 12:12:31 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_setnbr(char *num, int count, int n)
{
	unsigned int	nbr;
	int				neg;

	num[count] = '\0';
	neg = ft_isneg(n);
	if (neg)
	{
		num[0] = '-';
		nbr = n * -1;
	}
	else
		nbr = n;
	while ((count > 0 && !neg) || (count > 1 && neg))
	{
		count--;
		num[count] = (nbr % 10) + 48;
		nbr /= 10;
	}
}

char			*ft_itoa(int n)
{
	int				count;
	char			*num;
	unsigned int	nbr;

	count = 0;
	if (ft_isneg(n))
	{
		count = 1;
		nbr = n * -1;
	}
	else
		nbr = n;
	if (n == 0)
		count++;
	while (nbr > 0)
	{
		nbr /= 10;
		count++;
	}
	if (!(num = (char *)malloc(count + 1)))
		return (NULL);
	ft_setnbr(num, count, n);
	return (num);
}
