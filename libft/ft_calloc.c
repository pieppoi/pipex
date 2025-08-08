/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:00:38 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/05/16 18:28:35 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (count > 0 && size > 0 && (SIZE_MAX / size) < count)
	{
		return (NULL);
	}
	p = (void *)malloc(count * size);
	if (!p)
	{
		return (NULL);
	}
	ft_bzero(p, count * size);
	return (p);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *ch;

// 	ch = (char*)ft_calloc(42,42);

// 	puts("文字列を入力してください。");

// 	gets(ch);

// 	printf("入力した文字は→%s\n",ch);

// 	free(ch);

// 	return (0);
// }