/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:59:01 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/05/09 18:39:39 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
// #include<stdio.h>
// #include<string.h>
// int	main(void)
// {
// 	int len;
// 	char	str[] = "abcde";
// 	len = strlen(str);
// 	printf("%d\n",len);
// 	len = ft_strlen(str);
// 	printf("%d\n",len);
// }
