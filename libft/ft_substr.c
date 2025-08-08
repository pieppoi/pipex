/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:43:31 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/05/10 17:51:16 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*str;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s < start || len == 0)
	{
		str = ft_calloc(1, 1);
		return (str);
	}
	else if (len_s - start < len)
		len = len_s - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

// #include<stdio.h>
// int	main(void)
// {
// 	char const *s = "01234";
// 	unsigned int start = 3;
// 	size_t	len = 5;
// 	printf("%s\n", ft_substr(s, start, len));
// }
