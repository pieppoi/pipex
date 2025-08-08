/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:37:19 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/07/29 11:34:00 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*re_itoa(int n, int i, char *a)
{
	a[i] = '\0';
	while (n > 0)
	{
		a[i - 1] = 48 + (n % 10);
		n /= 10;
		i--;
	}
	return (a);
}

int	count_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*a;
	int		len;

	if (n == -2147483648)
	{
		a = (char *)malloc(12);
		if (!a)
			return (NULL);
		ft_strlcpy(a, "-2147483648", 12);
		return (a);
	}
	len = count_len(n);
	a = (char *)malloc(len + 1);
	if (!a)
		return (NULL);
	if (n == 0)
		a[0] = '0';
	else if (n < 0)
	{
		n *= -1;
		a[0] = '-';
	}
	a = re_itoa(n, len, a);
	return (a);
}

// int main ()
// {
// 	int n = 1;
// 	printf("%s\n", ft_itoa(n));
// 	return (0);
// }