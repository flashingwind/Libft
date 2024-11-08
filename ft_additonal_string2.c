/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additonal_string2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muiida <flashingwind@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:13:11 by muiida            #+#    #+#             */
/*   Updated: 2024/11/09 00:14:37 by muiida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*get_null_str(void)
{
	char	*dst;

	dst = (char *)malloc(sizeof(char));
	if (dst == NULL)
		return (dst);
	*dst = '\0';
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;
	size_t	s_len;
	size_t	d_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start)
		return (get_null_str());
	if (s_len - start < len)
		len = s_len - start;
	ss = (char *)malloc(sizeof(char) * (len + 1));
	if (ss == NULL)
		return (NULL);
	d_len = ft_strlcpy(ss, s + start, len + 1);
	if (d_len != len + 1)
	{
		free(ss);
		return (NULL);
	}
	return (ss);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, start, end - start));
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
	dst_head += ft_strlcpy(dst_head, s1, len + 1);
	dst_head += ft_strlcpy(dst_head, s2, len + 1);
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
