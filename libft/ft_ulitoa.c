/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 22:34:55 by jargote           #+#    #+#             */
/*   Updated: 2017/05/16 17:04:37 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ulitoa(unsigned long int n)
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
		digit[0] = (n % 10) + 48;
		n = n / 10;
		nbr = strinconce(digit, nbr, count);
		count++;
	}
	ft_strdel(&digit);
	nbr = strreverse(nbr);
	return (nbr);
}
