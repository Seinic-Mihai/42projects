/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:50:28 by mseinic           #+#    #+#             */
/*   Updated: 2015/11/24 12:48:26 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	char		*d;
	const char	*s;

	d = s1;
	s = s2;
	while (*d)
		d++;
	while (n-- && *s)
		*d++ = *s++;
	*d = '\0';
	return (s1);
}
