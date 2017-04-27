/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 03:43:12 by jargote           #+#    #+#             */
/*   Updated: 2017/03/23 17:26:22 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

								#include "stdio.h"

void	err(void)
{
	//free arrays if needed and call va_end(ap)??
	exit(0);
}

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

char	*lowercase(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}



void	putnchar(int n, char c)
{
	while (n-- > 0)
		ft_putchar(c);
}

int		apply_flags(char *str, t_flags f, int width, int precision, char s)
{
	int	len;
	int	padding;
	int	neg;
	int	prec_zero;

	len = 0;
	padding = 0;
	prec_zero = 0;
	neg = 0;
	if (str[0] == '-')
		neg = 1;
	if (precision == -1)
	{
		if (str[0] == '0')
		{
			prec_zero = 1;
			width++;
		}
		precision = 0;
	}
	if (f.pound)
	{
		if (s == 'o' || s == 'O')
			width--;
		else if (str[0] != 0 && (s == 'x' || s == 'X'))
			width -= 2;
	}
	if (width > (int)ft_strlen(str) && width > (precision + neg)) // check tester; precision buffs the strlen of type.str
	{
		padding = 1;
		//pos and sp
		if (s == 'd' || s == 'i' || s == 'D')
		{
			if (!neg && (f.pos || f.sp))
				width--;
		}
		//end pos and sp
		if (precision > (int)ft_strlen(str) - neg)
			width -= (precision + neg);
		else
			width -= ft_strlen(str);
		len += width;
	}
	if (!f.neg && padding && (!f.zero || (f.zero && precision)))
		putnchar(width, ' ');
	if (s == 'd' || s == 'i' || s == 'D')
	{
		if (neg)
		{
			ft_putchar('-');
			str++;
			len++;
		}
	//pos and sp
		else if (f.pos)
		{
			ft_putchar('+');
			len++;
		}
		else if (f.sp)
		{
			ft_putchar(' ');
			len++;
		}
	}
	//end pos and sp
	if (f.pound)
	{
		if ((s == 'o' || s == 'O') && (str[0] != '0' || prec_zero))
		{
			ft_putchar('0');
			len++;
		}
		else if (str[0] != '0' && s == 'x')
		{
			ft_putstr("0x");
			len += 2;
		}
		else if (str[0] != '0' && s == 'X')
		{
			ft_putstr("0X");
			len += 2;
		}
	}
	if (precision > (int)ft_strlen(str))
	{
		putnchar(precision - ft_strlen(str), '0');
		len += precision - ft_strlen(str);
	}
	if (!f.neg && f.zero && padding && !precision && !prec_zero)
		putnchar(width, '0');
	if (!prec_zero)
	{
		ft_putstr(str);
		len += ft_strlen(str);
	}
	if (f.neg && padding)
		putnchar(width, ' ');
	return (len);
}

int		apply_flags_str(char *str, t_flags f, int width, int precision, char s)
{
	int		len;
	char	*t;
	int		p_null;

	len = 0;
	p_null = 0;
	if (s == 'p' && ft_strcmp(str, "0x0") == 0)
		p_null = 1;
	if (precision > 0 || precision == -1)
	{
		if (precision == -1)
		{
			if (s == 's')
				precision = 0;
			else if (s == 'p')
				precision = 2;
		}
		t = ft_strsub(str, 0, precision);
		if (s == 'p' && !p_null)
			ft_strdel(&str);
		str = t;
	}
	if (f.neg)
		ft_putstr(str);
/*	if (width <= (int)ft_strlen(str) && width > precision) // condense code?
	{
		if (precision > 0)
			width -= precision;
		if (f.zero && !f.neg)
			putnchar(width, '0');
		else
			putnchar(width, ' ');
	}
	else */if (width > (int)ft_strlen(str))
	{
		width -= ft_strlen(str);
		if (f.zero && !f.neg)
			putnchar(width, '0');
		else
			putnchar(width, ' ');
		len += width;
	}
	if (!f.neg)
		ft_putstr(str);
//	len += width;
	len += ft_strlen(str);
	if (precision > 0 || (s == 'p' && !p_null))
		ft_strdel(&str);
	return (len);
}

int	find_specifier(t_format f, va_list ap)
{
	t_type	type;
	int		len;
	char	*t;
//	int		padding;
//	int 		neg;

	len = 0;
	if (f.specifier == '%')
	{
		if(f.flags.neg)
			ft_putchar(f.specifier);
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
			ft_putchar(f.specifier);
	}
	else if (f.specifier == 's' || f.specifier == 'S')
	{
		type.str = va_arg(ap, char *);
		if (!type.str)
			type.str = "(null)";
		len += apply_flags_str(type.str, f.flags, f.width, f.precision, f.specifier);
	}
	else if (f.specifier == 'c' || f.specifier == 'C')
	{
		if (f.length && f.length[0] == 'l')
			type.ui = va_arg(ap, unsigned int);
		else
			type.c = va_arg(ap, int);
		if (f.flags.neg)
		{
			if (f.length && f.length[0] == 'l')
				write(1, &type.ui, 1);
			else
				ft_putchar(type.c);
		}
		if (f.width > 0)
		{
			if (f.flags.zero && !f.flags.neg)
				putnchar(f.width - 1, '0');
			else
				putnchar(f.width - 1, ' ');
			len += f.width - 1;
		}
		if (!f.flags.neg)
		{
		/*	if (f.length && f.length[0] == 'l')
				write(1, &type.ui, 1);
			else*/
				ft_putchar(type.c);
		}
		len++;
	}
	else if (f.specifier == 'i' || f.specifier == 'd' || f.specifier == 'D')
	{
		// have condition for length values if passed and if so modify type for va_arg() accordingly && create ft_itoa() for additional length values
		if (f.specifier == 'D' || (f.length && (f.length[0] == 'l' || f.length[1] == 'l' || f.length[0] == 'z')))
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
					type.str = ft_sitoabase(type.i, 10);
				else if (f.length[1] == 'h')
					type.str = ft_citoabase(type.i, 10);
			}
			else
				type.str = ft_itoa(type.i);
		}
		len += apply_flags(type.str, f.flags, f.width, f.precision, f.specifier);
		ft_strdel(&type.str);
	}
	else if (f.specifier == 'X')
	{
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
					type.str = ft_usitoabase(type.ui, 16);
				else if (f.length[1] == 'h')
					type.str = ft_ucitoabase(type.ui, 16);
			}
			else
				type.str = ft_itoabase(type.ui, 16);
		}
	//	ft_putstr(type.str);
	//	len += ft_strlen(type.str);
		len += apply_flags(type.str, f.flags, f.width, f.precision, f.specifier);
		ft_strdel(&type.str);
	}
	else if (f.specifier == 'x')
	{
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
					type.str = lowercase(ft_usitoabase(type.ui, 16));
				else if (f.length[1] == 'h')
					type.str = lowercase(ft_ucitoabase(type.ui, 16));
			}
			else
				type.str = lowercase(ft_itoabase(type.ui, 16));
		}
	//	ft_putstr(type.str);
	//	len += ft_strlen(type.str);
		len += apply_flags(type.str, f.flags, f.width, f.precision, f.specifier);
		ft_strdel(&type.str);
	}
	else if (f.specifier == 'o' || f.specifier == 'O')
	{
		if (f.specifier == 'O' || (f.length && (f.length[0] == 'l' || f.length[1] == 'l')))
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
					type.str = ft_usitoabase(type.ui, 8);
				else
					type.str = ft_ucitoabase(type.ui, 8);
			}
			else
				type.str = ft_itoabase(type.ui, 8);
		}
	//	ft_putstr(type.str);
	//	len += ft_strlen(type.str);
		len += apply_flags(type.str, f.flags, f.width, f.precision, f.specifier);
		ft_strdel(&type.str);
	}
	else if (f.specifier == 'u' || f.specifier == 'U')
	{
		if (f.specifier == 'U' || (f.length && (f.length[0] == 'l' || f.length[1] == 'l')))
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
					type.str = ft_usitoa((short)type.ui);
				else if (f.length[1] == 'h')
					type.str = ft_ucitoa((char)type.ui);
			}
			else
			{
			//ft_putuint(type.ui);
				type.str = ft_uitoa(type.ui);
			}
		}
		/*	ft_putstr(type.str);
			len += ft_strlen(type.str);*/
		len += apply_flags(type.str, f.flags, f.width, f.precision, f.specifier);
		ft_strdel(&type.str);
//		ft_putstr(ft_itoa(type.ui));
	}
	else if (f.specifier == 'p')
	{
		type.p = va_arg(ap, void *);
	//	ft_putstr(PTR_PRE);
		if (type.p)
		{
			t = lowercase(ft_itoabase((int)type.p, 16));
			type.str = (char *)malloc(ft_strlen(PTR_PRE) + ft_strlen(t) + 1);
			ft_bzero(type.str, ft_strlen(PTR_PRE) + ft_strlen(t) + 1);
			type.str = ft_strcpy(type.str, PTR_PRE);
			type.str = ft_strcat(type.str, t);
			free(t);
		}
		else
		{
			type.str = "0x0";
		}
	//	ft_putstr(type.str);
	//	len += ft_strlen(PTR_PRE);
	//	len += ft_strlen(type.str);
		len += apply_flags_str(type.str, f.flags, f.width, f.precision, f.specifier);
	}
	else
	{
		if (f.width > 1)
		{
			putnchar(f.width - 1, ' ');
			len += f.width - 1;
		}
		ft_putchar(f.specifier);
		len++;
	}
	if (f.length)
		ft_strdel(&f.length);
	return (len);
}

int		count_isdigit(char *str)
{
	int		count;

	count = 0;
	while (ft_isdigit(str[count]))
		count++;
	return (count);
}

int		find_number(char *fmt, int **count)
{
	char	*number_str;
	int		number_strlen;
	int		*i;
	int		nbr;

	i = *count;
	number_strlen = count_isdigit(&fmt[*i + 1]); // count while ft_isdigit()
	number_str = ft_strsub(&fmt[*i + 1], 0, number_strlen);
/*	ft_putendl(number_str);
	ft_putstr("WIDTH_STRLEN: ");
	ft_putnbr(width_strlen);
	ft_putchar('\n');*/
	*i += number_strlen;	
	*count = i;
	nbr = ft_atoi(number_str);
	ft_strdel(&number_str);
	return (nbr);
}

t_flags		find_flags(char *fmt, int *i)
{
	t_flags	f;
	int	flag;

	f.pound = 0;
	f.zero = 0;
	f.neg = 0;
	f.sp = 0;
	f.pos = 0;
	flag = 1;
	*i += 1;
	while (flag)
	{
		if (fmt[*i] == '#')
			f.pound = 1;
		else if (fmt[*i] == '0')
			f.zero = 1;
		else if (fmt[*i] == '-')
			f.neg = 1;
		else if (fmt[*i] == ' ')
			f.sp = 1;
		else if (fmt[*i] == '+')
			f.pos = 1;
		else
		{
			flag = 0;
			*i -= 2;
		}
		*i += 1;
	}
	return (f);
}

char	*find_length(char *fmt, int *i)
{
	char	*length;
	int		len;
	char	f;
	char	*t1;
	char	*t2;

	f = fmt[*i + 1];
	if (f == 'h' || f == 'l' || f == 'j' || f == 'z')
	{
		f = fmt[*i + 2];
		if (f == 'h' || f == 'l')
			len = 2;
		else
			len = 1;
	}
	else
		return (NULL);
	if (!(length = ft_strnew(len)))
		return (NULL);
	if (!(t1 = ft_strsub(fmt, *i + 1, len)))
	{
		ft_strdel(&length);
		return (NULL);
	}
	t2 = length;
	length = t1;
	ft_strdel(&t2);
	*i += len;
	return (length);
}

int		find_type(char *f, int *i, va_list ap)
{
//	char	*type_str;
//	char	specifier;
///	int		width;
//	int		precision;
	int		len;
//	t_flags		flag;
	t_format	fmt;

	len = 0;
	if (f[*i + 1])
	{
//ft_putstr("*I = ");
//ft_putnbr(*i);
//ft_putchar('\n');
			// use a function (maybe from library) that finds if the fmt[i+1] is equal to any of the chars in "sSpdDioOuUxXcC" ----- use ft_strchr(*s, c)
		//	type_str = ft_strchr("sSpdDioOuUxXcC", fmt[*i + 1]); // still need to account for other components (precision, width, etc.)--use isdigit()
			//type_str = &fmt[*i + 1];
			fmt.flags = find_flags(f, i);
			fmt.length = find_length(f, i);
			fmt.specifier = f[*i + 1];
			fmt.width = 0;
			if (ft_isdigit(fmt.specifier))
			{
				fmt.width = find_number(f, &i);
				fmt.specifier = f[*i + 1];
			}
			fmt.precision = 0;
			if (fmt.specifier == '.')
			{
				*i += 1;
				fmt.precision = find_number(f, &i);
				if (fmt.precision == 0)
					fmt.precision = -1;
				fmt.specifier = f[*i + 1];
			}
			len += find_specifier(fmt, ap);
//ft_putstr("\t\t\tSPECIFIER = ");
//ft_putchar(specifier);
//ft_putchar('\n');
		*i += 1;
	}
//	else
//		err();
	return (len);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			count;
	int			len;

	va_start(ap, format);
	count = 0;
	len = 0;
	i = 0;
	while (format[i])
	{
//ft_putstr("I = ");
//ft_putnbr(i);
//ft_putchar('\n');
		if (format[i] == '%')
			len += find_type((char *)format, &i, ap);
		else
		{
			ft_putchar(format[i]);
			len++;
		}
		i++;
	}
	va_end(ap);
	// either use static count if printing directly or use ft_strlen() if storing value in an array.
	return (len);
}
