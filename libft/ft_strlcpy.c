/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:10:09 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/05/09 18:54:22 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	i = ft_strlen(src);
	return (i);
}

// #include<string.h>
// #include<stdio.h>

// int main(void)
// {
// 	const char *src = "0123456789";
// 	char dst[10];
// 	const char *src1 = "0123456789";
// 	char dst1[10];
// 	int x = 9;
// 	printf("%zu\n", ft_strlcpy(dst,src, x));
// 	printf("%s\n", dst);
// 	printf("%zu\n", strlcpy(dst1,src1, x));
// 	printf("%s\n", dst1);
// 	return (0);
// }
