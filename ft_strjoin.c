/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muiida <muiida@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:13:11 by muiida            #+#    #+#             */
/*   Updated: 2024/11/15 20:26:30 by muiida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	char	*p;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	dst = (char *)malloc((len + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	p = dst;
	p += ft_strlcpy(p, s1, len + 1);
	p += ft_strlcpy(p, s2, len + 1);
	*p = '\0';
	return (dst);
}
