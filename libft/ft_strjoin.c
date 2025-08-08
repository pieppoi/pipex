/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:24:55 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/07/29 11:35:16 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	j = 0;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	while (i > j)
	{
		if (ft_strlen(s1) > j)
			str[j] = s1[j];
		else
		{
			str[j] = *s2;
			s2++;
		}
		j++;
	}
	str[j] = '\0';
	return (str);
}

// #include<stdio.h>
// int	main(void)
// {
// 	const char	*s1 = "hello";
// 	const char	*s2 = "world";
// 	char	*a;
// 	a = ft_strjoin(s1, s2);
// 	printf("%s\n", a);
// 	return (0);
// }