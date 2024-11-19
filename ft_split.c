/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muiida <muiida@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:38:37 by muiida            #+#    #+#             */
/*   Updated: 2024/11/19 17:40:04 by muiida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_sect(char const *str, char sep)
{
	size_t	cnt;
	char	*s;

	s = (char *)str;
	cnt = 0;
	while (s != NULL && *s != '\0')
	{
		if (*s == sep)
		{
			s++;
		}
		else
		{
			cnt++;
			while (*s != '\0' && *s != sep)
				s++;
		}
	}
	return (cnt);
}

static char	**free_all(char **strs, size_t i)
{
	while (i > 0)
		free(strs[--i]);
	free(strs);
	return (NULL);
}

static char	**malloc_tab(char const *s, char c)
{
	char	**strs;

	if (s == NULL)
		return (NULL);
	strs = (char **)malloc(sizeof(char *) * (count_sect(s, c) + 1));
	if (strs == NULL)
		return (NULL);
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	i;
	size_t	len;

	strs = malloc_tab(s, c);
	if (strs == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s != '\0' && *s != c && ++len)
				s++;
			strs[i] = ft_substr(s - len, 0, len);
			if (strs[i] == NULL)
				return (free_all(strs, i));
			i++;
		}
		else
			s++;
	}
	strs[i] = NULL;
	return (strs);
}

// #include <stdio.h>

// int	main(void)
// {
// 	ft_split(NULL, '-');
// 	return (0);
// }
