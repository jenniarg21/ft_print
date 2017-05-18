/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usitoabase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 22:34:55 by jargote           #+#    #+#             */
/*   Updated: 2017/05/16 17:24:31 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	calc_digit(unsigned short int n, int base)
{
	if ((n % base) > 9)
		return ((n % base) - 10 + 65);
	else
		return ((n % base) + 48);
}

char		*ft_usitoabase(unsigned short int n, int base)
{
	char			*digit;
	int				count;
	char			*nbr;

	count = 1;
	nbr = (char *)malloc(count + 1);
	digit = (char *)malloc(2);
	ft_bzero(digit, 2);
	ft_bzero(nbr, 2);
	if (n == 0)
	{
		nbr[0] = '0';
		return (nbr);
	}
	while (n > 0)
	{
		digit[0] = calc_digit(n, base);
		n = n / base;
		nbr = strinconce(digit, nbr, count);
		count++;
	}
	ft_strdel(&digit);
	nbr = strreverse(nbr);
	return (nbr);
}
