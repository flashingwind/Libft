/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muiida <muiida@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:07:53 by muiida            #+#    #+#             */
/*   Updated: 2024/11/14 17:01:28 by muiida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
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
// 	// 	printf("ft_strncmp: %d\n", ft_strncmp(s1, s2, 5));
// 	// 	printf("strncmp: %d\n", strncmp(s1, s2, 5));

// 	write(1, "ft_strncmp\t: ", 13);

// 	check(ft_strncmp("t", "", 0) == 0);
// 	check(ft_strncmp("1234", "1235", 3) == 0);
// 	check(ft_strncmp("1234", "1235", 4) < 0);
// 	check(ft_strncmp("1234", "1235", -1) < 0);
// 	check(ft_strncmp("", "", 42) == 0);
// 	check(ft_strncmp("Tripouille", "Tripouille", 42) == 0);
// 	check(ft_strncmp("Tripouille", "tripouille", 42) < 0);
// 	check(ft_strncmp("Tripouille", "TriPouille", 42) > 0);
// 	check(ft_strncmp("Tripouille", "TripouillE", 42) > 0);
// 	check(ft_strncmp("Tripouille", "TripouilleX", 42) < 0);
// 	check(ft_strncmp("Tripouille", "Tripouill", 42) > 0);
// 	check(ft_strncmp("", "1", 0) == 0);
// 	check(ft_strncmp("1", "", 0) == 0);
// 	check(ft_strncmp("", "1", 1) < 0);
// 	check(ft_strncmp("1", "", 1) > 0);
// 	check(ft_strncmp("", "", 1) == 0);
// 	write(1, "\n", 1);
// 	return (0);
// }