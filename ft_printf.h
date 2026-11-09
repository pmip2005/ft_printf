/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoco <marvin.42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-11-05 12:30:17 by ppoco             #+#    #+#             */
/*   Updated: 2026-11-05 12:30:17 by ppoco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

# define HEX "0123456789ABCDEF"
# define HEX_LOW "0123456789abcdef"

typedef struct s_format
{
	int		left_align;
	int		zero_pad;
	int		plus_sign;
	int		space_sign;
	int		alternate;
	int		width;
	char	specifier;
}	t_format;

char	*ft_strtoupper(char *s);
char	*ft_itoa(int n);
char	*ft_itoa_unsigned(unsigned int n);
char	*ft_strdup(const char *src);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_puthex(unsigned long long n, char format);
int		ft_putptr(void *ptr);
int		ft_printf(const char *format, ...);
int		ft_select_method(va_list *args, char specifier);

#endif
