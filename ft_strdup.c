/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoco <ppoco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 14:20:18 by ppoco             #+#    #+#             */
/*   Updated: 2026/10/30 20:43:35 by ppoco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*str;
	size_t	strlen;

	strlen = ft_strlen(src);
	str = malloc((size_t)strlen + 1);
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, src);
	return (str);
}

// int main(void)
// {
// 	char *copy;
// 	copy = ft_strdup("libft");
// 	printf("%s\n", copy);
// 	free(copy);
// 	return (0);
// }
// cc -Wall -Wextra -Werror -include stdio.h *.c -o test && ./test
