/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:41:27 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/07/29 11:34:15 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// static void	del(void *content)
// {
// 	free(content);
// }

// int main()
// {
// 	char *content = strdup("Dynamic string content");
//     if (!content) {
//         perror("Failed to allocate content");
//         exit(EXIT_FAILURE);
//     }

//     t_list *node = ft_lstnew(content);
//     if (!node)
// 	{
//         perror("Failed to create list node");
//         free(content);
//         exit(EXIT_FAILURE);
//     }

//     ft_lstdelone(node, del);

//     printf("Node and its content have been deleted\n");

// 	return (0);
// }