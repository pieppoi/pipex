/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:17:38 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/07/29 11:34:10 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// int main()
// {
// 	t_list *list = NULL;

//     ft_lstadd_front(&list, ft_lstnew("3"));
//     ft_lstadd_front(&list, ft_lstnew("2"));
//     ft_lstadd_front(&list, ft_lstnew("1"));

// 	while (list != NULL)
// 	{
// 		printf("%c -> ", *(char *)list->content);
// 		list = list->next;
// 	}
// 	printf("NULL\n");

// 	return (0);
// }