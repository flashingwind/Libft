/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muiida <muiida@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 01:29:07 by muiida            #+#    #+#             */
/*   Updated: 2024/11/15 19:52:24 by muiida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst_front;
	t_list	*new_lst_back;
	t_list	*new_node;
	void	*new_content;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_lst_front = NULL;
	new_lst_back = NULL;
	while (lst != NULL)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (new_node == NULL)
		{
			del(new_content);
			ft_lstclear(&new_lst_front, del);
			return (NULL);
		}
		if (new_lst_front == NULL)
			new_lst_front = new_node;
		ft_lstadd_back(&new_lst_back, new_node);
		lst = lst->next;
	}
	return (new_lst_front);
}
