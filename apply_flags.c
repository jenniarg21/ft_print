/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 23:14:55 by jargote           #+#    #+#             */
/*   Updated: 2017/05/17 23:21:46 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	zero_precision(char *str, t_format *f)
{
	int		prec_zero;

	prec_zero = 0;
	if (f->prec == -1)
	{
		if (str[0] == '0')
		{
			prec_zero = 1;
			f->width++;
		}
		f->prec = 0;
	}
	else if (f->flags.pound && str[0] != '0' &&
			(f->spec == 'o' || f->spec == 'O'))
		f->prec--;
	return (prec_zero);
}

static int	adjust_width(char *str, t_format *f, int neg, int *len)
{
	int		padding;

	padding = 0;
	if (f->width > (int)ft_strlen(str) && f->width > (f->prec + neg))
	{
		padding = 1;
		if (f->spec == 'd' || f->spec == 'i' || f->spec == 'D')
		{
			if (!neg && (f->flags.pos || f->flags.sp))
				f->width--;
		}
		if (f->prec > (int)ft_strlen(str) - neg)
			f->width -= (f->prec + neg);
		else
			f->width -= ft_strlen(str);
		*len += f->width;
	}
	return (padding);
}

static int	print_sign_and_space(char **str, t_format f, int neg)
{
	int		len;

	len = 0;
	if (f.spec == 'd' || f.spec == 'i' || f.spec == 'D')
	{
		if (neg)
		{
			ft_putchar('-');
			*str += 1;
			len++;
		}
		else if (f.flags.pos)
		{
			ft_putchar('+');
			len++;
		}
		else if (f.flags.sp)
		{
			ft_putchar(' ');
			len++;
		}
	}
	return (len);
}

static void	apply_pound(char *str, t_format f, int prec_zero, int *len)
{
	if (f.flags.pound)
	{
		if ((f.spec == 'o' || f.spec == 'O') &&
				(str[0] != '0' || prec_zero))
		{
			ft_putchar('0');
			*len += 1;
		}
		else if ((str[0] != '0' && f.spec == 'x') || f.spec == 'p')
		{
			ft_putstr("0x");
			*len += 2;
		}
		else if (str[0] != '0' && f.spec == 'X')
		{
			ft_putstr("0X");
			*len += 2;
		}
	}
}

int			apply_flags(char *str, t_format f)
{
	int	len;
	int	padding;
	int	neg;
	int	prec_zero;

	len = 0;
	neg = 0;
	if (str[0] == '-')
		neg = 1;
	prec_zero = zero_precision(str, &f);
	if (f.flags.pound)
	{
		if (f.spec == 'o' || f.spec == 'O')
			f.width--;
		else if (str[0] != 0 &&
				(f.spec == 'x' || f.spec == 'X' || f.spec == 'p'))
			f.width -= 2;
	}
	padding = adjust_width(str, &f, neg, &len);
	if (!f.flags.neg && padding && (!f.flags.zero || (f.flags.zero && f.prec)))
		putnchar(f.width, ' ');
	len += print_sign_and_space(&str, f, neg);
	apply_pound(str, f, prec_zero, &len);
	len += print_padding_and_nbr(str, f, padding, prec_zero);
	return (len);
}
