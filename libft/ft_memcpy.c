/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:00:42 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/05/10 17:38:07 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	int			i;
	char		*f_cpy;
	const char	*s_cpy;

	i = 0;
	if (!str1 && !str2)
		return (NULL);
	f_cpy = (char *)str1;
	s_cpy = (const char *)str2;
	while (n > 0)
	{
		f_cpy[i] = s_cpy[i];
		n--;
		i++;
	}
	return (str1);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char str1[] = "0123456789";
// 	char str2[] = "abcd\0fgh";
// 	ft_memcpy(str1, str2, 10);
// 	printf("%s\n",str1);
// 	memcpy(str1, str2, 10);
// 	printf("%s\n",str1);
// 	return (0);
// }
