/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c:\Users\crazy\Documents\Code\Test\ft_printf\bonus.c:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoco <marvin.42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-11-07 02:08:50 by ppoco             #+#    #+#             */
/*   Updated: 2026-11-07 02:08:50 by ppoco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_printf(const char *s, ...)
{
	va_list		args;
	t_format	format;
	int			count;

	count = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			s = ft_parse_format(s, &format);
			count += ft_print_format(&args, &format);
		}
		else
			count += ft_putchar(*s++);
	}
	va_end(args);
	return (count);
}
