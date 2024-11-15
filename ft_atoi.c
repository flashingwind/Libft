/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muiida <muiida@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:29:37 by miida             #+#    #+#             */
/*   Updated: 2024/11/15 19:15:22 by muiida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_isspace(const char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	else
		return (0);
}

static long	sign_to_int(const char sign)
{
	if (sign == '-')
		return (-1);
	else
		return (1);
}

int	ft_atoi(const char *s)
{
	long	num;
	long	sign;
	size_t	i;

	i = 0;
	while (ft_isspace(s[i]))
		i++;
	sign = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		sign *= sign_to_int(s[i]);
		i++;
	}
	num = 0;
	while (ft_isdigit(s[i]))
	{
		num = num * 10 + ((long)s[i] - (long)'0');
		if (sign == 1 && num < 0)
			return ((int)LONG_MAX);
		else if (sign == -1 && num < 0)
			return ((int)LONG_MIN);
		i++;
	}
	num *= sign;
	return (num);
}

// #include <stdio.h>
// #include <stdlib.h>
// int	main(int argc, char **argv)
// {
// 	// char	s[] = "-2";
// 	printf("ft: 2147483647->%d\n", ft_atoi("2147483647"));
// 	printf("2147483647->%d\n", atoi("2147483647"));
// 	printf("ft: 2147483648->%d\n", ft_atoi("2147483648"));
// 	printf("2147483648->%d\n", atoi("2147483648"));
// 	printf("ft: -2147483648->%d\n", ft_atoi("-2147483648"));
// 	printf("-2147483648->%d\n", atoi("-2147483648"));
// 	printf("ft: -2147483649->%d\n", ft_atoi("-2147483649"));
// 	printf("-2147483649->%d\n", atoi("-2147483649"));
// 	printf("ft: 9223372036854775806->%d\n", ft_atoi("9223372036854775806"));
// 	printf("9223372036854775806->%d\n", atoi("9223372036854775806"));
// 	printf("ft: 9223372036854775807->%d\n", ft_atoi("9223372036854775807"));
// 	printf("9223372036854775807->%d\n", atoi("9223372036854775807"));
// 	printf("ft: 9223372036854775808->%d\n", ft_atoi("9223372036854775808"));
// 	printf("9223372036854775808->%d\n", atoi("9223372036854775808"));
// 	printf("ft: -9223372036854775807->%d\n", ft_atoi("-9223372036854775807"));
// 	printf("-9223372036854775807->%d\n", atoi("-9223372036854775807"));
// 	printf("ft: -9223372036854775808->%d\n", ft_atoi("-9223372036854775808"));
// 	printf("-9223372036854775808->%d\n", atoi("-9223372036854775808"));
// 	printf("ft: -9223372036854775809->%d\n", ft_atoi("-9223372036854775809"));
// 	printf("-9223372036854775809->%d\n", atoi("-9223372036854775809"));
// 	return (0);
// }
