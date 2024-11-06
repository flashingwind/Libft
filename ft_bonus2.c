/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muiida <muiida@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 01:29:07 by muiida            #+#    #+#             */
/*   Updated: 2024/11/06 16:42:29 by muiida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"
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
	t_list	*new_node;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_lst_front = NULL;
	new_lst_back = NULL;
	while (lst != NULL)
	{
		new_node = ft_lstnew(f(lst->content));
		if (new_node == NULL)
		{
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

// #include <stdlib.h>
// #include "libft.h"
// #include <unistd.h>
// #include <string.h>

// static t_list		*get_lst_new_elem(void *content)
// {
// 	t_list	*elem;

// 	elem = (t_list *)malloc(sizeof(t_list));
// 	if (!elem)
// 		return (NULL);
// 	elem->content = content;
// 	elem->next = NULL;
// 	return (elem);
// }

// static void			free_memory_and_return(char **tab, int i)
// {
// 	while (i >= 0)
// 	{
// 		free(tab[i]);
// 		i--;
// 	}
// 	free(tab);
// }

// static void			free_memory_lst_and_return(t_list *elem)
// {
// 	t_list		*tmp;

// 	while (elem)
// 	{
// 		tmp = elem->next;
// 		free(elem);
// 		elem = tmp;
// 	}
// }

// static char			**get_content_lst(int size)
// {
// 	char	**tab;
// 	int		i;
// 	char	str [] = "abcdef";

// 	if (!(tab = (char **)malloc(sizeof(*tab) * size + 1)))
// 		return (0);
// 	tab[size] = NULL;
// 	i = 0;
// 	while (i < size)
// 	{
// 		str[0] += i % 25;
// 		if (!(tab[i] = strdup((const char *)str)))
// 		{
// 			free_memory_and_return(tab, i - 1);
// 			return (NULL);
// 		}
// 		i++;
// 	}
// 	return (tab);
// }

// static t_list		*get_elem_lst(t_list *begin, char **tab, int i)
// {
// 	t_list		*elem;

// 	if (!(elem = get_lst_new_elem(tab[i])))
// 	{
// 		free_memory_lst_and_return(begin);
// 		free_memory_and_return(tab, 4);
// 		return (NULL);
// 	}
// 	return (elem);
// }

// #include <stdio.h>

// static void			ft_delelem(t_list *elem)
// {
// 	if (elem)
// 		free(elem->content);
// }

// static void		*ft_mapelem(char *content)
// {
// 	int		i;
// 	static int n=0;

// 	content[0] = '0'+n;
// 	n++;
// 	return (content);
// }
// int						main(int argc, const char *argv[])
// {
// 	t_list		*elem;
// 	t_list		*elem2;
// 	t_list		*elem3;
// 	t_list		*elem4;
// 	t_list		*tmp;;
// 	t_list		*list;
// 	char		**tab;

// 	if (argc == 1 || (!(tab = get_content_lst(4))))
// 		return (0);
// 	elem = NULL;
// 	if (!(elem = get_elem_lst(elem, tab, 0)))
// 		return (0);
// 	if (!(elem2 = get_elem_lst(elem, tab, 1)))
// 		return (0);
// 	elem->next = elem2;
// 	if (!(elem3 = get_elem_lst(elem, tab, 2)))
// 		return (0);
// 	elem2->next = elem3;
// 	if (!(elem4 = get_elem_lst(elem, tab, 3)))
// 		return (0);
// 	elem3->next = elem4;
// 	printf("elem content = %s\n", (char *)elem->content);
// 	printf("elem content = %s\n", (char *)elem2->content);
// 	printf("elem content = %s\n", (char *)elem3->content);
// 	printf("elem content = %s\n\n", (char *)elem4->content);
// 	list = ft_lstmap(elem, (void *)&ft_mapelem, (void *)&ft_delelem);
// 	tmp = list;
// 	printf("tmp = %s elem = %s\n", (char *)tmp->content, (char *)elem->content);

// 	while (tmp)
// 	{
// 		printf("tmp = %s\n", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// 	// ft_lstclear(&elem,free);
// 	// ft_lstclear(&list,free);
// 	free_memory_lst_and_return(list);
// 	free_memory_and_return(tab, 4);
// 	free_memory_lst_and_return(elem);
// 	return (0);
// }
