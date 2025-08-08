/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:34:34 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/05/09 16:45:18 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (0);
}

// #include<stdio.h>
// #include<string.h>
// int	main(void)
// {
// 	// char str[] = "mkazuhik";
// 	// int c = 'k';
// 	// char str1[] = "mkazuhik";
// 	// int c1 = 'k';
// 	int i = 0;
// 	char *src = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
// 	char *d1 = strrchr(src, '\0');
// 	char *d2 = ft_strrchr(src, '\0');
// 	printf("%s\n", d1);
// 	printf("%s\n", d2);
// 	return (0);
// }
