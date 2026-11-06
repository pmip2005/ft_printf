/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoco <ppoco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:20:26 by ppoco             #+#    #+#             */
/*   Updated: 2026/10/30 20:41:16 by ppoco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

static size_t	count_digits(int n)
{
	int		num;
	size_t	len;

	len = 0;
	num = n;
	while (num)
	{
		len++;
		num /= 10;
	}
	return (len);
}

static size_t	count_digits_unsigned(unsigned int n)
{
	unsigned int		num;
	size_t				len;

	len = 0;
	num = n;
	while (num)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	neg;
	size_t	len;
	char	*ptr;

	if (n == 0)
		return (ft_strdup("0"));
	len = count_digits(n);
	neg = 0;
	if (n < 0)
		neg = 1;
	len += neg;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	len --;
	while (n != 0)
	{
		ptr[len] = ft_abs(n % 10) + '0';
		n /= 10;
		len--;
	}
	if (neg == 1)
		ptr[0] = '-';
	return (ptr);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	size_t	len;
	char	*ptr;

	if (n == 0)
		return (ft_strdup("0"));
	len = count_digits_unsigned(n);
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	len --;
	while (n != 0)
	{
		ptr[len] = ft_abs(n % 10) + '0';
		n /= 10;
		len--;
	}
	return (ptr);
}

// int main(void)
// {
// 	char *number;
// 	number = ft_itoa(-42);
// 	printf("%s\n", number);
// 	free(number);
// 	return (0);
// }
// cc -Wall -Wextra -Werror -include stdio.h *.c -o test && ./test
