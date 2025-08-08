/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:25:16 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/07/29 11:35:13 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f (i, &s[i]);
		i++;
	}
}

// static void	function(unsigned int i, char *ch)
// {
// 	i = 0;
// 	if (*ch >= 'a' && *ch <= 'z')
// 		*ch = '*';
// }

// int main()
// {
//     char str[] = "string aBcd12";
//     ft_striteri(str, function);
//     printf("%s\n", str); 
//     return 0;
// }