/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:01:43 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/07/29 11:34:19 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

// void	p_list(t_list *list)
// {
// 	while (list != NULL)
// 	{
// 		printf("%c -> ", *(char *)list->content);
// 		list = list->next;
// 	}
// 	printf("NULL\n");
// }

// int main()
// {
// 	t_list *list = NULL;
// 	t_list *last;

//     ft_lstadd_front(&list, ft_lstnew("3"));
//     ft_lstadd_front(&list, ft_lstnew("2"));
//     ft_lstadd_front(&list, ft_lstnew("1"));

// 	p_list(list);
//     last = ft_lstlast(list);
//     if (last != NULL)
//         printf("Last: %s\n", (char *)last->content);
// 	return (0);
// }