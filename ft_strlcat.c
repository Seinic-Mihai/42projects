/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:56:48 by mseinic           #+#    #+#             */
/*   Updated: 2015/11/25 13:01:34 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	char		*p1;
	const char	*p2;
	size_t		i;
	size_t		k;

	i = size;
	p1 = dst;
	p2 = src;
	while (i-- && *p1)
		p1++;
	k = p1 - dst;
	i = size - k;
	if (i == 0)
		return (k + ft_strlen(p2));
	while (*p2)
	{
		if (i != 1)
		{
			*p1++ = *p2;
			i--;
		}
		p2++;
	}
	*p1 = '\0';
	return (k + (p2 - src));
}
