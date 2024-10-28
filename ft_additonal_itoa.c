/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additonal_itoa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muiida <muiida@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 01:07:43 by muiida            #+#    #+#             */
/*   Updated: 2024/10/29 01:13:42 by muiida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	num_of_digits(int n)
{
	size_t		len;
	long long	n2;

	len = 0;
	n2 = n;
	if (n2 == 0)
	{
		len++;
		return (len);
	}
	if (n2 < 0)
	{
		n2 = -n2;
		len++;
	}
	while (0 < n2)
	{
		n2 /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	long long	num;

	num = n;
	len = num_of_digits(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
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
