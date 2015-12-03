/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:17:07 by mseinic           #+#    #+#             */
/*   Updated: 2015/12/03 16:23:45 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_cpy(char *dst, const char *src, size_t i, size_t n)
{
	unsigned char k;

	k = 0;
	while (k < n)
	{
		dst[k] = src[i];
		k++;
		i++;
	}
	dst[n] = '\0';
	return (dst);
}

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if ((str = (char *)ft_memalloc((sizeof(char)) * len + 1)) != NULL)
	{
		str = ft_cpy(str, s, start, len);
		return (str);
	}
	return (str);
}
