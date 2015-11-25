/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:46:11 by mseinic           #+#    #+#             */
/*   Updated: 2015/11/25 11:36:30 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *restrict dst, const char *restrict src, size_t n)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	while (*s && n-- > 0)
		*d++ = *s++;
	n++;
	while (n-- > 0)
		*d++ = '\0';
	return (dst);
}
