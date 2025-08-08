/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:54:46 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/05/07 16:06:49 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (('a' <= c) && (c <= 'z'))
		c = c - 32;
	return (c);
}
// #include<stdio.h>
// #include<string.h>
// int	main(void)
// {
// 	int c = '1';
// 	printf("%c\n",ft_toupper(c));
// }
