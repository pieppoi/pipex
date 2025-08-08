/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:46:54 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/04/22 13:01:27 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
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
// 	int c = '\0';
// 	printf("%d\n",isascii(c));
// 	printf("%d\n",ft_isascii(c));
// }