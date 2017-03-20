/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:29:01 by jargote           #+#    #+#             */
/*   Updated: 2016/11/13 23:45:07 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*new;
	char			*temp;
	unsigned int	i;

	if (!(temp = (char *)malloc(size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		temp[i] = 0;
		i++;
	}
	new = (void *)temp;
	return (new);
}
