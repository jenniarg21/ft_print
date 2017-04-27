/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulitoabase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 22:34:55 by jargote           #+#    #+#             */
/*   Updated: 2017/03/22 21:09:21 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*strreverse(char *str)
{
	int		len;
	int		end;
	int		count;
	char	t;

	len = ft_strlen(str) - 1;
	end = len / 2;
	count = 0;
	while (count <= end)
	{
		t = str[count];
		str[count] = str[len];
		str[len] = t;
		count++;
		len--;
	}
	return (str);
}

char		*ft_ulitoabase(unsigned long int n, int base)
{
	char			*digit;
	int				count;
	char			*nbr;
	char			*t;

/*	count = 0;
	nbr = n;
	if (!(nbr > 0))
		nbr -= UINT_MAX -1;
	while (nbr > 0)
	{
		nbr /= 10;
		count++;
	}
	if (!(num = (char *)malloc(count + 1)))
		return (NULL);
	num[count] = '\0';
	while (count > 0)
	{
		count--;
		num[count] = (nbr % 10) + 48;
		nbr /= 10;
	}
	return (num);
	*/
	count = 1;
	nbr = (char *)malloc(count + 1);
	digit = (char *)malloc(2);
	ft_bzero(digit, 2);
	//ft_bzero(t);
	if (n == 0)
	{
		nbr[0] = '0';
		return (nbr);
	}
	while (n > 0)
	{
		if ((n % base) > 9)
			digit[0] = (n % base) - 10 + 65;
		else
			digit[0] = (n % base) + 48;
		n = n / base;
//ft_putendl("BEFORE MALLOCING");
		if (count == 1)
			ft_bzero(nbr, count + 1);
		else
		{
			t = nbr;
			//free(t);
//ft_putendl("\tBEFORE MALLOCING FOR NON-FIRST");
			nbr = (char *)malloc(count + 1); // similiar to GNL
//ft_putendl("\tBEFORE BEZEROING");
			ft_bzero(nbr, count + 1);
//ft_putendl("\tBEFORE STRCPY()");
			nbr = ft_strcpy(nbr, t);
			free(t);
		}
//ft_putendl("AFTER MALLOCING");
		nbr = ft_strcat(nbr, digit);
//ft_putendl("AFTER STRCAT()");
//ft_putendl(nbr);
		count++;
	}
	ft_strdel(&digit);
	nbr = strreverse(nbr);
	return (nbr);
}
