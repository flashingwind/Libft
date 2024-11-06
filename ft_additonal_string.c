/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additonal_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muiida <muiida@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:38:37 by muiida            #+#    #+#             */
/*   Updated: 2024/11/06 16:04:58 by muiida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_sect(char const *s, char sep)
{
	size_t	count;

	count = 0;
	while (s != NULL && *s != '\0')
	{
		if (*s == sep)
		{
			s++;
		}
		else
		{
			count++;
			while (*s != '\0' && *s != sep)
				s++;
		}
	}
	return (count);
}

static char	**free_all(char **strs, size_t i)
{
	while (i > 0)
		free(strs[--i]);
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	i;
	size_t	len;

	i = 0;
	strs = (char **)malloc(sizeof(char *) * (count_sect(s, c) + 1));
	if (s == NULL || strs == NULL)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
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
// 	char	*strs[3] = {"aaa", "bbb", "0123456789012345678901234567890!"};
// 	char	*dst;

// 	dst = ft_strjoin(3, strs, "*-");
// 	printf("%s$\n", dst);
// }
