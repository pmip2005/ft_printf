/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoco <marvin.42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-11-06 12:44:13 by ppoco             #+#    #+#             */
/*   Updated: 2026-11-06 12:44:13 by ppoco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	count;

	count = ft_putstr("0x");
	count += ft_puthex((unsigned long long)ptr, 'x');
	return (count);
}

int	ft_puthex(unsigned long long n, char specifier)
{
	char	buffer[sizeof(unsigned long long) * 2];
	char	*digits;
	int		count;
	int		i;

	digits = "0123456789abcdef";
	if (specifier == 'X')
		digits = HEX;
	i = 0;
	while (n || i == 0)
	{
		buffer[i++] = digits[n % 16];
		n /= 16;
	}
	count = 0;
	while (i > 0)
		count += ft_putchar(buffer[--i]);
	return (count);
}
