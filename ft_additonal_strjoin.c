/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additonal_strjoin.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muiida <muiida@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:13:11 by muiida            #+#    #+#             */
/*   Updated: 2024/10/26 20:40:07 by muiida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_strcpy_ret_size(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

static char	*get_null_str(void)
{
	char	*dst;

	dst = (char *)malloc(sizeof(char));
	*dst = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	char	*dst_head;
	size_t	len;

	len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	if (len == 0)
		return (get_null_str());
	dst = (char *)malloc(len * sizeof(char));
	if (dst == NULL)
		return (NULL);
	dst_head = dst;
	dst_head += ft_strcpy_ret_size(dst_head, s1);
	dst_head += ft_strcpy_ret_size(dst_head, s2);
	*dst_head = '\0';
	return (dst);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*strs[3] = {"aaa", "bbb", "0123456789012345678901234567890!"};
// 	char	*dst;

// 	dst = ft_strjoin(3, strs, "*-");
// 	printf("%s$\n", dst);
// }
