/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:51:27 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/05/15 14:33:03 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_l;
	size_t	src_l;

	src_l = ft_strlen(src);
	if (!dest && size == 0)
		return (src_l);
	dest_l = ft_strlen(dest);
	i = 0;
	j = dest_l;
	if (dest_l < size - 1 && size > 0)
	{
		while (src[i] && dest_l + i < size - 1)
		{
			dest[j] = src[i];
			j++;
			i++;
		}
		dest[j] = '\0';
	}
	if (dest_l >= size)
		return (size + src_l);
	return (dest_l + src_l);
}

// int	main(void)
// {
// // // 	char dest[101] = "ABCDE";
// // 	char src[101] = "1234";
// // // 	char dest1[101] = "ABCDE";
// // 	char src1[101] = "1234";
// // 	for (int i = 0; i < 99; i++)
// // 	{
// // 		src[i] = i + 1;
// // 		src1[i] = i + 1;
// // 	}
// 	char b[0xF] = "nyan !";
// 	int x = 2;
// 	unsigned int result1 = ft_strlcat(((void *)0), b, x);
// 	printf("%s: %u\n",NULL,  result1);
// 	// unsigned int result2 = strlcat(((void *)0), b, x);
// 	// printf("%s: %u\n", NULL, result2);
// 	return (0);
// }
