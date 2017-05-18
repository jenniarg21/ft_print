/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 23:11:28 by jargote           #+#    #+#             */
/*   Updated: 2017/05/16 21:12:17 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putuint(unsigned int n)
{
	unsigned int		num;
	char				digit;

	if (n == 0)
		write(1, "0", 1);
	if (n > 0)
	{
		num = n % 10;
		n = n / 10;
		if (n > 0)
			ft_putuint(n);
		digit = num + 48;
		write(1, &digit, 1);
	}
}
