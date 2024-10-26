/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muiida <muiida@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:29:37 by miida             #+#    #+#             */
/*   Updated: 2024/10/26 00:53:51 by muiida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
// #include <limits.h>
// #include <stddef.h>
// #include <stdio.h>
// #include <unistd.h>

static int	ft_isspace(const char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	else
		return (0);
}

static int	sign_to_int(const char sign)
{
	if (sign == '-')
		return (-1);
	else
		return (1);
}

int	ft_atoi(const char *s)
{
	long long	num;
	int			sign;

	while (ft_isspace(*s))
		s++;
	sign = 1;
	while (*s == '-' || *s == '+')
	{
		sign *= sign_to_int(*s);
		s++;
	}
	num = 0;
	while (ft_isdigit(*s))
	{
		num *= 10;
		num += *s - '0';
		s++;
	}
	num *= sign;
	return (num);
}

static unsigned char	*get_null_str(void)
{
	unsigned char	*dst;

	dst = malloc(sizeof(char));
	*dst = '\0';
	return (dst);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;

	if (nmemb * size == 0)
		p = get_null_str();
	p = malloc(size * sizeof(unsigned char));
	return ((void *)p);
}

/*MAIN

#include <stdlib.h>
#include <string.h>

int	main(void)
{
	printf("%d\n", ft_atoi(" -----1234ab567"));
	printf("%d\n", ft_atoi(" \t\r\n---+-++2147483647abc"));
	printf("%d\n", ft_atoi(" \t\r\n---+--++2147483648abc"));
}
//*/
