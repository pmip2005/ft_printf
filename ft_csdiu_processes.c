/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_csdiu_processes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoco <marvin.42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-11-05 12:33:20 by ppoco             #+#    #+#             */
/*   Updated: 2026-11-05 12:33:20 by ppoco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
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

int	ft_putnbr(int n)
{
	int		i;
	char	*s;

	s = ft_itoa(n);
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	free(s);
	return (i);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int		i;
	char	*s;

	s = ft_itoa_unsigned(n);
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	free(s);
	return (i);
}
