/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 23:25:32 by jargote           #+#    #+#             */
/*   Updated: 2017/05/17 18:20:00 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_number(char *fmt, int **count)
{
	char	*number_str;
	int		number_strlen;
	int		*i;
	int		nbr;

	i = *count;
	number_strlen = count_isdigit(&fmt[*i + 1]);
	number_str = ft_strsub(&fmt[*i + 1], 0, number_strlen);
	*i += number_strlen;
	*count = i;
	nbr = ft_atoi(number_str);
	ft_strdel(&number_str);
	return (nbr);
}
