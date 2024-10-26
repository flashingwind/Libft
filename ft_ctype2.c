/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muiida <muiida@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:04:05 by muiida            #+#    #+#             */
/*   Updated: 2024/10/26 01:04:24 by muiida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

int	ft_isprint(int c)
{
	return (' ' <= c && c <= '~');
}

int	ft_isascii(int c)
{
	return (0x00 <= c && c <= 0x7F);
}

// int	main(void)
// {
// 	char c = 'a';
// 	printf("%d", ft_isalpha(c));
// 	return (0);
// }
