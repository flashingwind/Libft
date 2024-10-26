/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_bsd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muiida <muiida@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:14:55 by muiida            #+#    #+#             */
/*   Updated: 2024/10/26 01:22:13 by muiida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	skip;
	unsigned int	i;

	skip = ft_strlen(dst);
	if (skip < size)
		return (size + ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && (skip + i) < (size - 1))
	{
		dst[skip + i] = src[i];
		i++;
	}
	dst[skip + i] = '\0';
	while (src[i] != '\0')
		i++;
	return (skip + i);
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
	char	*p_big;

	j = 0;
	p_big = (char *)big;
	while (*p_big != '\0' && j < len)
	{
		i = 0;
		while (p_big[i] == little[i] && p_big[i] != '\0')
		{
			if (p_big[i] == '\0' && little[i] != '\0')
				return (NULL);
			i++;
		}
		if (little[i] == '\0')
			return (p_big);
		p_big++;
		j++;
	}
	return (p_big);
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
