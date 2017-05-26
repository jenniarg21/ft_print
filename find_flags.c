/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 23:26:51 by jargote           #+#    #+#             */
/*   Updated: 2017/05/25 18:47:24 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	set_flags(char c, int **i, t_flags *f)
{
	if (c == '#')
		f->pound = 1;
	else if (c == '0')
		f->zero = 1;
	else if (c == '-')
		f->neg = 1;
	else if (c == ' ')
		f->sp = 1;
	else if (c == '+')
		f->pos = 1;
	else
	{
		**i -= 2;
		return (0);
	}
	return (1);
}

t_flags		find_flags(char *fmt, int *i)
{
	t_flags	f;
	int		flag;

	f.pound = 0;
	f.zero = 0;
	f.neg = 0;
	f.sp = 0;
	f.pos = 0;
	flag = 1;
	*i += 1;
	while (flag)
	{
		flag = set_flags(fmt[*i], &i, &f);
		*i += 1;
	}
	return (f);
}
