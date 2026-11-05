/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c:\Users\c\Code\Test\ft_printf\ft_printf.c:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoco <marvin.42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-11-03 00:44:20 by ppoco             #+#    #+#             */
/*   Updated: 2026-11-03 00:44:20 by ppoco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

static int	ft_putstr(char *s)
{
	int	count;

	if (!s)
		return (write(1, "(null)", 6));
	count = 0;
	while (*s)
	{
		count += ft_putchar(*s);
		s++;
	}
	return (count);
}

static int	ft_putnbr(int n)
{
	int		i;
	char	*s;

	s = ft_itoa(n);
	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				count += ft_putchar(va_arg(args, int));
			else if (*format == 's')
				count += ft_putstr(va_arg(args, char *));
			else if (*format == 'd' || *format == 'i')
				count += ft_putnbr(va_arg(args, int));
			else if (*format == 'u')
				count += ft_putnbr_unsigned(va_arg(args, unsigned int));
			else if (*format == 'x' || *format == 'X')
				count += ft_puthex(va_arg(args, unsigned int), *format);
			else if (*format == 'p')
				count += ft_putptr(va_arg(args, void *));
			else if (*format == '%')
				count += write(1, "%", 1);
		}
		else
		{
			count += ft_putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
