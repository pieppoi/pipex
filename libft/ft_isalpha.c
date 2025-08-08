/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:37:07 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/04/22 13:01:23 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
// #include<stdio.h>
// #include <ctype.h>
// int	main(void)
// {
// 	int c = 'a';
// 	printf("%d\n",isalpha(c));
// 	printf("%d\n",ft_isalpha(c));
// }
