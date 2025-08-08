/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:39:30 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/04/22 13:01:19 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ('0' <= c && c <= '9')
	{
		return (1);
	}
	else if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
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
// 	printf("%d\n",isalnum(c));
// 	printf("%d\n",ft_isalnum(c));
// }