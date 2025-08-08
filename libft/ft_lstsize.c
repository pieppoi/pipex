/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:40:08 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/07/29 11:34:26 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// int	main (void)
// {
// 	t_list *list = NULL;
// 	int	i;

//     ft_lstadd_front(&list, ft_lstnew("0"));
//     ft_lstadd_front(&list, ft_lstnew("1"));
//     ft_lstadd_front(&list, ft_lstnew("2"));
// 	i = ft_lstsize(list);
// 	printf ("%d\n", i);
// }
