/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_isdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 23:23:04 by jargote           #+#    #+#             */
/*   Updated: 2017/05/16 21:11:18 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_isdigit(char *str)
{
	int		count;

	count = 0;
	while (ft_isdigit(str[count]))
		count++;
	return (count);
}
