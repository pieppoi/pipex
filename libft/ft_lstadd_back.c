/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:19:06 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/07/29 11:34:03 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

// int main()
// {
// 	t_list *list = NULL;

//     ft_lstadd_back(&list, ft_lstnew("3"));
//     ft_lstadd_back(&list, ft_lstnew("2"));
//     ft_lstadd_back(&list, ft_lstnew("1"));

// 	while (list != NULL)
// 	{
// 		printf("%c -> ", *(char *)list->content);
// 		list = list->next;
// 	}
// 	printf("NULL\n");

// 	return (0);
// }