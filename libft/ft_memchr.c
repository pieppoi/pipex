/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:57:25 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/05/07 16:32:02 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s1, int ch, size_t n)
{
	size_t		i;
	const char	*a;
	void		*s2;

	i = 0;
	a = (const char *)s1;
	s2 = (void *)s1;
	while (i < n)
	{
		if (a[i] == (const char)ch)
		{
			return (s2);
		}
		i++;
		s2++;
	}
	return (0);
}

// #include<stdio.h>
// #include<string.h>
// int	main(void)
// {
// 	char str[] = "abcdef\0ghij";
// 	int ch = 'h';
// 	int	c = 9;
// 	char *p;
// 	p = memchr(str, ch, c);
// 	printf("%s\n", memchr(str, ch, c));
// 	printf("%s\n", ft_memchr(str, ch, c));
// 	return (0);
// }
