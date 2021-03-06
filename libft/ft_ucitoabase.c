/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ucitoabase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 22:34:55 by jargote           #+#    #+#             */
/*   Updated: 2017/05/24 19:03:08 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	calc_digit(unsigned char n, int base)
{
	if ((n % base) > 9)
		return ((n % base) - 10 + 65);
	else
		return ((n % base) + 48);
}

char		*ft_ucitoabase(unsigned char n, int base)
{
	char			*digit;
	int				count;
	char			*nbr;

	count = 1;
	nbr = (char *)malloc(count + 1);
	ft_bzero(nbr, 2);
	if (n == 0)
	{
		nbr[0] = '0';
		return (nbr);
	}
	digit = (char *)malloc(2);
	ft_bzero(digit, 2);
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
