/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:40:46 by doji              #+#    #+#             */
/*   Updated: 2025/01/28 23:40:47 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*create_new_node(t_list *lst, void *(*f)(void *))
{
	return (ft_lstnew((*f)(lst->content)));
}

static t_list	*handle_error(t_list **head, void (*del)(void *))
{
	ft_lstclear(head, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tmp;

	head = NULL;
	while (lst)
	{
		tmp = create_new_node(lst, f);
		if (!tmp)
			return (handle_error(&head, del));
		ft_lstadd_back(&head, tmp);
		lst = lst->next;
	}
	return (head);
}
