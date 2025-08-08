/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:20:57 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/05/09 16:24:11 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	int		i;

	i = 0;
	if (!str1 && !str2)
		return (0);
	if (str1 > str2)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*(char *)(str1 + i) = *(char *)(str2 + i);
			i--;
		}
	}
	else if (str1 <= str2)
	{
		while (i < (int)n)
		{
			*(char *)(str1 + i) = *(char *)(str2 + i);
			i++;
		}
	}
	return (str1);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char str[] = "0123456789";
// 	char str1[] = "0123456789";
// 	ft_memmove(str+2, str, 9);
// 	printf("%s\n",str);
// 	memmove(str1+2, str1, 9);
// 	printf("%s\n",str1);
// 	return (0);
// }
