/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:52:35 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/04/22 13:01:34 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (31 < c && c < 127)
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
// 	int c = 32;
// 	printf("%d\n",isprint(c));
// 	printf("%d\n",ft_isprint(c));
// }