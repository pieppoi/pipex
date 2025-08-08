/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:16:44 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/04/22 13:01:30 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
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
// 	printf("%d\n",isdigit(c));
// 	printf("%d\n",ft_isdigit(c));
// }