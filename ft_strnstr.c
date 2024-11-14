/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muiida <muiida@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:14:55 by muiida            #+#    #+#             */
/*   Updated: 2024/11/14 17:10:53 by muiida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (len == 0 && big == NULL)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	j = 0;
	while (big[j] != '\0' && j < len)
	{
		i = 0;
		while (big[j + i] != '\0' && little[i] != '\0' && j + i < len)
		{
			if (big[j + i] != little[i])
				break ;
			i++;
		}
		if (little[i] == '\0')
			return ((char *)(big + j));
		j++;
	}
	return (NULL);
}
