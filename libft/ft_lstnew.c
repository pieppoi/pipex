/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:14:33 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/07/29 11:34:23 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->content = content;
	node->next = NULL;
	return (node);
}

// int main()
// {
// 	int a = 1, b = 2, c = 3;

// 	t_list *node1 = ft_lstnew(&a);
// 	t_list *node2 = ft_lstnew(&b);
// 	t_list *node3 = ft_lstnew(&c);

// 	node1->next = node2;
// 	node2->next = node3;

// 	while (node1 != NULL)
// 	{
// 		printf("%d -> ", *(int *)node1->content);
// 		node1 = node1->next;
// 	}
// 	printf("NULL\n");

// 	free(node1);
// 	free(node2);
// 	free(node3);

// 	return (0);
// }
