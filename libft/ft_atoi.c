/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:10:28 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/08/14 16:35:51 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	long_overflow(int sign, const char *str)
{
	long	temp;
	long	value;

	value = 0;
	while (ft_isdigit(*str))
	{
		temp = value * 10 + *str - '0';
		if (sign == 1 && !(temp >= value))
			return (LONG_MAX);
		else if (sign == -1 && !(temp >= value))
			return (LONG_MIN);
		value = temp;
		str++;
	}
	return (value);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	a;

	i = 0;
	sign = 1;
	a = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	a = long_overflow(sign, str + i);
	return (a * sign);
}

// int main(void)
// {
//     int i;
//     char *s;

//     s = "2147483648";
//     i = ft_atoi(s);
//     printf("i = %d\n",i);
// 	printf("i = %d\n",atoi(s));
// }