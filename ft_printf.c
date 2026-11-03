/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c:\Users\crazy\Documents\Code\Test\ft_printf\ft_printf.c:+:      :+:    :+:   */
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
				count += write(1, "%", );
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
