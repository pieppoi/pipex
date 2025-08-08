/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:17:08 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/07/29 11:34:07 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		node = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = node;
	}
}

// static void	del(void *content)
// {
// 	free(content);
// }

// int main()
// {
//     t_list *list = ft_lstnew(strdup("1"));
//     ft_lstadd_back(&list, ft_lstnew(strdup("2")));
//     ft_lstadd_back(&list, ft_lstnew(strdup("3")));
//     ft_lstclear(&list, del);
//     printf("List cleared.\n");
//     return 0;
// }