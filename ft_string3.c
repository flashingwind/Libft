/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muiida <muiida@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:07:53 by muiida            #+#    #+#             */
/*   Updated: 2024/10/28 00:08:14 by muiida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s);
	s2 = (char *)malloc((len + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy(s2, s, len + 1);
	return (s2);
}

// #include <stdbool.h>
// #include <unistd.h>
// #include <stdio.h>
// #include <string.h>

// static void	check(bool b)
// {
// 	if (b)
// 		write(1, "OK ", 3);
// 	else
// 		write(1, "NG ", 3);
// }

// int	main(void)
// {
// 	// 	char	*s1;
// 	// 	char	*s2;
// 	// 	char	*s3;
// 	// 	char	*s4;

// 	// 	s1 = "abcde";
// 	// 	s2 = "abcde";
// 	// 	s3 = "abcde";
// 	// 	s4 = "abcde";
// 	// 	printf("ft_strchr: %s\n", ft_strchr(s1, 'c'));
// 	// 	printf("strchr: %s\n", strchr(s2, 'c'));
// 	// 	printf("ft_strrchr: %s\n", ft_strrchr(s3, 'c'));
// 	// 	printf("strrchr: %s\n", strrchr(s4, 'c'));


// 	write(1, "\n", 1);
// 	return (0);
// }