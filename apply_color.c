/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 22:34:26 by jargote           #+#    #+#             */
/*   Updated: 2017/05/26 00:01:39 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	set_color(char *color)
{
	if (!ft_strcmp(color, "red"))
		ft_putstr("\x1B[31m");
	else if (!ft_strcmp(color, "green"))
		ft_putstr("\x1B[32m");
	else if (!ft_strcmp(color, "yellow"))
		ft_putstr("\x1B[33m");
	else if (!ft_strcmp(color, "blue"))
		ft_putstr("\x1B[34m");
	else if (!ft_strcmp(color, "magenta"))
		ft_putstr("\x1B[35m");
	else if (!ft_strcmp(color, "cyan"))
		ft_putstr("\x1B[36m");
	else if (!ft_strcmp(color, "white"))
		ft_putstr("\x1B[37m");
	else if (!ft_strcmp(color, "eoc"))
		ft_putstr("\x1B[0m");
	else
		return (0);
	return (1);
}

int			apply_color(char *f, int *i)
{
	int		count;
	char	*color;

	count = 0;
	color = ft_strsub(f, *i + 1, ft_memchrlen(&f[*i + 1], '}',
				ft_strlen(&f[*i])));
	if (set_color(color))
	{
		*i += ft_strlen(color);
		free(color);
		return (1);
	}
	free(color);
	return (0);
}
