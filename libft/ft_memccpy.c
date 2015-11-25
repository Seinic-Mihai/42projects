/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:11:36 by mseinic           #+#    #+#             */
/*   Updated: 2015/11/25 12:56:49 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict d, const void *restrict s, int c, size_t n)
{
	unsigned char			*ptr1;
	const unsigned char		*ptr2;
	unsigned char			ch;

	ptr1 = d;
	ptr2 = s;
	ch = c;
	while (n--)
	{
		if ((*ptr1++ = *ptr2++) == ch)
			return (ptr1);
	}
	return (0);
}
