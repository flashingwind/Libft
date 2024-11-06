/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muiida <muiida@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:07:53 by muiida            #+#    #+#             */
/*   Updated: 2024/11/05 17:27:30 by muiida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s != NULL && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_memchr(const void *b, int c, size_t len)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *)b;
	while (i < len && p[i] != (unsigned char)c)
		i++;
	if (i == len)
		return (NULL);
	else
		return (&p[i]);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	while (i < n && p1[i] == p2[i])
		i++;
	if (i == n)
		return (0);
	else
		return (p1[i] - p2[i]);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;
	size_t	i;

	if (dst == NULL || src == NULL)
		return (NULL);
	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (s < d)
	{
		while (0 < len--)
			d[len] = s[len];
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

// #include <stdbool.h>
// #include <unistd.h>

// // #include <unistd.h>

// // #include <string.h>

// static void	check(bool b)
// {
// 	if (b)
// 		write(1, "OK ", 3);
// 	else
// 		write(1, "NG ", 3);
// }

// #include <stdio.h>

// int	main(void)
// {
// 	char s[] = {0, 1, 2, 3, 4, 5};
// 	printf("ft_memchr(s, 0, 0): NULL->%zx\n", (size_t)ft_memchr(s, 0, 0));
// 	printf("ft_memchr(s, 0, 1): %zx->%zx\n", (size_t)s, (size_t)ft_memchr(s, 0,
// 			1));
// 	printf("ft_memchr(s, 2, 3): %zx->%zx\n", (size_t)s + 2, (size_t)ft_memchr(s,
// 			2, 3));
// 	printf("ft_memchr(s, 6, 6): NULL->%zx\n", (size_t)ft_memchr(s, 6, 6));
// 	printf("ft_memchr(s, 2 + 256, 3): %zx->%zx\n", (size_t)s + 2,
// 		(size_t)ft_memchr(s, 2 + 256, 3));
// 	return (0);
// }