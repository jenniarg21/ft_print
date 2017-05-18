/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <jargote@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 13:34:15 by jargote           #+#    #+#             */
/*   Updated: 2017/05/17 23:41:03 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

								#include "stdio.h"

static int	percent(t_format f)
{
	int		len;
	
	len = 0;
		if(f.flags.neg)
			ft_putchar(f.spec);
		if (f.width)
		{
			if (f.flags.zero && !f.flags.neg)
				putnchar(f.width - 1, '0');
			else
				putnchar(f.width - 1, ' ');
			len += f.width;
		}
		else
			len++;
		if (!f.flags.neg)
			ft_putchar(f.spec);
	return (len);
}

static int	string(t_format f, va_list ap)
{
	t_type	type;
	int		len;

	len = 0;
		type.str = va_arg(ap, char *);
		if (!type.str)
			type.str = "(null)";
		len += apply_flags_str(&type.str, f);
	return (len);
}

static int	character(t_format f, va_list ap)
{
	t_type	type;
	int		len;

	len = 0;
		type.c = va_arg(ap, int);
		if (f.flags.neg)
			ft_putchar(type.c);
		if (f.width > 0)
		{
			if (f.flags.zero && !f.flags.neg)
				putnchar(f.width - 1, '0');
			else
				putnchar(f.width - 1, ' ');
			len += f.width - 1;
		}
		if (!f.flags.neg)
			ft_putchar(type.c);
		len++;
	return (len);
}

static int	integer(t_format f, va_list ap)
{
	t_type	type;
	int		len;

	len = 0;
		if (f.spec == 'D' || (f.length && (f.length[0] == 'l' || f.length[1] == 'l' || f.length[0] == 'z')))
		{
			type.li = va_arg(ap, long int);
			type.str = ft_litoa(type.li);
		}
		else if (f.length && f.length[0] == 'j')
		{
			type.imt = va_arg(ap, intmax_t);
			type.str = ft_imtitoabase(type.imt, 10);
		}
		else
		{
			type.i = va_arg(ap, int);
			if (f.length)
			{
				if (f.length[0] == 'h' && f.length[1] == '\0')
					type.str = ft_sitoabase((short)type.i, 10);
				else if (f.length[1] == 'h')
					type.str = ft_citoabase((char)type.i, 10);
			}
			else
				type.str = ft_itoa(type.i);
		}
		len += apply_flags(type.str, f);
		ft_strdel(&type.str);
	return (len);
}

static int	hex_upper(t_format f, va_list ap)
{
	t_type	type;
	int		len;

	len = 0;
		if (f.length && (f.length[0] == 'l' || f.length[1] == 'l'))
		{
			type.uli = va_arg(ap, unsigned long int);
			type.str = ft_ulitoabase(type.uli, 16);
		}
		else if (f.length && f.length[0] == 'j')
		{
			type.uimt = va_arg(ap, uintmax_t);
			type.str = ft_uimtitoabase(type.uimt, 16);
		}
		else if (f.length && f.length[0] == 'z')
		{
			type.st = va_arg(ap, size_t);
			type.str = ft_ustitoabase(type.st, 16);
		}
		else
		{
			type.ui = va_arg(ap, unsigned int);
			if (f.length)
			{
				if (f.length[0] == 'h' && f.length[1] =='\0')
					type.str = ft_usitoabase((unsigned short)type.ui, 16);
				else if (f.length[1] == 'h')
					type.str = ft_ucitoabase((unsigned char)type.ui, 16);
			}
			else
				type.str = ft_itoabase(type.ui, 16);
		}
	//	ft_putstr(type.str);
	//	len += ft_strlen(type.str);
		len += apply_flags(type.str, f);
		ft_strdel(&type.str);
	return (len);
}

static int	hex_lower(t_format f, va_list ap)
{
	t_type	type;
	int		len;

	len = 0;
		if (f.spec == 'p')
		{
			type.p = va_arg(ap, void *);
			type.str = lowercase(ft_ulitoabase((unsigned long int)type.p, 16));
		}
		if (f.length && (f.length[0] == 'l' || f.length[1] == 'l'))
		{
			type.uli = va_arg(ap, unsigned long int);
			type.str = lowercase(ft_ulitoabase(type.uli, 16));
		}
		else if (f.length && f.length[0] == 'j')
		{
			type.uimt = va_arg(ap, uintmax_t);
			type.str = lowercase(ft_uimtitoabase(type.uimt, 16));
		}
		else if (f.length && f.length[0] == 'z')
		{
			type.st = va_arg(ap, size_t);
			type.str = lowercase(ft_ustitoabase(type.st, 16));
		}
		else
		{
			type.ui = va_arg(ap, unsigned int);
			if (f.length)
			{
				if (f.length[0] == 'h' && f.length[1] == '\0')
					type.str = lowercase(ft_usitoabase((unsigned short)type.ui, 16));
				else if (f.length[1] == 'h')
					type.str = lowercase(ft_ucitoabase((unsigned char)type.ui, 16));
			}
			else
				type.str = lowercase(ft_itoabase(type.ui, 16));
		}
	//	ft_putstr(type.str);
	//	len += ft_strlen(type.str);
		if (f.spec == 'p')
			f.flags.pound = 1;
		len += apply_flags(type.str, f);
		ft_strdel(&type.str);
	return (len);
}

static int	octal(t_format f, va_list ap)
{
	t_type	type;
	int		len;

	len = 0;
		if (f.spec == 'O' || (f.length && (f.length[0] == 'l' || f.length[1] == 'l')))
		{
			type.uli = va_arg(ap, unsigned long int);
			type.str = ft_ulitoabase(type.uli, 8);
		}
		else if (f.length && f.length[0] == 'j')
		{
			type.uimt = va_arg(ap, uintmax_t);
			type.str = ft_uimtitoabase(type.uimt, 8);
		}
		else if (f.length && f.length[0] == 'z')
		{
			type.st = va_arg(ap, size_t);
			type.str = ft_ustitoabase(type.st, 8);
		}
		else
		{
			type.ui = va_arg(ap, unsigned int);
			if (f.length)
			{
				if (f.length[0] == 'h' && f.length[1] == '\0')
					type.str = ft_usitoabase((unsigned short)type.ui, 8);
				else
					type.str = ft_ucitoabase((unsigned char)type.ui, 8);
			}
			else
				type.str = ft_itoabase(type.ui, 8);
		}
		len += apply_flags(type.str, f);
		ft_strdel(&type.str);
	return (len);
}

static int	u_integer(t_format f, va_list ap)
{
	t_type	type;
	int		len;

	len = 0;
		if (f.spec == 'U' || (f.length && (f.length[0] == 'l' || f.length[1] == 'l')))
		{
			type.uli = va_arg(ap, unsigned long int);
			type.str = ft_ulitoa(type.uli);
		}
		else if (f.length && f.length[0] == 'j')
		{
			type.uimt = va_arg(ap, uintmax_t);
			type.str = ft_uimtitoabase(type.uimt, 10);
		}
		else if (f.length && f.length[0] == 'z')
		{
			type.st = va_arg(ap, size_t);
			type.str = ft_ustitoabase(type.st, 10);
		}
		else
		{
		//if (va_arg(ap, long int) < 0)
		//	type.ui = UINT_MAX + va_arg(ap, long int) - 1;
		//else
		//	if (va_arg(ap, int) < 0)
		//	{
		//		type.i = va_arg(ap, int);
		//		type.ui = type.i + UINT_MAX - 1;
		//	}
		//	else
			type.ui = va_arg(ap, unsigned int);
			if (f.length)
			{
				if (f.length[0] == 'h' && f.length[1] == '\0')
					type.str = ft_usitoa((unsigned short)type.ui);
				else if (f.length[1] == 'h')
					type.str = ft_ucitoa((unsigned char)type.ui);
			}
			else
			{
			//ft_putuint(type.ui);
				type.str = ft_uitoa(type.ui);
			}
		}
		/*	ft_putstr(type.str);
			len += ft_strlen(type.str);*/
		len += apply_flags(type.str, f);
		ft_strdel(&type.str);
//		ft_putstr(ft_itoa(type.ui));
	return (len);
}

static int	pointer(t_format f, va_list ap)
{
	t_type	type;
	int		len;

	len = 0;
	type.p = va_arg(ap, void *);
	type.str = lowercase(ft_ulitoabase((unsigned long int)type.p, 16));
	f.flags.pound = 1;
	len += apply_flags(type.str, f);
	ft_strdel(&type.str);
	return (len);
}

static int	catch_other(t_format f)
{
	int		len;

	len = 0;
		if (f.flags.neg)
			ft_putchar(f.spec);
		if (f.width > 0)
		{
			if (f.flags.zero && !f.flags.neg)
				putnchar(f.width - 1, '0');
			else
				putnchar(f.width - 1, ' ');
			len += f.width - 1;
		}
		if (!f.flags.neg)
			ft_putchar(f.spec);
		len++;
	return (len);
}

int	find_specifier(t_format f, va_list ap)
{
	int		len;

	if (f.spec == '%')
		len = percent(f);
	else if (f.spec == 's' || f.spec == 'S')
		len = string(f, ap);
	else if (f.spec == 'c' || f.spec == 'C')
		len = character(f, ap);
	else if (f.spec == 'i' || f.spec == 'd' || f.spec == 'D')
		len = integer(f, ap);
	else if (f.spec == 'X')
		len = hex_upper(f, ap);
	else if (f.spec == 'x')
		len = hex_lower(f, ap);
	else if (f.spec == 'o' || f.spec == 'O')
		len = octal(f, ap);
	else if (f.spec == 'u' || f.spec == 'U')
		len = u_integer(f, ap);
	else if (f.spec == 'p')
		len = pointer(f, ap);
	else
		len = catch_other(f);
	return (len);
}
