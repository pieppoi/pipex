/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:42:20 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/05/10 16:53:10 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*a;
	const unsigned char	*b;

	i = 0;
	a = (const unsigned char *)s1;
	b = (const unsigned char *)s2;
	while (i < n)
	{
		if (a[i] > b[i])
		{
			return (a[i] - b[i]);
		}
		else if (a[i] < b[i])
		{
			return (a[i] - b[i]);
		}
		i++;
	}
	return (0);
}

// #include<stdio.h>
// #include<string.h>
// int	main(void)
// {
// 	char str[] = "abc\0d";
// 	char ch[] = "abcb";
// 	int	c = 4;
// 	printf("%d\n", memcmp(str, ch, c));
// 	printf("%d\n", ft_memcmp(str, ch, c));
// 	return (0);
// }
