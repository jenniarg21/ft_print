/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 03:43:12 by jargote           #+#    #+#             */
/*   Updated: 2017/03/19 23:43:47 by jargote          ###   ########.fr       */
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
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

void	putspaces(int n)
{
	while (n-- > 0)
		ft_putchar(' ');
}

void	find_specifier(char specifier, va_list ap, int width, int precision)
{
	t_type	type;

	if (specifier == 's' || specifier == 'S')
	{
		type.str = va_arg(ap, char *);
		if (precision >= 0)
			type.str = ft_strsub(type.str, 0, precision);
		if (width <= (int)ft_strlen(type.str) && width > precision) // condense code?
		{
			width -= precision;
			putspaces(width);
		}
		else
		{
			width -= ft_strlen(type.str);
			putspaces(width);
		}
		ft_putstr(type.str);
	}
	else if (specifier == 'c' || specifier == 'C')
	{
		if (width > 0)
			putspaces(width - 1);
		type.c = va_arg(ap, int);
		ft_putchar(type.c);
	}
	else if (specifier == 'i' || specifier == 'd')
	{
		type.i = va_arg(ap, int);
		ft_putnbr(type.i);
	}
	else if (specifier == 'X')
	{
		type.ui = va_arg(ap, unsigned int);
		ft_putstr(ft_itoabase(type.ui, 16));
	}
	else if (specifier == 'x')
	{
		type.ui = va_arg(ap, unsigned int);
		ft_putstr(lowercase(ft_itoabase(type.ui, 16)));
	}
	else if (specifier == 'o' || specifier == 'O')
	{
		type.ui = va_arg(ap, unsigned int);
		ft_putstr(ft_itoabase(type.ui, 8));
	}
	else if (specifier == 'u' || specifier == 'U')
	{
		//if (va_arg(ap, long int) < 0)
		//	type.ui = UINT_MAX + va_arg(ap, long int) - 1;
		//else
			type.ui = va_arg(ap, unsigned int);
			ft_putuint(type.ui);
//		ft_putstr(ft_itoa(type.ui));
	}
	else if (specifier == 'p')
	{
		type.p = va_arg(ap, void *);
		ft_putstr(PTR_PRE);
		ft_putstr(lowercase(ft_itoabase(type.ui, 16)));
	}
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

	i = *count;
	number_strlen = count_isdigit(&fmt[*i + 1]); // count while ft_isdigit()
	number_str = ft_strsub(&fmt[*i + 1], 0, number_strlen);
/*	ft_putendl(number_str);
	ft_putstr("WIDTH_STRLEN: ");
	ft_putnbr(width_strlen);
	ft_putchar('\n');*/
	*i += number_strlen;	
	*count = i;
	return (ft_atoi(number_str));
}

void	find_type(char *fmt, int *i, va_list ap)
{
//	char	*type_str;
	char	specifier;
	int		width;
	int		precision;

	if (fmt[*i + 1])
	{
		if (fmt[*i + 1] == '%')
			ft_putchar(fmt[*i]);
		else
		{
//ft_putstr("*I = ");
//ft_putnbr(*i);
//ft_putchar('\n');
			// use a function (maybe from library) that finds if the fmt[i+1] is equal to any of the chars in "sSpdDioOuUxXcC" ----- use ft_strchr(*s, c)
		//	type_str = ft_strchr("sSpdDioOuUxXcC", fmt[*i + 1]); // still need to account for other components (precision, width, etc.)--use isdigit()
			//type_str = &fmt[*i + 1];
			specifier = fmt[*i + 1];
			width = 0;
			if (ft_isdigit(specifier))
			{
				width = find_number(fmt, &i);
				specifier = fmt[*i + 1];
			}
			precision = 0;
			if (specifier == '.')
			{
				*i += 1;
				precision = find_number(fmt, &i);
				specifier = fmt[*i + 1];
			}
			find_specifier(specifier, ap, width, precision);
//ft_putstr("\t\t\tSPECIFIER = ");
//ft_putchar(specifier);
//ft_putchar('\n');
		}
		*i += 1;
	}
	else
		err();
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			count;

	va_start(ap, format);
	count = 0;
	i = 0;
	while (format[i])
	{
//ft_putstr("I = ");
//ft_putnbr(i);
//ft_putchar('\n');
		if (format[i] == '%')
			find_type((char *)format, &i, ap);
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	// either use static count if printing directly or use ft_strlen() if storing value in an array.
	return (count);
}
