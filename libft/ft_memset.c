/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:47:44 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/05/09 16:20:14 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int ch, size_t n)
{
	char	*str1;
	size_t	i;

	i = 0;
	str1 = (char *)str;
	while (n > i)
	{
		str1[i] = ch;
		i++;
	}
	return (str);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	// char str[100] = "";
// 	printf("%s\n",ft_memset("", 'A', 0));
// 	printf("%s\n",memset("", 'A', 0));
// 	return (0);
// }
