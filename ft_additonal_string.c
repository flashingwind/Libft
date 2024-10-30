/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additonal_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muiida <muiida@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:38:37 by muiida            #+#    #+#             */
/*   Updated: 2024/10/31 00:21:10 by muiida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_sect(char const *s, char sep)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
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

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	i;
	size_t	len;

	if (s == NULL)
		return (NULL);
	i = 0;
	strs = (char **)malloc(sizeof(char *) * (count_sect(s, c) + 1));
	if (strs == NULL)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				s++;
			strs[i++] = ft_substr(s - len, 0, len);
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
