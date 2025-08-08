/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:18:15 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/07/29 11:35:30 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	left_count(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (set[j] != '\0')
	{
		if (s1[i] == set[j])
		{
			j = 0;
			i++;
		}
		else
			j++;
	}
	return (i);
}

int	right_count(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	i = i - 1;
	while (set[j] != '\0')
	{
		if (s1[i] == set[j])
		{
			j = 0;
			i--;
		}
		else
			j++;
	}
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		count;
	int		j;
	int		i;
	char	*a;

	if (!s1 || !set)
		return (NULL);
	count = right_count(s1, set);
	i = left_count(s1, set);
	if (count < i)
		i = 0;
	else
		i = count - i;
	a = (char *)malloc(sizeof(char) * (i + 1));
	if (!a)
		return (NULL);
	a[0] = '\0';
	j = left_count(s1, set);
	if (i >= 1)
		ft_strlcpy(a, &s1[j], i + 1);
	return (a);
}

// #include<stdio.h>
// int	main(void)
// {
// 	char	*a = "   xxxtripouille";
// 	char	*b = " x";
//  	printf("%s\n", ft_strtrim(a, b));
// 	// char	*a1 = "   xxx   xxx";
// 	// char	*b1 = " x";
//  	// printf("%s\n", strtrim(a1, b1));
// 	return (0);
// }