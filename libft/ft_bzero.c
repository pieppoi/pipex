/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:22:37 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/04/22 13:01:11 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	char	*str1;

	str1 = (char *)str;
	while (n > 0)
	{
		*str1 = '\0';
		str1++;
		str++;
		n--;
	}
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char str[] = "0123456789";
// 	ft_bzero(str+2, 5);
// 	printf("%s\n",str);
// 	bzero(str+2, 5);
// 	printf("%s\n",str);
// 	return (0);
// }
