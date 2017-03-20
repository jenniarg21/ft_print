/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstrings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 18:03:01 by jargote           #+#    #+#             */
/*   Updated: 2016/11/12 18:14:51 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printstrings(char **arr)
{
	unsigned int	i;

	if (arr)
	{
		i = 0;
		while (arr[i] != '\0')
		{
			ft_putstr(arr[i]);
			ft_putchar('\n');
			i++;
		}
	}
}
