/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muiida <flashingwind@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 01:24:50 by muiida            #+#    #+#             */
/*   Updated: 2024/11/11 01:50:53 by muiida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
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
	t_list	*back;

	if (lst == NULL || new_node == NULL)
	{
		return ;
	}
	back = ft_lstlast(*lst);
	if (back == NULL)
	{
		*lst = new_node;
	}
	else
	{
		back->next = new_node;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

// #include <stdio.h>
// int						main(int argc, const char *argv[])
// {
// 	t_list		*elem;
// 	t_list		*elem1;
// 	t_list		*elem2;
// 	t_list		*elem3;
// 	t_list		*begin;
// 	char		*s0="0";
// 	char		*s1="1";
// 	char		*s2="2";
// 	char		*s3="3";

// 	if (!(elem = ft_lstnew(s0)))
// 		return (0);
// 	if (!(elem1 = ft_lstnew(s1)))
// 		return (0);
// 	if (!(elem2 = ft_lstnew(s2)))
// 		return (0);
// 	if (!(elem3 = ft_lstnew(s3)))
// 		return (0);
// 	begin = NULL;
// 	ft_lstadd_back(&begin, elem3);
// 	ft_lstadd_back(&begin, elem2);
// 	ft_lstadd_back(&begin, elem1);
// 	ft_lstadd_back(&begin, elem);
// 	while (begin!=NULL)
// 	{
// 		printf("%s %zu\n",(char *)begin->content,(size_t)begin->next);
// 		begin = begin->next;
// 	}
// 	return (0);
// }
