/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_bsd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muiida <muiida@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:14:55 by muiida            #+#    #+#             */
/*   Updated: 2024/10/29 03:05:12 by muiida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	dst_len;
	unsigned int	i;

	dst_len = ft_strlen(dst);
	if (dst_len < size)
		return (dst_len + ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && (dst_len + i) < (size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	while (src[i] != '\0')
		i++;
	return (dst_len + i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
	{
		i = 0;
		while (src[i] != '\0')
			i++;
		return (i);
	}
	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little == NULL || little[0] == '\0' || big == little)
		return ((char *)big);
	j = 0;
	while (big[j] != '\0' && j < len)
	{
		i = 0;
		while (big[j + i] != '\0' && little[i] != '\0' && j + i < len)
		{
			if (big[j + i] != little[i])
				break ;
			i++;
		}
		if (little[i] == '\0')
			return ((char *)(big + j));
		j++;
	}
	return (NULL);
}

/* Original */
// size_t	strlcpy(char *dst, const char *src, size_t dsize)
// {
// 	const char	*osrc = src;
// 	size_t		nleft;

// 	nleft = dsize;
// 	if (nleft != 0)
// 	{
// 		while (--nleft != 0)
// 		{
// 			if ((*dst++ = *src++) == '\0')
// 				break ;
// 		}
// 	}
// 	if (nleft == 0)
// 	{
// 		if (dsize != 0)
// 			*dst = '\0';
// 		while (*src++)
// 			;
// 	}
// 	return (src - osrc - 1);
// }

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	unsigned long	len;
// 	char			src[] = "abcdefg\0hi";
// 	char			dst[10];
// 	char			s1[] = "Foo Bar Baz";
// 	char			s2[] = "";

// 	len = strlcpy(dst, src, sizeof(dst));
// 	if (len != strlen(dst))
// 	{
// 		printf("コピーしっぱい");
// 	}
// 	printf("%s\n", ft_strnstr("hel", "hello", 10));
// 	printf("%s\n\n", ft_strnstr("hel", "hello", 10));
// 	printf("%s\n", ft_strnstr("hello world", "ello", 10));
// 	printf("%s\n\n", ft_strnstr("hello world", "ello", 10));
// 	printf("%s\n", ft_strnstr("hello world", " ", 10));
// 	printf("%s\n\n", ft_strnstr("hello world", " ", 10));
// 	printf("%s\n", ft_strnstr("hello world", "w", 10));
// 	printf("%s\n\n", ft_strnstr("hello world", "w", 10));
// 	printf("%s\n", ft_strnstr("hello world", "ld", 10));
// 	printf("%s\n\n", ft_strnstr("hello world", "ld", 10));
// 	printf("%s\n", ft_strnstr("hello world", "d", 10));
// 	printf("%s\n\n", ft_strnstr("hello world", "d", 10));
// 	printf("%s\n", ft_strnstr("hello world", "", 10));
// 	printf("%s\n\n", ft_strnstr("hello world", "", 10));
// 	printf("%s\n", ft_strnstr("", "hello", 10));
// 	printf("%s\n\n", ft_strnstr("", "hello", 10));
// 	printf("%s\n", ft_strnstr(s1, s2, 12));
// 	printf("%s\n\n", ft_strnstr(s1, s2, 5));
// }
