/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:00:37 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/05/13 15:46:45 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *text, const char *pattern, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!pattern[0])
		return ((char *)text);
	if (len == 0)
		return (NULL);
	while (text[i] != '\0' && (len > i))
	{
		if (text[i] == pattern[j])
		{
			while (text[i + j] == pattern[j] && (i + j) < len)
			{
				if (pattern[j + 1] == '\0')
					return ((char *)(text + i));
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}

// int  main(void)
// {
// // 	const char    *a = "libft-test-tokyo";
// // 	const char    *b = "";
// // 	// for (int i = 0; i < 16; i++)
// // 	// {
// // 	// 	printf("%s ", ft_strnstr(a, b, i));
// // 	// 	printf("%s\n", strnstr(a, b, i));
// // 	// 	b = "libft-test-tokyo";
// // 	// 	printf("%s ", ft_strnstr(a, b, i));
// // 	// 	printf("%s\n", strnstr(a, b, i));
// // 	// 	b = "libft";
// // 	// 	printf("%s ", ft_strnstr(a, b, i));
// // 	// 	printf("%s\n", strnstr(a, b, i));
// // 	// 	b = "test";
// // 	// 	printf("%s ", ft_strnstr(a, b, i));
// // 	// 	printf("%s\n", strnstr(a, b, i));
// // 	// 	b = "tokyo";
// // 	// 	printf("%s ", ft_strnstr(a, b, i));
// // 	// 	printf("%s\n", strnstr(a, b, i));
// // 	// 	b = "libft~";
// // 	// 	printf("%s ", ft_strnstr(a, b, i));
// // 	// 	printf("%s\n", strnstr(a, b, i));
// // 	// 	b = "z";
// // 	// 	printf("%s ", ft_strnstr(a, b, i));
// // 	// 	printf("%s\n", strnstr(a, b, i));
// // 	// }
// 	printf("%s\n", ft_strnstr("oh no not the empty string !", "", 0));
// 	printf("%s\n", strnstr("oh no not the empty string !", "", 0));
// 	return(0);
// }