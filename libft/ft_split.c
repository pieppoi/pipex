/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:55:29 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/07/29 11:34:41 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**all_free(char **b, int i)
{
	i--;
	while (i >= 0)
	{
		free(b[i]);
		i--;
	}
	free(b);
	return (0);
}

static void	input_word(char *word, char const *s, int count, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		count++;
		i++;
	}
	word[i] = '\0';
}

int	sep_count(char const *s, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (j == 0)
				count++;
			j++;
		}
		else
			j = 0;
		i++;
	}
	return (count);
}

char	**ft_split1(char const *s, char c, char **b, int sep)
{
	int	i;
	int	word;
	int	l_count;

	i = 0;
	word = 0;
	l_count = 0;
	while (sep > word)
	{
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			s++;
			l_count++;
		}
		b[word] = (char *)malloc(sizeof(char) * (l_count + 1));
		if (!b[word])
			return (all_free(b, i));
		input_word(b[word], s - l_count, l_count, c);
		l_count = 0;
		word++;
	}
	b[word] = NULL;
	return (b);
}

char	**ft_split(char const *s, char c)
{
	char	**b;
	int		sep;

	if (!s)
		return (NULL);
	sep = sep_count(s, c);
	b = (char **)malloc(sizeof(char *) * (sep + 1));
	if (!b)
		return (NULL);
	b = ft_split1(s, c, b, sep);
	return (b);
}

// #include<stdio.h>
// int main(void)
// {
// 	const char	*s = "      split       this for   me  !       ";
// 	char		c = ' ';
// 	char		**a = ft_split(s, c);

// 	for (int i = 0; i < 6; i++)
// 	{
// 		printf("%s\n", a[i]);
// 	}
// 	// printf("%s\n", a[0]);
// 	// printf("%s\n", a[1]);
// 	// printf("%s\n", a[2]);
// 	// printf("%s\n", a[3]);
// 	// printf("%s\n", a[4]);
// }
