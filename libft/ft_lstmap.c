/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:01:18 by mkazuhik          #+#    #+#             */
/*   Updated: 2025/07/29 11:34:21 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;

	new_lst = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		node = ft_lstnew((*f)(lst->content));
		if (!node)
		{
			ft_lstclear(&node, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, node);
		lst = lst->next;
	}
	return (new_lst);
}

// static void	p_content(void *content)
// {
// 	printf("%s\n", (char *)content);
// }

// static void	del(void *content)
// {
// 	free(content);
// }

// static void	*uppercase(void *content)
// {
// 	int	i;

// 	i = 0;
// 	char *str = (char *)content;
// 	char *new_str = strdup(str);
// 	while (new_str && new_str[i])
// 	{
// 		new_str[i] = ft_toupper(new_str[i]);
// 		i++;
// 	}
// 	return (new_str);
// }

// int	main(void)
// {
// 	t_list *list = ft_lstnew(strdup("one"));
//     ft_lstadd_back(&list, ft_lstnew(strdup("two")));
//     ft_lstadd_back(&list, ft_lstnew(strdup("three")));

//     t_list *mapped_list = ft_lstmap(list, uppercase, del);

//     ft_lstiter(list, p_content);
//     ft_lstiter(mapped_list, p_content);

//     ft_lstclear(&list, del);
//     ft_lstclear(&mapped_list, del);
//     return 0;
// }
