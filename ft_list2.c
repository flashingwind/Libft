/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muiida <muiida@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 01:29:07 by muiida            #+#    #+#             */
/*   Updated: 2024/10/31 05:49:37 by muiida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>

int	ft_lstsize(t_list *lst)
{
	size_t	cnt;

	cnt = 0;
	while (lst != NULL)
	{
		cnt++;
		lst = lst->next;
	}
	return (cnt);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst_front;
	t_list	*new_lst_back;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_lst_front = ft_lstnew(f(lst->content));
	if (new_lst_front == NULL)
		return (0);
	new_lst_back = new_lst_front;
	while (lst != NULL)
	{
		new_lst_back->next = ft_lstnew(f(lst->content));
		if (new_lst_back->next == NULL)
		{
			ft_lstclear(&new_lst_front, del);
			return (NULL);
		}
		new_lst_back->next->next = NULL;
		new_lst_back = new_lst_back->next;
		lst = lst->next;
	}
	return (new_lst_front);
}
