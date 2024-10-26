/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additonal_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muiida <muiida@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:38:37 by muiida            #+#    #+#             */
/*   Updated: 2024/10/26 20:36:23 by muiida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*get_null_str(void)
{
	char	*dst;

	dst = (char *)malloc(sizeof(char));
	*dst = '\0';
	return (dst);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (get_null_str());
	if (len > s_len - start)
		len = s_len - start;
	ss = (char *)malloc(sizeof(char) * (len + 1));
	if (ss == NULL)
		return (NULL);
	ft_strlcpy(ss, s + start, len + 1);
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

static size_t	count_sect(char const *s, char sep)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
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
size_t	num_of_digits(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		len++;
	else if (n == 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	num;

	num = n;
	len = num_of_digits(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		str[len] = '0' + (num % 10);
		num /= 10;
		len--;
	}
	return (str);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	*strs[3] = {"aaa", "bbb", "0123456789012345678901234567890!"};
// 	char	*dst;

// 	dst = ft_strjoin(3, strs, "*-");
// 	printf("%s$\n", dst);
// }
