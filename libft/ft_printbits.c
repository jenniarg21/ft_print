/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 19:15:50 by jargote           #+#    #+#             */
/*   Updated: 2016/11/15 19:25:54 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printbits(unsigned char octet)
{
	int				count;
	unsigned int	b;

	count = 8;
	b = 128;
	while (count > 0)
	{
		if ((octet / b) != 0)
		{
			octet %= b;
			ft_putchar('1');
		}
		else
			ft_putchar('0');
		b /= 2;
		count--;
	}
}
