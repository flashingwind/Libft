/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muiida <muiida@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:07:53 by muiida            #+#    #+#             */
/*   Updated: 2024/11/14 17:55:39 by muiida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*ss;
	char	*p;

	p = NULL;
	ss = (char *)s;
	while (*ss != '\0')
	{
		if (*ss == (char)c)
			p = ss;
		ss++;
	}
	if (*ss == (char)c)
		p = ss;
	return (p);
}
