/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:12:55 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/07/29 11:35:00 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*t;

	i = 0;
	t = (char *)s;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return (t + i);
		}
		i++;
	}
	if (s[i] == (char)c)
		return (t + i);
	else
		return (NULL);
}

// int	main(void)
// {
// 	char str[] = "libft-test-tokyo";
// 	int c = 'i' + 256;
// 	char str1[] = "libft-test-tokyo";
// 	int c1 = 'i' + 256;

// 	printf("%s\n", strchr(str, c));
// 	printf("%s\n", ft_strchr(str1, c1));
// 	return (0);
// }
