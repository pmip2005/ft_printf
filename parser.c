/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c:\Users\crazy\Documents\Code\Test\bonus2.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoco <marvin.42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-11-07 02:07:03 by ppoco             #+#    #+#             */
/*   Updated: 2026-11-07 02:07:03 by ppoco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_init_format(t_format *format)
{
	format->left_align = 0;
	format->zero_pad = 0;
	format->plus_sign = 0;
	format->space_sign = 0;
	format->alternate = 0;
	format->width = 0;
	format->specifier = '\0';
}

static const char	*ft_parse_flags(const char *s, t_format *format)
{
	while (*s == '-' || *s == '0' || *s == '+' || *s == ' ' || *s == '#')
	{
		if (*s == '-')
			format->left_align = 1;
		else if (*s == '0')
			format->zero_pad = 1;
		else if (*s == '+')
			format->plus_sign = 1;
		else if (*s == ' ')
			format->space_sign = 1;
		else if (*s == '#')
			format->alternate = 1;
		s++;
	}
	if (format->left_align)
		format->zero_pad = 0;
	if (format->plus_sign)
		format->space_sign = 0;
	return (s);
}

static const char	*ft_parse_width(const char *s, t_format *format)
{
	while (*s >= '0' && *s <= '9')
	{
		format->width = format->width * 10 + (*s - '0');
		s++;
	}
	return (s);
}

const char	*ft_parse_format(const char *s, t_format *format)
{
	ft_init_format(format);
	s = ft_parse_flags(s, format);
	s = ft_parse_width(s, format);
	format->specifier = *s;
	if (*s)
		s++;
	return (s);
}


