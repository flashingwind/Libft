/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muiida <muiida@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:06:58 by muiida            #+#    #+#             */
/*   Updated: 2024/11/21 15:14:34 by muiida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (size != 0 && SIZE_MAX / size < nmemb)
		return (NULL);
	p = (unsigned char *)malloc(nmemb * size * sizeof(unsigned char));
	if (p == NULL)
		return (NULL);
	ft_bzero(p, size * nmemb);
	return ((void *)p);
}
