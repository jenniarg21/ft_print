/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 23:26:51 by jargote           #+#    #+#             */
/*   Updated: 2017/05/17 18:51:11 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	set_flags(char *fmt, int *i, t_flags *f, int *flag)
{
	if (fmt[*i] == '#')
		f->pound = 1;
	else if (fmt[*i] == '0')
		f->zero = 1;
	else if (fmt[*i] == '-')
		f->neg = 1;
	else if (fmt[*i] == ' ')
		f->sp = 1;
	else if (fmt[*i] == '+')
		f->pos = 1;
	else
	{
		*flag = 0;
		*i -= 2;
	}
	return (*i);
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
		*i = set_flags(fmt, i, &f, &flag);
		*i += 1;
	}
	return (f);
}
