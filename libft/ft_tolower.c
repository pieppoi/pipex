/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:03:44 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/04/22 13:45:17 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (('A' <= c) && (c <= 'Z'))
		c = c + 32;
	return (c);
}
// #include<stdio.h>
// #include<string.h>
// int	main(void)
// {
// 	int c = 'H';
// 	printf("%c\n",ft_toliwer(c));
// }
