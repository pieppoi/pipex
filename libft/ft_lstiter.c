/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:44:42 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/07/29 11:34:17 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

// static void	p_content(void *content)
// {
// 	printf("%s\n", (char *)content);
// }

// static void	del(void *content)
// {
// 	free(content);
// }

// int main()
// {
//     t_list *list = ft_lstnew(strdup("One"));
//     ft_lstadd_back(&list, ft_lstnew(strdup("Two")));
//     ft_lstadd_back(&list, ft_lstnew(strdup("Three")));

//     ft_lstiter(list, p_content);

//     ft_lstclear(&list, del);
//     return 0;
// }