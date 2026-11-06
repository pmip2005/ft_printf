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

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			count += ft_select_method(&args, *(format + 1));
			format++;
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

int	ft_select_method(va_list *args, char specifier)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (specifier == 'u')
		return (ft_putnbr_unsigned(va_arg(*args, unsigned int)));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), specifier));
	else if (specifier == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	else if (specifier == '%')
		return (ft_putchar('%'));
	return (0);
}
