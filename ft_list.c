/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muiida <muiida@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 01:24:50 by muiida            #+#    #+#             */
/*   Updated: 2024/10/31 02:12:12 by muiida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = (t_list *)NULL;
	return (new_node);
}

void	ft_lstadd_front(t_list **lst, t_list *new_node)
{
	if (lst != NULL && new_node != NULL)
	{
		new_node->next = *lst;
		*lst = new_node;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	if (lst == NULL || new_node == NULL)
	{
	}
	else if (*lst == NULL)
	{
		*lst = new_node;
	}
	else
	{
		*lst = ft_lstlast(*lst);
		(*lst)->next = new_node;
		*lst = (*lst)->next;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}